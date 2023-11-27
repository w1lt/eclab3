#ifndef BANKING_SYSTEM_H
#define BANKING_SYSTEM_H

#include <iostream>
#include <string>

class Account {
protected:
    std::string accountNumber;
    std::string accountHolder;
    double balance;

public:
    Account(std::string accountNumber, std::string accountHolder, double balance);
    virtual void displayDetails() const;
    void deposit(double amount);
    virtual void withdraw(double amount);
    friend std::ostream& operator<<(std::ostream& os, const Account& account);
    double getBalance() const { return balance; }
};

class SavingsAccount : public Account {
private:
    double interestRate;

public:
    SavingsAccount(std::string accountNumber, std::string accountHolder, double balance, double interestRate);
    void displayDetails() const override;
    void withdraw(double amount) override;
};

class CurrentAccount : public Account {
private:
    double overdraftLimit;

public:
    CurrentAccount(std::string accountNumber, std::string accountHolder, double balance, double overdraftLimit);
    void displayDetails() const override;
    void withdraw(double amount) override;
    CurrentAccount operator+(const SavingsAccount& savings);
};

#endif // BANKING_SYSTEM_H
