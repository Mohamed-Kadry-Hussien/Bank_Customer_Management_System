#include <stdio.h>
#include <string.h>
#include "functions.h"

Customer customers[MAX_CUSTOMERS];
int customer_count = 0;

void print_customer_data(Customer *customers, int *customer_count) {
    if (*customer_count == 0) {
        printf("No customers to display.\n");
        return;
    }

    int id_to_find;
    printf("Enter Customer ID to display: ");
    if (scanf("%d", &id_to_find) != 1) {
        printf("Invalid input.\n");
        while (getchar() != '\n');
        return;
    }

    int found = 0;
    for (int i = 0; i < *customer_count; i++) {
        if (customers[i].id == id_to_find) {
            printf("Customer Data:\n");
            printf("ID: %d\n", customers[i].id);
            printf("Name: %s\n", customers[i].name);
            printf("Phone: %s\n", customers[i].phone);
            printf("Balance: %.2lf\n", customers[i].balance);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Customer not found.\n");
    }
}
void delete_customer(Customer *customers, int *customer_count) {
    if (*customer_count == 0) {
        printf("No customers to delete.\n");
        return;
    }

    int id_to_delete;
    printf("Enter Customer ID: ");
    scanf("%d", &id_to_delete);

    int found = 0;
    for (int i = 0; i < *customer_count; i++) {
        if (customers[i].id == id_to_delete) {
            found = 1;
            for (int j = i; j < *customer_count - 1; j++) {
                customers[j] = customers[j + 1];
            }
            (*customer_count)--;
            printf("Customer deleted successfully.\n");
            break;
        }
    }

    if (!found) {
        printf("Customer not found.\n");
    }
}