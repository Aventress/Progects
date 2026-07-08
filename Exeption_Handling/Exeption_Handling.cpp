#include <iostream>
#include <vector>
#include "Savings_Account.h"
#include "Trust_account.h"
#include "Account_Util.h"
#include "Checking_Account.h"
#include "NegativeBalanceException.h"
#include "InsufficentFundsException.h"

using namespace std;

int main() {
    cout.precision(2);
    cout << fixed;

    // Savings 
    try {
        Account* Sav_acc_2 = new Savings_Account{ "MyBoy", 2000, 2.0 };
        withdraw(Sav_acc_2, 3000);
        Account* Sav_acc_3 = new Savings_Account{ "MyGoy", -200, 2.0 };
        vector <Account*> vector_of_sav_acc;
        vector_of_sav_acc.push_back(Sav_acc_3);
        display(Sav_acc_3);
        display(vector_of_sav_acc);
        deposit(Sav_acc_3, 1000);
        withdraw(Sav_acc_3, 200);
    }
    catch (const InsufficentFundsException& ex) {
        cerr << ex.what() << endl;
    }
    catch (const NegativeBalanceException& ex) {
        cerr << ex.what() << endl;
    }
    try {
        // Checking
        Account* Check_acc = new Checking_Account{ "BOY", -2000 };
        vector <Account*> vector_of_check_acc;
        vector_of_check_acc.push_back(Check_acc);
        display(Check_acc);
        display(vector_of_check_acc);
        deposit(Check_acc, 1000);
    } 
    catch (const InsufficentFundsException& ex) {
        cerr << ex.what() << endl;
    }
    catch (const NegativeBalanceException& ex) {
        cerr << ex.what() << endl;
    }
    try {
        // Trust
        Account* Trust_acc_1 = new Trust_account{ "Pony", 5734, 5.6 };
        vector <Account*> vector_of_trust_acc;
        vector_of_trust_acc.push_back(Trust_acc_1);
        display(Trust_acc_1);
        display(vector_of_trust_acc);
        deposit(Trust_acc_1, 1000);
        withdraw(Trust_acc_1, 500);
    }
    catch (const InsufficentFundsException& ex) {
        cerr << ex.what() << endl;
    }
    catch (const NegativeBalanceException& ex) {
        cerr << ex.what() << endl;
    }
    /*delete Sav_acc_1;
    delete Sav_acc_2;
    delete Check_acc;
    delete Check_acc_2;
    delete Trust_acc_1;
    delete Trust_acc_2;
    delete Trust_acc_3;*/
    return 0;
}

