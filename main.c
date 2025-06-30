// main.c
#include "functions.h"
#include <stdlib.h> 

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

void display_menu() {
    system(CLEAR); 
    printf("\n\n");
    printf("***************************************\n");
    printf("*      Bank Management System        *\n");
    printf("***************************************\n");
    printf("*                                    *\n");
    printf("*  1. Add New Customer               *\n");
    printf("*  2. Edit Customer                  *\n");
    printf("*  3. View Customer Details          *\n");
    printf("*  4. Delete Customer                *\n");
    printf("*  5. Deposit                        *\n");
    printf("*  6. Withdraw                       *\n");
    printf("*  7. Transfer Money                 *\n");
    printf("*  8. Exit                           *\n");
    printf("*                                    *\n");
    printf("***************************************\n");
    printf("\nEnter your choice (1-8): ");
}

int main() {
    int choice;
    load_data();
    
    do {
        display_menu();
        scanf("%d", &choice);
        
        switch (choice) {
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
            case 7: {
                int from_id, to_id;
                double amount;
                printf("Enter sender ID: ");
                scanf("%d", &from_id);
                printf("Enter recipient ID: ");
                scanf("%d", &to_id);
                printf("Enter amount to transfer: ");
                scanf("%lf", &amount);
                transfer_money(customers, from_id, to_id, amount, customer_count);
                break;
            }
            case 8: 
                printf("\nExiting program. Goodbye!\n"); 
                break;
            default: 
                printf("\nInvalid choice! Please try again.\n");
        }
        
        if (choice != 8) {
            printf("\nPress Enter to continue...");
            while (getchar() != '\n'); 
            getchar(); 
        }
            save_data(customers, &customer_count, "customers.txt");
        
    } while (choice != 8);
    
    return 0;
}