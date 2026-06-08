#pragma once
#include "Savings_Account.h"
#include <iostream>
#include <string>

class Trust_account : public Savings_Account {
private:
	size_t counter {};
	static constexpr const char* default_trust_account_name = "Unnamed trust account";
	static constexpr double def_balance = 0.0;
	static constexpr double def_int_rate = 0.0;
	static constexpr double def_allowed_summ_to_withdraw = def_balance * 0.2;
protected:
	double allowed_summ_to_withdraw = 0.0;
public:
	Trust_account(std::string name = default_trust_account_name, double balance = def_balance, double int_rate = def_int_rate, double allowed_summ_to_withdraw = def_allowed_summ_to_withdraw);
	virtual void print(std::ostream& os) const override;
	virtual bool deposit(double ammount) override;
	virtual bool withdraw(double amount) override;
	double get_allowed_summ_to_withdraw() const;
};