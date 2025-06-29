#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "functions.h"

Customer customers[MAX_CUSTOMERS];

void create_customer(Customer *customers, int *customer_count) {
    if (*customer_count >= MAX_CUSTOMERS) {
        printf("Customer limit reached. Cannot add more customers.\n");
        return;
    }
    Customer *new_customer = &customers[*customer_count];
    int is_unique;
    do {
        is_unique = 0;
        new_customer->id = rand() % 10000;

        for (int i = 0; i < *customer_count; i++) {
            if (customers[i].id == new_customer->id) {
                is_unique = 1;
                break;
            }
        }
    } while (is_unique);
    while (1) {
        printf("Enter your name: ");
        scanf(" %[^\n]", new_customer->name);
        int valid = 1;
        for (int i = 0; new_customer->name[i]; i++) {
            if (!isalpha(new_customer->name[i]) && new_customer->name[i] != ' ') {
                valid = 0;
                break;
            }
        }
        if (valid) break;
        else printf("Invalid name.\n");
    }
    while (1) {
        printf("Enter your phone number: ");
        scanf("%s", new_customer->phone);
        int length = strlen(new_customer->phone);
        int valid = (length == 11);
        for (int i = 0; i < length && valid; i++) {
            if (!isdigit(new_customer->phone[i])) {
                valid = 0;
                break;
            }
        }
        if (valid) break;
        else printf("Invalid phone number.\n");
    }
    do {
        printf("Enter your balance: ");
        scanf("%lf", &new_customer->balance);
        if (new_customer->balance < 0) {
            printf("Balance cannot be negative. Try again.\n");
        }
    } while (new_customer->balance < 0);
    (*customer_count)++;
    printf("Customer created successfully. ID: %d\n", new_customer->id);
}

void edit_customer(Customer *customers, int *customer_count){
    int id;
    printf("Enter customer ID to edit: ");
    scanf("%d", &id);
    int index = find_customer(customers, *customer_count, id);
    if(index == -1) {
        printf("Customer is not found.\n");
        return;
    }
    while (1) {
        printf("Enter new name: ");
        scanf(" %[^\n]", customers[index].name);

        int valid = 1;
        for (int i = 0; customers[index].name[i]; i++) {
            if (!isalpha(customers[index].name[i]) && customers[index].name[i] != ' ') {
                valid = 0;
                break;
            }
        }

        if (valid) break;
        else printf("Invalid name.\n");
    }
    while (1) {
        printf("Enter new phone number: ");
        scanf("%s", customers[index].phone);

        int len = strlen(customers[index].phone);
        int valid = (len == 11);

        for (int i = 0; i < len && valid; i++) {
            if (!isdigit(customers[index].phone[i])) {
                valid = 0;
                break;
            }
        }

        if (valid) break;
        else printf("Invalid phone number.\n");
    }
    printf("Customer updated successfully.\n");
}

void save_data(Customer *customers, int *customer_count, char *file_name){
    FILE *file = fopen(file_name, "w");
    if(!file){
        printf("Error while opening the file!!!");
        return;
    }
    for(int i = 0; i < *customer_count; i++){
        fprintf(file, "%d,%s,%s,%.2f\n", customers->id, customers->name, customers->phone, customers->balance);
    }
    fclose(file);
}