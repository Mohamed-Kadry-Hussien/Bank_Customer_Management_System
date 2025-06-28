#include <stdio.h>
#include "functions.h"

Customer customers[MAX_CUSTOMERS];

void create_customer(Customer *customers, int *customer_count){
    if(*customer_count >= MAX_CUSTOMERS) {
        printf("Customer limit reached. Cannot add more customers.\n");
        return;
    }
    Customer *new_customer = &customers[*customer_count];
    new_customer->id = rand() % 10000;
    printf("Enter your name: ");
    scanf("%s", new_customer->name);
    printf("Enter your phone number: ");
    scanf("%s", new_customer->phone);
    
    do{
        printf("Enter your balance: ");
        scanf("%lf", &new_customer->balance);
    } 
    while(new_customer->balance < 0);
    (*customer_count)++;
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
    printf("Enter new name: ");
    scanf("%s", customers[index].name);
    printf("Enter new phone number: ");
    scanf("%s", customers[index].phone);
    printf("Customer updated successfully.\n");
}