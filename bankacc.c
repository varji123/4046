#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define MAX_NAME_LENGTH 100

// Structure to store account information
typedef struct {
    int accountNumber;
    char name[MAX_NAME_LENGTH];
    float balance;
} Account;

// Global array to store all the accounts
Account accounts[MAX_ACCOUNTS];
int numAccounts = 0;

// Function to create a new account
void createAccount() {
    if (numAccounts >= MAX_ACCOUNTS) {
        printf("Sorry, the system is at full capacity.\n");
        return;
    }

    Account newAccount;
    newAccount.accountNumber = numAccounts + 1;

    printf("Enter the name of the account holder: ");
    getchar();  // To consume the newline character left by the previous input
    fgets(newAccount.name, MAX_NAME_LENGTH, stdin);
    newAccount.name[strcspn(newAccount.name, "\n")] = '\0'; // Remove the newline at the end

    newAccount.balance = 0.0;

    accounts[numAccounts] = newAccount;
    numAccounts++;

    printf("Account created successfully! Your account number is: %d\n", newAccount.accountNumber);
}

// Function to find an account by account number
Account* findAccount(int accountNumber) {
    for (int i = 0; i < numAccounts; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            return &accounts[i];
        }
    }
    return NULL;
}

// Function to deposit money
void deposit() {
    int accountNumber;
    float amount;

    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    Account* account = findAccount(accountNumber);
    if (account == NULL) {
        printf("Account not found.\n");
        return;
    }

    printf("Enter amount to deposit: ");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Invalid deposit amount.\n");
        return;
    }

    account->balance += amount;
    printf("Deposit successful! New balance: %.2f\n", account->balance);
}

// Function to withdraw money
void withdraw() {
    int accountNumber;
    float amount;

    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    Account* account = findAccount(accountNumber);
    if (account == NULL) {
        printf("Account not found.\n");
        return;
    }

    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Invalid withdrawal amount.\n");
        return;
    }

    if (account->balance < amount) {
        printf("Insufficient balance.\n");
        return;
    }

    account->balance -= amount;
    printf("Withdrawal successful! New balance: %.2f\n", account->balance);
}

// Function to check balance
void checkBalance() {
    int accountNumber;

    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    Account* account = findAccount(accountNumber);
    if (account == NULL) {
        printf("Account not found.\n");
        return;
    }

    printf("Account number: %d\n", account->accountNumber);
    printf("Account holder: %s\n", account->name);
    printf("Balance: %.2f\n", account->balance);
}

// Function to print all accounts
void printAllAccounts() {
    if (numAccounts == 0) {
        printf("No accounts available.\n");
        return;
    }

    printf("List of all accounts:\n");
    for (int i = 0; i < numAccounts; i++) {
        printf("Account Number: %d\n", accounts[i].accountNumber);
        printf("Name: %s\n", accounts[i].name);
        printf("Balance: %.2f\n\n", accounts[i].balance);
    }
}

// Function to delete an account
void deleteAccount() {
    int accountNumber;

    printf("Enter account number to delete: ");
    scanf("%d", &accountNumber);

    Account* account = findAccount(accountNumber);
    if (account == NULL) {
        printf("Account not found.\n");
        return;
    }

    // Delete account by shifting the remaining accounts
    for (int i = 0; i < numAccounts; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            for (int j = i; j < numAccounts - 1; j++) {
                accounts[j] = accounts[j + 1];
            }
            numAccounts--;
            printf("Account deleted successfully.\n");
            return;
        }
    }
}

// Function to print the menu
void printMenu() {
    printf("\nBanking System Menu:\n");
    printf("1. Create Account\n");
    printf("2. Deposit Money\n");
    printf("3. Withdraw Money\n");
    printf("4. Check Balance\n");
    printf("5. Print All Accounts\n");
    printf("6. Delete Account\n");
    printf("7. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    int choice;

    while (1) {
        printMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                deposit();
                break;
            case 3:
                withdraw();
                break;
            case 4:
                checkBalance();
                break;
            case 5:
                printAllAccounts();
                break;
            case 6:
                deleteAccount();
                break;
            case 7:
                printf("Exiting the system...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

