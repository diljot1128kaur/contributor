#include <stdio.h>
#include <string.h>

// Define structure for customer data
struct customer {
    int id;
    char name[50];
    char address[100];
    char phone[11];
};

// Define global variables
int num_customers = 0;
struct customer customers[100];

// Function to add a new customer
void add_customer() {
    struct customer new_customer;
    printf("Enter customer name: ");
    scanf("%s", new_customer.name);
    printf("Enter customer address: ");
    scanf("%s", new_customer.address);
    printf("Enter customer phone number: ");
    scanf("%s", new_customer.phone);
    new_customer.id = num_customers + 1;
    customers[num_customers] = new_customer;
    num_customers++;
    printf("Customer added successfully.\n");
}

// Function to display customer details
void display_customers() {
    if (num_customers == 0) {
        printf("No customers found.\n");
    } else {
        printf("ID\tName\tAddress\t\tPhone\n");
        for (int i = 0; i < num_customers; i++) {
            printf("%d\t%s\t%s\t%s\n", customers[i].id, customers[i].name, customers[i].address, customers[i].phone);
        }
    }
}

// Function to remove a customer
void remove_customer() {
    int id;
    printf("Enter customer ID: ");
    scanf("%d", &id);
    int index = -1;
    for (int i = 0; i < num_customers; i++) {
        if (customers[i].id == id) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Customer not found.\n");
    } else {
        for (int i = index; i < num_customers - 1; i++) {
            customers[i] = customers[i+1];
        }
        num_customers--;
        printf("Customer removed successfully.\n");
    }
}

// Main function
int main() {
    int choice;
    do {
        printf("\n\n");
        printf("1. Add customer\n");
        printf("2. Display customers\n");
        printf("3. Remove customer\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_customer();
                break;
            case 2:
                display_customers();
                break;
            case 3:
                remove_customer();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 4);
    return 0;
}