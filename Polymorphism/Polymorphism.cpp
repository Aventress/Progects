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
    vector <Account*> vector_of_sav_acc;
    vector_of_sav_acc.push_back(Sav_acc_1);
    vector_of_sav_acc.push_back(Sav_acc_2);
    display(Sav_acc_2);
    display(vector_of_sav_acc);
    deposit(Sav_acc_2, 1000);
    withdraw(Sav_acc_2, 200);

    // Checking
    Account* Check_acc = new Checking_Account;
    Account* Check_acc_2 = new Checking_Account{"BOY", 2000};
    vector <Account*> vector_of_check_acc;
    vector_of_check_acc.push_back(Check_acc);
    vector_of_check_acc.push_back(Check_acc_2);
    //display(Check_acc);
    display(vector_of_check_acc);
    deposit(Check_acc, 1000);
    withdraw(Check_acc_2, 100);

    // Trust
    Account* Trust_acc_1 = new Trust_account;
    Account* Trust_acc_2 = new Trust_account{"Chair", 7999, 2.5};
    Account* Trust_acc_3 = new Trust_account{"Pony", 5734, 5.6};
    vector <Account*> vector_of_trust_acc;
    vector_of_trust_acc.push_back(Trust_acc_1);
    vector_of_trust_acc.push_back(Trust_acc_2);
    vector_of_trust_acc.push_back(Trust_acc_3);
    display(Trust_acc_1);
    display(vector_of_trust_acc);
    deposit(Trust_acc_1, 1000);
    withdraw(Trust_acc_1, 500);
    delete Sav_acc_1;
    delete Sav_acc_2;
    delete Check_acc;
    delete Check_acc_2;
    delete Trust_acc_1;
    delete Trust_acc_2;
    delete Trust_acc_3;
    return 0;
}

