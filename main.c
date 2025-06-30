// Used libraries and headers
#include "functions.h"
#include <stdlib.h>

// Function for UI
void display_menu()
{
    printf("\n\n");
    printf("***************************************\n");
    printf("*       Bank Management System        *\n");
    printf("***************************************\n");
    printf("*                                     *\n");
    printf("*       1. Add New Customer           *\n");
    printf("*       2. Edit Customer              *\n");
    printf("*       3. View Customer Details      *\n");
    printf("*       4. Delete Customer            *\n");
    printf("*       5. Deposit                    *\n");
    printf("*       6. Withdraw                   *\n");
    printf("*       7. Transfer Money             *\n");
    printf("*       8. Exit                       *\n");
    printf("*                                     *\n");
    printf("***************************************\n");
    printf("\nEnter your choice (1-8): ");
}

int main()
{
    int choice;  // Variable to store user's choice
    load_data();  // Load customer data from file at the start

    // Entering the program ;oop until the user chooses to exit
    do
    {
        display_menu();
        scanf("%d", &choice);

        // Switch case to handle user's choice
        switch (choice)
        {
        case 1:
            create_customer(customers, &customer_count);
            break;
        case 2:
            edit_customer(customers, &customer_count);
            break;
        case 3:
            print_customer_data(customers, &customer_count);
            break;
        case 4:
            delete_customer(customers, &customer_count);
            break;
        case 5:
            deposit();
            break;
        case 6:
            withdraw();
            break;
        case 7:
        {
            transfer_money(customers, customer_count);
            break;
        }
        case 8:
            printf("\nExiting program. Goodbye!\n");
            break;
        default:
            printf("\nInvalid choice! Please try again.\n");
        }

        if (choice != 8)
        {
            printf("\nPress Enter to continue...");
            while (getchar() != '\n') // Clear the input buffer
                ;
            getchar();
        }
        save_data(customers, &customer_count, "customers.txt");  // Save data after each operation

    } while (choice != 8);

    return 0;
}
