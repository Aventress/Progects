#include "Trust_account.h"
#include "NegativeBalanceException.h"
#include "InsufficentFundsException.h"

Trust_account::Trust_account(std::string name, double balance, double int_rate, double allowed_summ_to_withdraw)
	:Savings_Account{ name, balance, int_rate }, allowed_summ_to_withdraw{ balance * 0.2 } {
	if (balance < 0.0) {
		throw NegativeBalanceException{};
	}
}

bool Trust_account::deposit(double ammount) {
	double trust_summ = (ammount + 50) * 0.2; // для trust account, если заносится сумма больше 500$, то тогда начисляется бонусом 50$
	if (ammount >= 500.0) {
		allowed_summ_to_withdraw = trust_summ * 0.2; //нужно обновит минимальную сумму снятия (комменты как у нейронки)
		return Savings_Account::deposit(trust_summ);
	}
	else {
		return Savings_Account::deposit(ammount);
	}
}

bool Trust_account::withdraw(double ammount) {
	if (balance - ammount >= 0) {
		if (counter >= 3) {
			std::cout << "You can withdraw only 3 times per year";
			return false;
		}
		if (ammount <= allowed_summ_to_withdraw) {
			std::cout << "You cant withdraw sums less than 20$ of youre balance\nYoure current balance is: " << balance << "%\nAnd youve tried to withwraw is: " << ammount << "$\nSo minimal allowed sum for you is: " << allowed_summ_to_withdraw << "&\n";
			return false;
		}
		else if (Account::withdraw(ammount)) {
			std::cout << "$. Youre current withdraw minimal summ is: " << allowed_summ_to_withdraw
				<< "$. And Youre curren withdraw count is(3 times per year) : " << counter << " times]\n";
			counter++;
			return true;
		}
	}
	else {
		throw InsufficentFundsException{};
	}
}

void Trust_account::print(std::ostream& os) const {
	std::cout << "[Trust Account: " << Trust_account::name << " with balance: "
		<< Trust_account::balance << "$ and int rate " << Trust_account::int_rate << "$ ]" << std::endl;
}

double Trust_account::get_allowed_summ_to_withdraw() const{
	return allowed_summ_to_withdraw;
}