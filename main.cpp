#include "banking_system.h"

int main() {
    SavingsAccount savings("S123", "John Doe", 1000, 0.02);
    CurrentAccount current("C456", "Jane Doe", 2000, 500);

    std::cout << savings << current;

    savings.deposit(500);
    current.withdraw(1000);
    
    std::cout << "\nAccount Details after deposit and withdrawal:\n";
    std::cout << savings << current;

    // Transfer 300 from savings to current
    current = current + savings;

    std::cout << "\nAccount Details after transfer:\n";
    std::cout << savings << current;

    return 0;
}
