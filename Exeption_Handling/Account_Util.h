#ifndef _ACCOUNT_UTIL_H_
#define _ACCOUNT_UTIL_H_
#include <vector>
#include <memory>
#include "Account.h"

void display(const std::vector <std::shared_ptr<Account>> &account);
void display(const std::shared_ptr<Account>& account);
void deposit(std::shared_ptr<Account> &account, double ammount);
void deposit(const std::vector<std::shared_ptr<Account>>&account, double ammount);
void withdraw(std::shared_ptr<Account> &account, double ammount);
void withdraw(const std::vector<std::shared_ptr<Account>>&account, double ammount);

#endif