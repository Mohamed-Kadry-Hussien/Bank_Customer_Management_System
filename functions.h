// functions.h
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdbool.h>

#define MAX_CUSTOMERS 100
#define PHONE_LENGTH 11

typedef struct
{
    int id;
    char name[100];
    char phone[20];
    double balance;
} Customer;

extern Customer customers[MAX_CUSTOMERS];
extern int customer_count;

bool is_valid_name(const char *name);
bool is_valid_phone(const char *phone);
void load_data();
void save_data(Customer *customers, int *customer_count, char *file_name);
int find_customer(Customer *customers, int customer_count, int id);
void create_customer(Customer *customers, int *customer_count);
void edit_customer(Customer *customers, int *customer_count);
void print_customer_data(Customer *customers, int *customer_count);
void delete_customer(Customer *customers, int *customer_count);
void deposit();
void withdraw();
void transfer_money(Customer *customers, int customer_count);

#endif
