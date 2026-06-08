#include"Checking_Account.h"

Checking_Account::Checking_Account(std::string name, double balance)
    :Account{ name, balance }{
}

bool Checking_Account::withdraw(double amount) {
    amount += 1.5;
    return Account::withdraw(amount);
}

bool Checking_Account::deposit(double amount) {
    return Account::deposit(amount);
}

void Checking_Account::print(std::ostream& os) const {
    std::cout << "\n===Checking Accounts ==========================================" << std::endl;
    std::cout << "[Checking Account: " << Checking_Account::name << " with balance: "
    << Checking_Account::balance << "$ ]\n";
}