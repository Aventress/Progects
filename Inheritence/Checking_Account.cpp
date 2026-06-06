#include"Checking_Account.h"

Checking_Account::Checking_Account(std::string name, double balance)
    :Account{ name, balance }{
}

bool Checking_Account::withdraw(double ammount) {
    ammount += 1.5;
    return Account::withdraw(ammount);
}

std::ostream& operator<<(std::ostream& os, const Checking_Account& account) {
    os << "[Checking Account: " << account.name << ": " << account.balance << "]";
    return os;
}