#ifndef _ACCOUNT_UTIL_H_
#define _ACCOUNT_UTIL_H_
#include <vector>
#include "Account.h"


void display(const Account* account);
void display(const std::vector <Account*> &account);
void display(const Account& account);
void deposit(Account* &account, double ammount);
void deposit(const std::vector<Account*> &account, double ammount);
void withdraw(Account* &account, double ammount);
void withdraw(const std::vector<Account*> &account, double ammount);

#endif