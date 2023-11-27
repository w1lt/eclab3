#include "banking_system.h"

Account::Account(std::string num, std::string holder, double bal)
    : accountNumber(num), accountHolder(holder), balance(bal) {}

void Account::displayDetails() const {
    std::cout << "Account Details for Account (ID: " << accountNumber << "):\n"
              << "   Holder: " << accountHolder << "\n"
              << "   Balance: $" << balance << "\n";
}

void Account::deposit(double amount) {
    balance += amount;
}

void Account::withdraw(double amount) {
    if (amount <= balance) {
        balance -= amount;
    } else {
        std::cout << "Insufficient funds.\n";
    }
}

std::ostream& operator<<(std::ostream& os, const Account& account) {
    account.displayDetails();
    return os;
}

SavingsAccount::SavingsAccount(std::string num, std::string holder, double bal, double rate)
    : Account(num, holder, bal), interestRate(rate) {}

void SavingsAccount::displayDetails() const {
    Account::displayDetails();
    std::cout << "   Interest Rate: " << interestRate * 100 << "%\n";
}

void SavingsAccount::withdraw(double amount) {
    if (balance - amount < 500) { // Assuming minimum balance is 500
        std::cout << "Cannot withdraw. Minimum balance requirement not met.\n";
    } else {
        Account::withdraw(amount);
    }
}

CurrentAccount::CurrentAccount(std::string num, std::string holder, double bal, double limit)
    : Account(num, holder, bal), overdraftLimit(limit) {}

void CurrentAccount::displayDetails() const {
    Account::displayDetails();
    std::cout << "   Overdraft Limit: $" << overdraftLimit << "\n";
}

void CurrentAccount::withdraw(double amount) {
    if (amount <= balance + overdraftLimit) {
        balance -= amount;
    } else {
        std::cout << "Overdraft limit exceeded.\n";
    }
}

CurrentAccount CurrentAccount::operator+(const SavingsAccount& savings) {
    this->balance += savings.getBalance();
    return *this;
}

