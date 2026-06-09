#ifndef _ACCOUNT_UTIL_H_
#define _ACCOUNT_UTIL_H_
#include <vector>
#include "Account.h"
#include "Savings_Account.h"
#include "Trust_account.h"
#include "Checking_Account.h"

// Utility helper functions for Account class

void display(const Account* account);
void display(const std::vector <Account*> &account);
void display(const Account& account);
void deposit(Account* &account, double ammount);
void withdraw(Account* &account, double ammount);

#endif