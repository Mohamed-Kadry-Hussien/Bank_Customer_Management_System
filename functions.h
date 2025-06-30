// Defining header guard to prevent multiple inclusions
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

// Used libraries and headers
#include <stdio.h>
#include <stdbool.h>

// Macros and constants
#define MAX_CUSTOMERS 100
#define PHONE_LENGTH 11

// The main struct for customer data
typedef struct
{
    int id;
    char name[100];
    char phone[20];
    double balance;
} Customer;

/*
    Global variables to store customers data.
    extern keyword is used to declare variables that are defined in another file.
    This allows us to use these variables across multiple files without redefining them.
*/
extern Customer customers[MAX_CUSTOMERS];
extern int customer_count;

bool is_valid_name(const char *name);  // Function to validate customer name
bool is_valid_phone(const char *phone);  // Function to validate customer phone number
void load_data();  // Function to load customer data from a file
void save_data(Customer *customers, int *customer_count, char *file_name);  // Function to save customer data to a file
int find_customer(Customer *customers, int customer_count, int id);  // Function to find a customer by ID
void create_customer(Customer *customers, int *customer_count);  // Function to create a new customer
void edit_customer(Customer *customers, int *customer_count);  // Function to edit an existing customer's data
void print_customer_data(Customer *customers, int *customer_count);  // Function to print customer data by ID
void delete_customer(Customer *customers, int *customer_count);  // Function to delete a customer by ID
void deposit();  // Function to deposit money into a customer's account
void withdraw();  // Function to withdraw money from a customer's account
void transfer_money(Customer *customers, int customer_count);  // Function to transfer money between two customers

#endif
