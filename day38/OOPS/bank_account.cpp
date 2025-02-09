#include <iostream>
using namespace std;

class BankAccount {
private:
    int accountNumber;
    string accountHolderName;
    double balance;

public:
    BankAccount(int accNo, string name, double bal) {
        accountNumber = accNo;
        accountHolderName = name;
        balance = bal;
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposited: " << amount << "\n";
    }

    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient Balance!\n";
        } else {
            balance -= amount;
            cout << "Withdrawn: " << amount << "\n";
        }
    }

    void display() {
        cout << "Account Number: " << accountNumber << "\n";
        cout << "Account Holder: " << accountHolderName << "\n";
        cout << "Balance: " << balance << "\n";
    }
};

int main() {
    BankAccount acc(101, "Mayank Gaur", 5000);

    acc.display();
    acc.deposit(2000);
    acc.withdraw(3000);
    acc.display();

    return 0;
}
