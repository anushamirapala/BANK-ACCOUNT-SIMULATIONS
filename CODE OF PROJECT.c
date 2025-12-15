#include <stdio.h>
#include <stdlib.h>

struct Account {
    int accNumber;
    char name[50];
    float balance;

};

void createAccount() {
    struct Account acc;
    FILE *fp = fopen("account.txt", "w");

    printf("\nEnter Account Number: ");
    scanf("%d", &acc.accNumber);

    printf("Enter Name: ");
    scanf("%s", acc.name);

    acc.balance = 1000.0;

    fwrite(&acc, sizeof(acc), 1, fp);
    fclose(fp);

    printf("\nAccount Created Successfully!\n");
}

void depositMoney() {
    struct Account acc;
    FILE *fp = fopen("account.txt", "r+");

    fread(&acc, sizeof(acc), 1, fp);

    float amount;
    printf("\nEnter amount to deposit: ");
    scanf("%f", &amount);

    acc.balance += amount;

    fseek(fp, 0, SEEK_SET);
    fwrite(&acc, sizeof(acc), 1, fp);

    fclose(fp);
    printf("\nAmount Deposited Successfully!\n");
}

void withdrawMoney() {
    struct Account acc;
    FILE *fp = fopen("account.txt", "r+");

    fread(&acc, sizeof(acc), 1, fp);

    float amount;
    printf("\nEnter amount to withdraw: ");
    scanf("%f", &amount);

    if (amount > acc.balance) {
        printf("\nInsufficient Balance!\n");
    } else {
        acc.balance -= amount;
        fseek(fp, 0, SEEK_SET);
        fwrite(&acc, sizeof(acc), 1, fp);
        printf("\nWithdrawal Successful!\n");
    }

    fclose(fp);
}

void displayBalance() {
    struct Account acc;
    FILE *fp = fopen("account.txt", "r");

    fread(&acc, sizeof(acc), 1, fp);
    fclose(fp);

    printf("\n----- Account Details -----\n");
    printf("Account Number: %d\n", acc.accNumber);
    printf("Name: %s\n", acc.name);
    printf("Balance: %.2f\n", acc.balance);
}

int main() {
    int choice;

    while (1) {
        printf("\n===== BANK MENU =====\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Display Balance\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: createAccount(); break;
            case 2: depositMoney(); break;
            case 3: withdrawMoney(); break;
            case 4: displayBalance(); break;
            case 5:
                printf("\nThank you for using the Bank System!\n");
                exit(0);

            default:
                printf("\nInvalid choice! Try again.\n");
        }
    }

    return 0;
}
