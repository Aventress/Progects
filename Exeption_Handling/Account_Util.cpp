#include <iostream>
#include "Account_Util.h"

void display(const Account* account) {
    std::cout << *account << std::endl;
}
void display(const Account& account) {
    std::cout << account << std::endl;
}
void display(const std::vector <Account*>& account) {
    std::cout << "======Display================================\n";
    for (auto acc : account) {
        std::cout << *acc << std::endl;
    }
}
void deposit(Account* &account, double ammount) {
    std::cout << "======Deposit================================\n";
    if (account->deposit(ammount)) {
        std::cout << "Deposited " << ammount << "$ to " << *account << std::endl;
    }
    else
        std::cout << "Failed Deposit of " << ammount << " to " << *account << std::endl;
}
void deposit(const std::vector<Account*>& account, double ammount) {
    std::cout << "======Deposit================================\n";
    for (auto acc : account) {
        if (acc->deposit(ammount)) {
            std::cout << "Deposited " << ammount << "$ to " << *acc << std::endl;
        }
        else
            std::cout << "Failed Deposit of " << ammount << " to " << *acc << std::endl;
    }
}

void withdraw(Account* &account, double ammount) {
    std::cout << "======Withdraw================================\n";
    if (account->withdraw(ammount)) {
        std::cout << "Withdrawed " << ammount << "$ to " << *account << std::endl;
    }
    else
        std::cout << "Failded Withdraw of " << ammount << " to " << *account << std::endl;
}

void withdraw(const std::vector<Account*>& account, double ammount) {
    std::cout << "======Withdraw================================\n";
    for (auto acc : account) {
        if (acc->withdraw(ammount)) {
            std::cout << "Withdrawed " << ammount << "$ to " << *acc << std::endl;
        }
        else
            std::cout << "Failded Withdraw of " << ammount << " to " << *acc << std::endl;
    }
}
