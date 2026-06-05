// Section 15
// Challenge 
#include <iostream>
#include <vector>
#include "Savings_Account.h"
#include "Trust_account.h";
#include "Account_Util.h"

using namespace std;

int main() {
    cout.precision(2);
    cout << fixed;
    /*
    // Accounts
    vector<Account> accounts;
    accounts.push_back(Account{});
    accounts.push_back(Account{ "Larry" });
    accounts.push_back(Account{ "Moe", 2000 });
    accounts.push_back(Account{ "Curly", 5000 });

    display(accounts);
    deposit(accounts, 1000);
    withdraw(accounts, 2000);

    // Savings 

    vector<Savings_Account> sav_accounts;
    sav_accounts.push_back(Savings_Account{});
    sav_accounts.push_back(Savings_Account{ "Superman" });
    sav_accounts.push_back(Savings_Account{ "Batman", 2000 });
    sav_accounts.push_back(Savings_Account{ "Wonderwoman", 5000, 5.0 });

    display(sav_accounts);
    deposit(sav_accounts, 1000);
    withdraw(sav_accounts, 2000); */

    // Trust

    vector<Trust_account> trust_acc;
   // trust_acc.push_back(Trust_account{});
   // trust_acc.push_back(Trust_account{ "MRBALL" });
    trust_acc.push_back(Trust_account{ "GANDON", 20000 });
    trust_acc.push_back(Trust_account{ "Markplier", 50000, 2.0});

    display(trust_acc);
    deposit(trust_acc, 1000);
    withdraw(trust_acc, 5000);
    return 0;
}

