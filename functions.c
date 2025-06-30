// functions.c
#include "functions.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

Customer customers[MAX_CUSTOMERS];
int customer_count = 0;

bool is_valid_name(const char *name)
{
    for (int i = 0; name[i] != '\0'; i++)
    {
        if (!isalpha(name[i]) && name[i] != ' ')
        {
            return false;
        }
    }
    return true;
}

bool is_valid_phone(const char *phone)
{
    if (strlen(phone) != PHONE_LENGTH)
    {
        return false;
    }
    for (int i = 0; phone[i] != '\0'; i++)
    {
        if (!isdigit(phone[i]))
        {
            return false;
        }
    }
    return true;
}
void load_data()
{
    FILE *file = fopen("customers.txt", "r");
    if (file == NULL)
        return;
    customer_count = 0;
    while (fscanf(file, "%d,%99[^,],%19[^,],%lf\n",
                  &customers[customer_count].id,
                  customers[customer_count].name,
                  customers[customer_count].phone,
                  &customers[customer_count].balance) != EOF)
    {
        customer_count++;
    }
    fclose(file);
}


void save_data(Customer *customers, int *customer_count, char *file_name)
{
    FILE *file = fopen(file_name, "w");
    if (!file)
    {
        printf("Error while opening the file!!!");
        return;
    }
    for (int i = 0; i < *customer_count; i++)
    {
    fprintf(file, "%d,%s,%s,%.2f\n", customers[i].id, customers[i].name, customers[i].phone, customers[i].balance);
    }

    fclose(file);
}

int find_customer(Customer *customers, int customer_count, int id)
{
    if (customer_count <= 0 || customers == NULL)
    {
        printf("No customers available.\n");
        return -1;
    }
    for (int i = 0; i < customer_count; i++)
    {
        if (customers[i].id == id)
            return i;
    }
    return -1;
}

void create_customer(Customer *customers, int *customer_count)
{
    if (*customer_count >= MAX_CUSTOMERS)
    {
        printf("Customer limit reached. Cannot add more customers.\n");
        return;
    }
    Customer *new_customer = &customers[*customer_count];
    int is_unique;
    do
    {
        is_unique = 0;
        new_customer->id = rand() % 10000;

        for (int i = 0; i < *customer_count; i++)
        {
            if (customers[i].id == new_customer->id)
            {
                is_unique = 1;
                break;
            }
        }
    } while (is_unique);
 
    do
    {
        
        printf("Enter your name : ");
        scanf(" %[^\n]", new_customer->name);
        if(!is_valid_name(new_customer->name))
        {
            printf("Invalid name.\n");
        }
        
    }while(!is_valid_name(new_customer->name));
    
    do
    {
        
        printf("Enter your phone number: ");
        scanf("%s", new_customer->phone);
        if(!is_valid_phone(new_customer->phone))
        {
            printf("Invalid phone.\n");
        }

    }while(!is_valid_phone(new_customer->phone));
    do
    {
        printf("Enter your balance: ");
        scanf("%lf", &new_customer->balance);
        if (new_customer->balance < 0)
        {
            printf("Balance cannot be negative. Try again.\n");
        }
    } while (new_customer->balance < 0);
    (*customer_count)++;
    printf("Customer created successfully. ID: %d\n", new_customer->id);
}

void edit_customer(Customer *customers, int *customer_count)
{
    int id;
    printf("Enter customer ID to edit: ");
    scanf("%d", &id);
    int index = find_customer(customers, *customer_count, id);
    if (index == -1)
    {
        printf("Customer is not found.\n");
        return;
    }
     do
    {
        
        printf("Enter your new name : ");
        scanf(" %[^\n]", customers[index].name);
        if(!is_valid_name(customers[index].name))
        {
            printf("Invalid name.\n");
        }
        
    }while(!is_valid_name(customers[index].name));
    
    do
    {
        
        printf("Enter new phone number: ");
        scanf("%s", customers[index].phone);
        if(!is_valid_phone(customers[index].phone))
        {
            printf("Invalid phone.\n");
        }

    }while(!is_valid_phone(customers[index].phone));
    printf("Customer updated successfully.\n");
}

void print_customer_data(Customer *customers, int *customer_count)
{
    if (*customer_count == 0)
    {
        printf("No customers to display.\n");
        return;
    }

    int id_to_find;
    printf("Enter Customer ID to display: ");
    if (scanf("%d", &id_to_find) != 1)
    {
        printf("Invalid input.\n");
        while (getchar() != '\n')
            ;
        return;
    }

    int index = find_customer(customers, *customer_count, id_to_find);
    if (index != -1)
    {
        printf("Customer Data:\n");
        printf("ID: %d\n", customers[index].id);
        printf("Name: %s\n", customers[index].name);
        printf("Phone: %s\n", customers[index].phone);
        printf("Balance: %.2lf\n", customers[index].balance);
    }
    else
    {
        printf("Customer not found.\n");
    }
}
void delete_customer(Customer *customers, int *customer_count)
{
    if (*customer_count == 0)
    {
        printf("No customers to delete.\n");
        return;
    }

    int id_to_delete;
    printf("Enter Customer ID: ");
    if (scanf("%d", &id_to_delete) != 1)
    {
        printf("Invalid input.\n");
        while (getchar() != '\n')
            ;
        return;
    }

    int index = find_customer(customers, *customer_count, id_to_delete);
    if (index != -1)
    {
        for (int i = index; i < *customer_count - 1; i++)
        {
            customers[i] = customers[i + 1];
        }
        (*customer_count)--;
        printf("Customer deleted successfully.\n");
    }
    else
    {
        printf("Customer not found.\n");
    }
}

void deposit()
{
    int id;
    double amount;
    printf("Enter customer ID for deposit: ");
    scanf("%d", &id);
    int idx = find_customer(customers, customer_count, id);
    if (idx == -1)
    {
        printf("Customer not found.\n");
        return;
    }
    printf("Enter amount to deposit: ");
    scanf("%lf", &amount);
    if (amount < 0)
    {
        printf("Amount must be positive.\n");
        return;
    }
    customers[idx].balance += amount;
    save_data(customers, &customer_count, "customers.txt");
    printf("Deposit completed successfully.\n");
}

void withdraw()
{
    int id;
    double amount;
    printf("Enter customer ID for withdrawal: ");
    scanf("%d", &id);
    int idx = find_customer(customers, customer_count, id);
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
    if (customers[idx].balance < amount)
    {
        printf("Insufficient balance.\n");
        return;
    }
    customers[idx].balance -= amount;
    save_data(customers, &customer_count, "customers.txt");
    printf("Withdrawal completed successfully.\n");
}
void transfer_money(Customer *customers, int ID1, int ID2, double amount, int customer_count)
{
    int index1 = find_customer(customers, customer_count, ID1);
    int index2 = find_customer(customers, customer_count, ID2);
    if (index1 == -1 || index2 == -1)
    {
        printf("Customer not found\n");
        return;
    }
    if (index1 == index2)
    {
        printf("Same customer!\n");
        return;
    }
    if (amount <= 0)
    {
        printf("Invalid amount\n");
        return;
    }
    if (customers[index1].balance < amount)
    {
        printf("Insufficient balance\n");
        return;
    }
    customers[index1].balance -= amount;
    customers[index2].balance += amount;
    printf("Transfer of %.2f from customer %d to customer %d completed successfully.\n", amount, ID1, ID2);
}