#include <iostream>
#include "Account_Util.h"

// Displays Account objects in a  vector of Account objects 
void display(const Account* account) {
    std::cout << *account << std::endl;
}
void display(const Account& account) {
    std::cout << account << std::endl;
}
void display(const std::vector <Account*>& account) {
    std::cout << "======Display================================\n";
    for (auto& acc : account) {
        std::cout << *acc << std::endl;
    }
}

// Deposit supplied ammount to 1 Account 
void deposit(Account* &account, double ammount) {
    std::cout << "======Deposit================================\n";
    if (account->deposit(ammount)) {
        std::cout << "Deposited " << ammount << "$ to " << *account << std::endl;
    }
    else
        std::cout << "Failed Deposit of " << ammount << " to " << *account << std::endl;
}

void withdraw(Account* &account, double ammount) {
    std::cout << "======Withdraw================================\n";
    if (account->withdraw(ammount)) {
        std::cout << "Withdrawed " << ammount << "$ to " << *account << std::endl;
    }
    else
        std::cout << "Failded Withdraw of " << ammount << " to " << *account << std::endl;
}
