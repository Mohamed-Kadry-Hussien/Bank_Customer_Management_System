// main.c
#include "functions.c"
#include <stdlib.h>
#include <stdio.h>

void display_menu()
{
    printf("\n********************************************\n");
    printf("*                                          *\n");
    printf("*          Bank Management System          *\n");
    printf("*                                          *\n");
    printf("********************************************\n");
    printf("*                                          *\n");
    printf("*          1. Add New Customer             *\n");
    printf("*          2. Edit Customer                *\n");
    printf("*          3. View Customer Details        *\n");
    printf("*          4. Delete Customer              *\n");
    printf("*          5. Deposit                      *\n");
    printf("*          6. Withdraw                     *\n");
    printf("*          7. Transfer Money               *\n");
    printf("*          8. Exit                         *\n");
    printf("*                                          *\n");
    printf("********************************************ٍ\n");
}

int main()
{
    int choice;
    // load_data();

    do
    {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            // create_customer();
            printf("You choose option 1");
            break;
        case 2:
            // edit_customer(customers, &customer_count);
            printf("You choose option 2");
            break;
        case 3:
            // print_customer_data(customers, &customer_count);
            printf("You choose option 3");
            break;
        case 4:
            // delete_customer(customers, &customer_count);
            printf("You choose option 4");
            break;
        case 5:
            // deposit();
            printf("You choose option 5");
            break;
        case 6:
            // withdraw();
            printf("You choose option 6");
            break;
        case 7:
            // int from_id, to_id;
            // double amount;
            // printf("Enter amount to transfer: ");
            // scanf("%lf", &amount);
            // printf("Enter sender customer ID: ");
            // scanf("%d", &from_id);
            // printf("Enter receiver customer ID: ");
            // scanf("%d", &to_id);
            // transfer_money(customers, from_id, to_id, amount, customer_count);
            printf("You choose option 7");
            break;
        case 8:
            printf("\nExiting program. Goodbye!\n");
            break;
        default:
            printf("\nInvalid choice! Please try again.\n");
        }

        if (choice != 8)
        {
            printf("\nPress Enter to continue...");
            while (getchar() != '\n')
                ;
            getchar();
        }

    } while (choice != 8);

    return 0;
}