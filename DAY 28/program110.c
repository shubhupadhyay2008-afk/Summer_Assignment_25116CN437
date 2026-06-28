#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct BankAccount {
    int accountNumber;
    char name[50];
    float balance;
};

void createAccount(struct BankAccount *acc) {
    printf("\n--- Create New Account ---\n");
    printf("Enter Account Number: ");
    scanf("%d", &acc->accountNumber);
    printf("Enter Account Holder Name: ");
    scanf(" %[^\n]s", acc->name); 
    acc->balance = 0.0f;
    printf("Account created successfully for %s!\n", acc->name);
}

void depositMoney(struct BankAccount *acc) {
    float amount;
    printf("\n--- Deposit ---\n");
    printf("Enter amount to deposit: $");
    scanf("%f", &amount);
    
    if (amount > 0) {
        acc->balance += amount;
        printf("Successfully deposited $%.2f. New Balance: $%.2f\n", amount, acc->balance);
    } else {
        printf("Invalid deposit amount! Please enter a positive value.\n");
    }
}

void withdrawMoney(struct BankAccount *acc) {
    float amount;
    printf("\n--- Withdraw ---\n");
    printf("Enter amount to withdraw: $");
    scanf("%f", &amount);
    
    if (amount > 0 && amount <= acc->balance) {
        acc->balance -= amount;
        printf("Successfully withdrawn $%.2f. New Balance: $%.2f\n", amount, acc->balance);
    } else if (amount > acc->balance) {
        printf("Insufficient balance!\n");
    } else {
        printf("Invalid withdrawal amount! Please enter a positive value.\n");
    }
}

void checkBalance(struct BankAccount acc) {
    printf("\n--- Account Details ---\n");
    printf("Account Number: %d\n", acc.accountNumber);
    printf("Account Holder: %s\n", acc.name);
    printf("Current Balance: $%.2f\n", acc.balance);
}

int main() {
    struct BankAccount account;
    int choice;
    int accountCreated = 0;

    do {
        printf("\n=== BANK MANAGEMENT SYSTEM ===");
        printf("\n1. Create Account");
        printf("\n2. Deposit");
        printf("\n3. Withdraw");
        printf("\n4. Check Balance");
        printf("\n5. Exit");
        printf("\nEnter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount(&account);
                accountCreated = 1;
                break;
            case 2:
                if (accountCreated) depositMoney(&account);
                else printf("Please create an account first!\n");
                break;
            case 3:
                if (accountCreated) withdrawMoney(&account);
                else printf("Please create an account first!\n");
                break;
            case 4:
                if (accountCreated) checkBalance(account);
                else printf("Please create an account first!\n");
                break;
            case 5:
                printf("\nThank you for banking with us. Exiting...\n");
                break;
            default:
                printf("\nInvalid choice! Please select a valid option (1-5).\n");
        }
    } while (choice != 5);

    return 0;
}
