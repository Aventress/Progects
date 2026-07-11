#include <iostream>
#include <vector>
#include <memory>
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
    shared_ptr<Account> Sav_acc_1;
    shared_ptr<Account> Sav_acc_2;
    shared_ptr<Account> Check_akk_1;
    shared_ptr<Account> Check_akk_2;
    shared_ptr<Account> Trust_akk_1;
    shared_ptr<Account> Trust_akk_2;
    // Savings 
    try {
        Sav_acc_1 = make_shared<Savings_Account>("Boy", 200);

        Sav_acc_2 = make_shared<Savings_Account>("DOY", -200);

        vector <shared_ptr<Account>> vector_of_sav_acc;
        vector_of_sav_acc.push_back(Sav_acc_1);
        display(Sav_acc_1);

        //display(Sav_acc_2);

        display(vector_of_sav_acc);
        deposit(Sav_acc_1, 1000);
        deposit(vector_of_sav_acc, 10);
        withdraw(Sav_acc_1, 200);

        //withdraw(Sav_acc_1, 200000);
    }
    catch (const InsufficentFundsException& ex) {
        cerr << ex.what() << endl;
    }
    catch (const NegativeBalanceException& ex) {
        cerr << ex.what() << endl;
    }
    try {
        cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
        cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
        cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
        cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
        // Checking
        Check_akk_1 = make_shared<Checking_Account>("BOY", 2000);

        //Check_akk_1 = make_shared<Checking_Account>("Fish", -2000);

        vector <shared_ptr<Account>> vector_of_check_acc;
        vector_of_check_acc.push_back(Check_akk_1);
        display(Check_akk_1);
        display(vector_of_check_acc);
        deposit(Check_akk_1, 1000);
        withdraw(Check_akk_1, 500);

        //withdraw(Check_akk_1, 5000000);

    } 
    catch (const InsufficentFundsException& ex) {
        cerr << ex.what() << endl;
    }
    catch (const NegativeBalanceException& ex) {
        cerr << ex.what() << endl;
    }
    try {
        cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
        cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
        cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
        cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
        cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
        // Trust
        Trust_akk_1 = make_shared<Trust_account>("Pony", 5734, 5.6);

        //Trust_akk_2 = make_shared<Trust_account>("GARRET", -5734, 5.6);

        vector <shared_ptr<Account>> vector_of_trust_acc;
        vector_of_trust_acc.push_back(Trust_akk_1);
        display(Trust_akk_1);
        display(vector_of_trust_acc);
        deposit(Trust_akk_1, 1000);
        withdraw(Trust_akk_1, 500);

        //withdraw(Trust_akk_1, 500000);
    }
    catch (const InsufficentFundsException& ex) {
        cerr << ex.what() << endl;
    }
    catch (const NegativeBalanceException& ex) {
        cerr << ex.what() << endl;
    }
    return 0;
}

