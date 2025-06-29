#include <stdio.h>
#include "functions.h"

Customer customers[MAX_CUSTOMERS];

void transfer_money(Customer *customers, int ID1, int ID2, double amount, int customer_count)
{
    int index1 = find_customer(customers, customer_count, ID1);
    int index2 = find_customer(customers, customer_count, ID2);
    if (index1 == -1 || index2 == -1)
    {
        printf("Customer not found\n");
        return;
    }
    if (index1 == index2)
    {
        printf("Same customer!\n");
        return;
    }
    if (amount <= 0)
    {
        printf("Invalid amount\n");
        return;
    }
    if (customers[index1].balance < amount)
    {
        printf("Insufficient balance\n");
        return;
    }
    customers[index1].balance -= amount;
    customers[index2].balance += amount;
    printf("Transfer of %.2f from customer %d to customer %d completed successfully.\n", amount, ID1, ID2);
}

int find_customer(Customer *customers, int customer_count, int id)
{
    if (customer_count <= 0 || customers == NULL)
    {
        printf("No customers available.\n");
        return -1;
    }
    for (int i = 0; i < customer_count; i++)
    {
        if (customers[i].id == id)
            return i;
    }
    return -1;
}