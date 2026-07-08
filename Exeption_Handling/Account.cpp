#include "Account.h"
#include "NegativeBalanceException.h"
#include "InsufficentFundsException.h"

Account::Account(std::string name, double balance)
    : name{ name }, balance{ balance } {
    if (balance < 0.0) {
        throw NegativeBalanceException{};
    }
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
    }
    else
        throw InsufficentFundsException{};
}

void Account::print(std::ostream& os) const {
    std::cout << "[Account: " << name << " with balance: " << balance << "$ ]\n";
}
