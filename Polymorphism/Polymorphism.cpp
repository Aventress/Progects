// Section 15
// Challenge 
#include <iostream>
#include <vector>
#include "Savings_Account.h"
#include "Trust_account.h"
#include "Account_Util.h"
#include "Checking_Account.h"

using namespace std;

int main() {
    cout.precision(2);
    cout << fixed;
    
    // Savings 
    Account* Sav_acc_1 = new Savings_Account{"MyMan", 200};
    Account* Sav_acc_2 = new Savings_Account{ "MyBoy", 200, 2.0 };
    display(Sav_acc_2);
    Sav_acc_1->deposit(1000);
    Sav_acc_1->withdraw(100);

    // Checking
    Account* Check_acc = new Checking_Account;
    Account* Check_acc_2 = new Checking_Account{"BOY", 2000};
    display(Check_acc);
    Check_acc->deposit(1000);
    Check_acc->withdraw(300);

    // Trust
    Account* Trust_acc = new Trust_account;
    display(Trust_acc);
    Trust_acc->deposit(1000);
    Trust_acc->withdraw(300);

    return 0;
}

