#include "Account.h"

Account::Account(std::string name, double balance) 
    : name{name}, balance{balance} {
}

bool Account::deposit(double amount) {
    if (amount < 0) 
        return false;
    else {
        balance += amount;
        return true;
    }
}

bool Account::withdraw(double amount) {
    if (balance-amount >=0) {
        balance-=amount;
        return true;
    } else
        return false;
}

//я хз нах я это написал, если мы все равно с Account ниче делать не можем
void Account::print(std::ostream& os) const {
    std::cout << "[Account: " << Account::name << " with balance: " << Account::balance << "$ ]\n";
}
