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

    int index = find_customer(customers, *customer_count, id_to_find);
    if (index != -1) {
        printf("Customer Data:\n");
        printf("ID: %d\n", customers[index].id);
        printf("Name: %s\n", customers[index].name);
        printf("Phone: %s\n", customers[index].phone);
        printf("Balance: %.2lf\n", customers[index].balance);
    } else {
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
    if (scanf("%d", &id_to_delete) != 1) {
        printf("Invalid input.\n");
        while (getchar() != '\n');
        return;
    }

    int index = find_customer(customers, *customer_count, id_to_delete);
    if (index != -1) {
        for (int i = index; i < *customer_count - 1; i++) {
            customers[i] = customers[i + 1];
        }
        (*customer_count)--;
        printf("Customer deleted successfully.\n");
    } else {
        printf("Customer not found.\n");
    }
}