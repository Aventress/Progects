#pragma once
#include "Account.h"
#include <iostream>
#include <string>

class Checking_Account : public Account {
	friend std::ostream& operator<<(std::ostream& os, const Checking_Account& account);
private:
	static constexpr const char* default_checking_account_name = "Unnamed Checking account";
	static constexpr double def_balance = 0.0;
	static constexpr double def_fee = 1.5;
public:
	Checking_Account(std::string name = default_checking_account_name, double balance = def_balance);
	bool withdraw(double amount);
};