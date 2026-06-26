#include <stdio.h>
#include <stdlib.h>

int main() {
    int pin = 1234, entered_pin, choice, count = 0;
    float balance = 5000.00;
    float deposit_amount, withdraw_amount;
    char transaction = 'y';

    printf("Welcome to the ATM Simulation\n");
    while (entered_pin != pin) {
        printf("Enter your 4-digit PIN: ");
        scanf("%d", &entered_pin);
        
        if (entered_pin != pin) {
            count++;
            if (count == 3) {
                printf("Too many incorrect attempts. Your card is blocked.\n");
                exit(0);
            }
            printf("Invalid PIN. You have %d attempt(s) left.\n\n", 3 - count);
        }
    }

    while (transaction == 'y' || transaction == 'Y') {
        printf("\n================ ATM Menu ================\n");
        printf("1. Check Balance\n");
        printf("2. Cash Withdraw\n");
        printf("3. Cash Deposit\n");
        printf("4. Exit\n");
        printf("==========================================\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nYour current balance is: $%.2f\n", balance);
                break;

            case 2:
                printf("\nEnter amount to withdraw: $");
                scanf("%f", &withdraw_amount);
                if (withdraw_amount % 10 != 0 && withdraw_amount % 20 != 0 && withdraw_amount % 50 != 0 && withdraw_amount % 100 != 0) {
                    printf("Error: Please enter amount in multiples of 10, 20, 50, or 100.\n");
                } else if (withdraw_amount > balance) {
                    printf("Error: Insufficient balance!\n");
                } else if (withdraw_amount <= 0) {
                    printf("Error: Invalid amount!\n");
                } else {
                    balance -= withdraw_amount;
                    printf("Please collect your cash. New balance: $%.2f\n", balance);
                }
                break;

            case 3:
                printf("\nEnter amount to deposit: $");
                scanf("%f", &deposit_amount);
                if (deposit_amount > 0) {
                    balance += deposit_amount;
                    printf("Successfully deposited $%.2f. New balance: $%.2f\n", deposit_amount, balance);
                } else {
                    printf("Error: Invalid deposit amount!\n");
                }
                break;

            case 4:
                printf("\nThank you for using our ATM. Have a great day!\n");
                exit(0);

            default:
                printf("Error: Invalid choice. Please select from 1 to 4.\n");
                break;
        }

        printf("\nDo you wish to perform another transaction? (y/n): ");
        scanf(" %c", &transaction); 
    }

    printf("\nThank you for using our ATM. Have a great day!\n");
    return 0;
}
