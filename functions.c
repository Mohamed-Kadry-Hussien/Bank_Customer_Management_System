#include <stdio.h>
#include "functions.h"

Customer customers[MAX_CUSTOMERS];

void transfer_money(Customer *customers, int ID1, int ID2, double amount)
{
    int index1 = find_customer(customers, ID1, 0, customer_count);
    int index2 = find_customer(customers, ID2, 0, customer_count);
    if (index1 == -1 || index2 == -1)
    {
        printf("Customer not found\n");
        return;
    }
    customers[index1].balance -= amount;
    customers[index2].balance += amount;
}

int find_customer(Customer *customers, int id, int start, int end)
{
    if (start > end)
        return -1;
    int mid = start + (end - start) / 2;
    if (id == customers[mid].id)
        return mid;
    else if (id < customers[mid].id)
        return find_customer(customers, id, start, mid - 1);
    else
        return find_customer(customers, id, mid + 1, end);
}