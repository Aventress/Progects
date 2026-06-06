// Section 15
// Challenge 
#include <iostream>
#include <vector>
#include "Savings_Account.h"
#include "Trust_account.h";
#include "Account_Util.h"
#include "Checking_Account.h"

using namespace std;

int main() {
    cout.precision(2);
    cout << fixed;
    // Accounts
    vector<Account> accounts;
    accounts.push_back(Account{});
    accounts.push_back(Account{ "Larry" });
    accounts.push_back(Account{ "Moe", 2000 });
    accounts.push_back(Account{ "Curly", 5000 });

    display(accounts);
    deposit(accounts, 1000);
    deposit(accounts.at(3), 1000);
    withdraw(accounts.at(0), 100);

   // Savings 

    vector<Savings_Account> sav_accounts;
    sav_accounts.push_back(Savings_Account{});
    sav_accounts.push_back(Savings_Account{ "Superman" });
    sav_accounts.push_back(Savings_Account{ "Batman", 2000 });
    sav_accounts.push_back(Savings_Account{ "Wonderwoman", 5000, 5.0 });

    display(sav_accounts);
    deposit(sav_accounts, 1000);
    deposit(sav_accounts.at(2), 1000);
    withdraw(sav_accounts.at(0), 100);

   // Trust

   vector<Trust_account> trust_acc;
   trust_acc.push_back(Trust_account{});
   trust_acc.push_back(Trust_account{ "MRBALL" });
   trust_acc.push_back(Trust_account{ "GANDON", 2000 });
   trust_acc.push_back(Trust_account{ "Markplier", 5000, 2.0});

    display(trust_acc);
    deposit(trust_acc, 1000);
    deposit(trust_acc.at(1), 1000);
    withdraw(trust_acc, 5000);
    withdraw(trust_acc.at(1), 300);
    withdraw(trust_acc.at(1), 300);
    withdraw(trust_acc.at(1), 300);
    withdraw(trust_acc.at(2), 500);
    withdraw(trust_acc.at(1), 300);
    withdraw(trust_acc.at(2), 500);

    // Checking 
    vector<Checking_Account> check_acc;
    check_acc.push_back(Checking_Account{});
    check_acc.push_back(Checking_Account{"GOO BOO MOO"});
    check_acc.push_back(Checking_Account{"MRDOCKTORBOO", 10000});

    display(check_acc);
    deposit(check_acc, 1000);
    deposit(check_acc.at(1), 1000);
    withdraw(check_acc, 500);
    withdraw(check_acc.at(1), 500);

    return 0;
}

