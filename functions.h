// functions.h
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>

#define MAX_CUSTOMERS 100

typedef struct {
    int id;
    char name[100];
    char phone[20];
    double balance;
} Customer;

extern Customer customers[MAX_CUSTOMERS];
extern int customer_count;

int load_data(Customer *customers, char *file_name);
void save_data(Customer *customers, int *customer_count, char *file_name);
void create_customer(Customer *customers, int *customer_count);
void edit_customer(Customer *customers, int *customer_count);
void print_customer_data();
void delete_customer();
void deposit();
void withdraw();
void transfer_money();
int find_customer(Customer *customers, int customer_count, int id);

#endif
