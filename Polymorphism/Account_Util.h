#ifndef _ACCOUNT_UTIL_H_
#define _ACCOUNT_UTIL_H_
#include <vector>
#include "Account.h"
#include "Savings_Account.h"
#include "Trust_account.h"
#include "Checking_Account.h"

// Utility helper functions for Account class

void display(const Account* account);
void display(const Account& account);
void deposit(std::vector<Account> &accounts, double amount);
void deposit(Account& account, double ammount);
void withdraw(std::vector<Account> &accounts, double amount);
void withdraw(Account& account, double ammount);

// Utility helper functions for Savings Account class
void deposit(std::vector<Savings_Account> &accounts, double amount);
void deposit(Savings_Account& account, double ammount);
void withdraw(std::vector<Savings_Account> &accounts, double amount);
void withdraw(Savings_Account& account, double ammount);

// Utility helper functions for Trust Account class

void deposit(std::vector<Trust_account>& accounts, double amount);
void deposit(Trust_account& account, double ammount);
void withdraw(std::vector<Trust_account>& accounts, double amount);
void withdraw(Trust_account& account, double ammount);

// Utility helper functions for Checking Account class
void deposit(std::vector<Checking_Account>& accounts, double amount);
void deposit(Checking_Account& account, double ammount);
void withdraw(std::vector<Checking_Account>& accounts, double amount);
void withdraw(Checking_Account& account, double ammount);
#endif