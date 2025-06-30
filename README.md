# 💳 Bank Customer Management System

A simple, menu-driven console application written in C that allows you to manage customer accounts. The system supports creating, editing, viewing, and deleting customers, as well as deposit, withdrawal, and money transfer operations. All customer data is saved persistently in a text file.

---

## 📁 Project Files

- `main.c` – Contains the main menu and program UI.
- `functions.c` – Contains implementations for all core functionalities.
- `functions.h` – Contains function declarations, struct definitions, constants and marcos.
- `customers.txt` – Used to store customer records in CSV format (auto-generated).

---

## ✅ Main functions

- crate_customer(): Add new customers (with auto-generated unique ID)
- edit_customer(): Edit existing customer details
- print_customer_data(): View customer details by ID
- delete_customer(): Delete customer accounts
- find_customer(): searches for the customer in the array by the ID
- deposit(): Deposit money to the account by ID
- withdraw(): withdraw money from the account by the ID
- transfer_money(): Transfer money between customers
- save_data(): Data is automatically saved after each operation
- load_data(): Getting all the customers in the array after running the program
- Another functions for input validation for names, phone numbers, and balances
