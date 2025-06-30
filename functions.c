// Used libraries and headers
#include "functions.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Global variables to store customers data
Customer customers[MAX_CUSTOMERS];
int customer_count = 0;

// Function to validate customer name
bool is_valid_name(const char *name)
{
    // Iterates the input and checks if every character is a letter or a space only
    for (int i = 0; name[i] != '\0'; i++)
    {
        if (!isalpha(name[i]) && name[i] != ' ')  // isalpha checks if the character is a letter
        {
            return false;
        }
    }
    return true;
}

// Function to validate customer phone number
bool is_valid_phone(const char *phone)
{
    if (strlen(phone) != PHONE_LENGTH) // Checks if the phone number has the correct length
    {
        return false;
    }
    // Iterates the input and checks if every character is a digit
    for (int i = 0; phone[i] != '\0'; i++)
    {
        if (!isdigit(phone[i]))  // isdigit checks if the character is a digit (Same as isalpha)
        {
            return false;
        }
    }
    return true;
}

// Function to load customer data from a file
void load_data()
{
    // Opens the file in read mode
    FILE *file = fopen("customers.txt", "r");
    // If the file cannot be opened, it returns without doing anything
    if (file == NULL)
        return;
    customer_count = 0;  // Counting the number of customers in the file
    while (fscanf(file, "%d,%99[^,],%19[^,],%lf\n",
                  &customers[customer_count].id,
                  customers[customer_count].name,
                  customers[customer_count].phone,
                  &customers[customer_count].balance) != EOF)
    {
        customer_count++;  // Increment the customer count for each successfully read customer
    }
    fclose(file);  // Closes the file after reading for safety
}

// Function to save customer data to a file
void save_data(Customer *customers, int *customer_count, char *file_name)
{
    // Opens the file in write mode, which will create the file if it doesn't exist or overwrite it if it does
    FILE *file = fopen(file_name, "w");
    // If the file cannot be opened, it prints an error message and returns
    if (!file)
    {
        printf("Error while opening the file!!!");
        return;
    }
    // Writes the customer data to the file in CSV format
    for (int i = 0; i < *customer_count; i++)
    {
        fprintf(file, "%d,%s,%s,%.2f\n", customers[i].id, customers[i].name, customers[i].phone, customers[i].balance);
    }

    fclose(file);  // Closes the file after writing for safety
}

// Function to find a customer by ID
int find_customer(Customer *customers, int customer_count, int id)
{
    // Checks if there are customers available
    if (customer_count <= 0 || customers == NULL)
    {
        printf("No customers available.\n");
        return -1;
    }
    // Iterates through the customers array to find the customer with the given ID
    for (int i = 0; i < customer_count; i++)
    {
        if (customers[i].id == id)
            return i;  // Returns the index of the customer if found
    }
    return -1;
}

// Function to create a new customer
void create_customer(Customer *customers, int *customer_count)
{
    // Checks if the customer count has reached the maximum limit
    if (*customer_count >= MAX_CUSTOMERS)
    {
        printf("Customer limit reached. Cannot add more customers.\n");
        return;
    }
    // Defining a new customer at the end of the customers array
    Customer *new_customer = &customers[*customer_count];
    int is_unique;  // Variable to check if the ID is unique
    do
    {
        is_unique = 0;
        new_customer->id = rand() % 10000;  // Generates a random ID between 0 and 9999
        // Checks if the generated ID is unique by iterating through existing customers
        for (int i = 0; i < *customer_count; i++)
        {
            if (customers[i].id == new_customer->id)
            {
                is_unique = 1;
                break;
            }
        }
    } while (is_unique);  // Repeats until a unique ID is generated

    // Checks if the name is valid
    do
    {
        printf("Enter your name : ");
        scanf(" %[^\n]", new_customer->name);
        if (!is_valid_name(new_customer->name))
        {
            printf("Invalid name.\n");
        }

    } while (!is_valid_name(new_customer->name));  // Repeats untill the name input is valid

    // Checks if the phone number is valid
    do
    {
        printf("Enter your phone number: ");
        scanf("%s", new_customer->phone);
        if (!is_valid_phone(new_customer->phone))
        {
            printf("Invalid phone.\n");
        }

    } while (!is_valid_phone(new_customer->phone));  // Repeats until the phone input is valid
    
    // Checks if the balance is non-negative
    do
    {
        printf("Enter your balance: ");
        scanf("%lf", &new_customer->balance);
        if (new_customer->balance < 0)
        {
            printf("Balance cannot be negative. Try again.\n");
        }
    } while (new_customer->balance < 0);  // Repeats until the balance input is non-negative
    (*customer_count)++;  // Increments the customer count after adding a new customer
    printf("Customer created successfully. ID: %d\n", new_customer->id);
}

// Function to edit an existing customer's data
void edit_customer(Customer *customers, int *customer_count)
{
    int id;  // Variable to store the ID of the customer to be edited
    printf("Enter customer ID to edit: ");
    scanf("%d", &id);
    int index = find_customer(customers, *customer_count, id);  // Finds the index of the customer with the given ID
    // If the customer is not found, it prints an error message and returns
    if (index == -1)
    {
        printf("Customer is not found.\n");
        return;
    }
    // If the customer is found, it prompts the user to enter new data for the customer
    do
    {

        printf("Enter your new name : ");
        scanf(" %[^\n]", customers[index].name);
        if (!is_valid_name(customers[index].name))  // Checks if the name is valid
        {
            printf("Invalid name.\n");
        }

    } while (!is_valid_name(customers[index].name));  // Repeats until the name input is valid

    // Checks if the phone number is valid
    do
    {

        printf("Enter new phone number: ");
        scanf("%s", customers[index].phone);
        if (!is_valid_phone(customers[index].phone))  // Checks if the phone number is valid
        {
            printf("Invalid phone.\n");
        }

    } while (!is_valid_phone(customers[index].phone));  // Repeats until the phone input is valid
    printf("Customer updated successfully.\n");
}

// Function to print customer data by ID
void print_customer_data(Customer *customers, int *customer_count)
{
    // Checks if there are customers available to display
    if (*customer_count == 0)
    {
        printf("No customers to display.\n");
        return;
    }

    int id_to_find;  // Variable to store the ID of the customer to be displayed
    printf("Enter Customer ID to display: ");
    if (scanf("%d", &id_to_find) != 1)  // Checks if the input is a valid integer
    {
        printf("Invalid input.\n");
        while (getchar() != '\n');  // Clear the input buffer
        return;
    }

    int index = find_customer(customers, *customer_count, id_to_find);  // Finds the index of the customer with the given ID
    if (index != -1)  // If the customer is found, it prints the customer's data
    {
        // Displaying the customer's data
        printf("Customer Data:\n");
        printf("ID: %d\n", customers[index].id);
        printf("Name: %s\n", customers[index].name);
        printf("Phone: %s\n", customers[index].phone);
        printf("Balance: %.2lf\n", customers[index].balance);
    }
    else
    {
        // If the customer is not found, it prints an error message
        printf("Customer not found.\n");
    }
}

// Function to delete a customer by ID
void delete_customer(Customer *customers, int *customer_count)
{
    // Checks if there are customers available to delete
    if (*customer_count == 0)
    {
        printf("No customers to delete.\n");
        return;
    }

    int id_to_delete;  // Variable to store the ID of the customer to be deleted
    printf("Enter Customer ID: ");
    if (scanf("%d", &id_to_delete) != 1)  // Checks if the input is a valid integer
    {
        printf("Invalid input.\n");
        while (getchar() != '\n');  // Clear the input buffer
        return;
    }

    // Finds the index of the customer with the given ID
    int index = find_customer(customers, *customer_count, id_to_delete);
    if (index != -1)
    {
        // If the customer is found, it shifts the remaining customers to fill the gap
        for (int i = index; i < *customer_count - 1; i++)
        {
            customers[i] = customers[i + 1];  // This overwrites the current customer with the next one
        }
        (*customer_count)--;  // Decrements the customer count
        printf("Customer deleted successfully.\n");
    }
    else
    {
        printf("Customer not found.\n");
    }
}

// Function to deposit money into a customer's account
void deposit()
{
    int id;  // Variable to store the ID of the customer for deposit
    double amount;  // Variable to store the amount to be deposited
    printf("Enter customer ID for deposit: ");
    scanf("%d", &id);
    int idx = find_customer(customers, customer_count, id);  // Finds the index of the customer with the given ID
    // If the customer is not found, it prints an error message and returns
    if (idx == -1)
    {
        printf("Customer not found.\n");
        return;
    }
    printf("Enter amount to deposit: ");
    scanf("%lf", &amount);
    // Checks if the amount is negative
    if (amount < 0)
    {
        printf("Amount must be positive.\n");
        return;
    }
    customers[idx].balance += amount;  // Adds the deposit amount to the customer's balance
    save_data(customers, &customer_count, "customers.txt");  // Saves the updated customer data to the file
    printf("Deposit completed successfully.\n");
}

// Function to withdraw money from a customer's account
void withdraw()
{
    int id;  // Variable to store the ID of the customer for withdrawal
    double amount;  // Variable to store the amount to be withdrawn
    printf("Enter customer ID for withdrawal: ");
    scanf("%d", &id);
    int idx = find_customer(customers, customer_count, id);  // Finds the index of the customer with the given ID
    // If the customer is not found, it prints an error message and returns
    if (idx == -1)
    {
        printf("Customer not found.\n");
        return;
    }
    printf("Enter amount to withdraw: ");
    scanf("%lf", &amount);
    if (amount < 0)
    {
        printf("Amount must be positive.\n");
        return;
    }
    // Checks if the withdrawal amount is greater than the customer's balance
    if (customers[idx].balance < amount)
    {
        printf("Insufficient balance.\n");
        return;
    }
    customers[idx].balance -= amount;  // Deducts the withdrawal amount from the customer's balance
    save_data(customers, &customer_count, "customers.txt");  // Saves the updated customer data to the file
    printf("Withdrawal completed successfully.\n");
}

// Function to transfer money between two customers
void transfer_money(Customer *customers, int customer_count)
{
    // Checks if there are at least two customers to transfer money between
    if (customer_count < 2)
    {
        printf("Not enough customers to transfer money.\n");
        return;
    }
    int from_id, to_id;  // Variables to store the IDs of the sender and recipient
    double amount;  // Variable to store the amount to be transferred
    printf("Enter sender ID: ");
    scanf("%d", &from_id);
    printf("Enter recipient ID: ");
    scanf("%d", &to_id);
    printf("Enter amount to transfer: ");
    scanf("%lf", &amount);
    int index1 = find_customer(customers, customer_count, from_id);  // Finds the index of the sender with the given ID
    int index2 = find_customer(customers, customer_count, to_id);  // Finds the index of the recipient with the given ID
    // If either the sender or recipient is not found, it prints an error message and returns
    if (index1 == -1 || index2 == -1)
    {
        printf("Customer not found\n");
        return;
    }
    // Checks if the sender and recipient are the same
    if (index1 == index2)
    {
        printf("Same customer!\n");
        return;
    }
    // Checks if the transfer amount is valid
    if (amount <= 0)
    {
        printf("Invalid amount\n");
        return;
    }
    // Checks if the sender has enough balance for the transfer
    if (customers[index1].balance < amount)
    {
        printf("Insufficient balance\n");
        return;
    }
    customers[index1].balance -= amount;  // Deducts the transfer amount from the sender's balance
    customers[index2].balance += amount;  // Adds the transfer amount to the recipient's balance
    printf("Transfer of %.2f from customer %d to customer %d completed successfully.\n", amount, from_id, to_id);
}
