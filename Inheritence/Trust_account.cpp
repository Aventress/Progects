#include "Trust_account.h"

Trust_account::Trust_account(std::string name, double balance, double int_rate)
	:Savings_Account{ name, balance, int_rate } {
}

bool Trust_account::deposit(double ammount) {
	if (ammount >= 500.0) {
		return Savings_Account::deposit(ammount + 50);
	}
	else {
		return Savings_Account::deposit(ammount);
	}
}

bool Trust_account::withdraw(double ammount) {
	static size_t counter{};
	double allowed_summ_to_withdraw = balance * 0.2;
	if (counter >= 3) {
		std::cout << "You can withdraw only 3 times per year";
		return false;
	}
	if (ammount <= allowed_summ_to_withdraw) {
		std::cout << "You cant withdraw sums less than 20$ of youre balance\nYoure current balance is: " << balance << "%\nAnd youve tried to withwraw is: " << ammount << "$\nSo minimal allowed sum for you is: " << allowed_summ_to_withdraw << "&\n";
		return false;
	}
	else if (Account::withdraw(ammount)) {
		counter++;
		return true;
	}
}

std::ostream& operator<<(std::ostream& os, const Trust_account& account) {
	os << "[Trust_Account: " << account.name << ": " << account.balance << ", " << account.int_rate << "%]";
	return os;
}
