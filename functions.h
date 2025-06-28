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

void load_data();
void save_data();
void create_customer();
void edit_customer();
void print_customer_data();
void delete_customer();
void deposit();
void withdraw();
void transfer_money();

#endif
