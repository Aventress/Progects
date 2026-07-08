#include "Savings_Account.h"
#include "NegativeBalanceException.h"
#include "InsufficentFundsException.h"

Savings_Account::Savings_Account(std::string name, double balance, double int_rate)
    : Account {name, balance}, int_rate{int_rate} {
    if (balance < 0.0) {
        throw NegativeBalanceException{};
    }
}

bool Savings_Account::deposit(double amount) {
    amount += amount * (int_rate/100);
    return Account::deposit(amount);
}
bool Savings_Account::withdraw(double amount) {
    return Account::withdraw(amount);
}

void Savings_Account::print(std::ostream& os) const {
    std::cout << "[Savings Account: " << Savings_Account::name << " with balance: " 
    << Savings_Account::balance << "$ and initiate rate: " << Savings_Account::int_rate << "$ ]\n";
}

