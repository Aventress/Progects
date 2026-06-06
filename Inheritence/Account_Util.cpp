#include <iostream>
#include "Account_Util.h"

// Displays Account objects in a  vector of Account objects 
void display(const std::vector<Account> &accounts) {
    std::cout << "\n=== Accounts ==========================================" << std::endl;
    for (const auto &acc: accounts) 
        std::cout << acc << std::endl;
}

// Deposits supplied ammount to each Account object in the vector
void deposit(std::vector<Account> &accounts, double ammount) {
    std::cout << "\n=== Depositing to Accounts =================================" << std::endl;
    for (auto &acc:accounts)  {
        if (acc.deposit(ammount)) 
            std::cout << "Deposited " << ammount << " to " << acc << std::endl;
        else
            std::cout << "Failed Deposit of " << ammount << " to " << acc << std::endl;
    }
}

// Deposit supplied ammount to 1 Account 
void deposit(Account& account, double ammount) {
    std::cout << "\n=== Depositing to Accounts ==========================" << std::endl;
    if (account.deposit(ammount)) {
        std::cout << "Deposited " << ammount << " to " << account << std::endl;
    }
    else
        std::cout << "Failed Deposit of " << ammount << " to " << account << std::endl;
}

// Withdraw ammount from each Account object in the vector
void withdraw(std::vector<Account> &accounts, double ammount) {
    std::cout << "\n=== Withdrawing from Accounts ==============================" <<std::endl;
    for (auto &acc:accounts)  {
        if (acc.withdraw(ammount)) 
            std::cout << "Withdrew " << ammount << " from " << acc << std::endl;
        else
            std::cout << "Failed Withdrawal of " << ammount << " from " << acc << std::endl;
    } 
}

// Withdraw supplied ammount to 1 Trust account 
void withdraw(Account& account, double ammount) {
    std::cout << "\n=== Withdrawing from Accounts ======================" << std::endl;
    if (account.withdraw(ammount))
        std::cout << "Withdrew " << ammount << " from " << account << std::endl;
    else
        std::cout << "Failed Withdrawal of " << ammount << " from " << account << std::endl;
}

// Helper functions for Savings Account class

// Displays Savings Account objects in a  vector of Savings Account objects 
void display(const std::vector<Savings_Account> &accounts) {
    std::cout << "\n=== Savings Accounts ====================================" << std::endl;
    for (const auto &acc: accounts) 
        std::cout << acc << std::endl;
}

// Deposits supplied ammount to each Savings Account object in the vector
void deposit(std::vector<Savings_Account> &accounts, double ammount) {
    std::cout << "\n=== Depositing to Savings Accounts ==========================" << std::endl;
    for (auto &acc:accounts)  {
        if (acc.deposit(ammount)) 
            std::cout << "Deposited " << ammount << " to " << acc << std::endl;
        else
            std::cout << "Failed Deposit of " << ammount << " to " << acc << std::endl;
    }
}

// Deposit supplied ammount to 1 Saving account 
void deposit(Savings_Account& account, double ammount) {
    std::cout << "\n=== Depositing to Savings Accounts ==========================" << std::endl;
    if (account.deposit(ammount)) {
        std::cout << "Deposited " << ammount << " to " << account << std::endl;
    }
    else
        std::cout << "Failed Deposit of " << ammount << " to " << account << std::endl;
}

// Withdraw supplied ammount from each Savings Account object in the vector
void withdraw(std::vector<Savings_Account> &accounts, double ammount) {
    std::cout << "\n=== Withdrawing from Savings Accounts ======================" << std::endl;
    for (auto &acc:accounts)  {
        if (acc.withdraw(ammount)) 
            std::cout << "Withdrew " << ammount << " from " << acc << std::endl;
        else
            std::cout << "Failed Withdrawal of " << ammount << " from " << acc << std::endl;
    } 
}

// Withdraw supplied ammount to 1 Trust account 
void withdraw(Savings_Account& account, double ammount) {
    std::cout << "\n=== Withdrawing from Savings Accounts ======================" << std::endl;
    if (account.withdraw(ammount))
        std::cout << "Withdrew " << ammount << " from " << account << std::endl;
    else
        std::cout << "Failed Withdrawal of " << ammount << " from " << account << std::endl;
}

// Helper functions for Trust Account class

// Displays Trust Account objects in a  vector of Trust Account objects 
void display(const std::vector<Trust_account>& accounts) {
    std::cout << "\n=== Trust Accounts ====================================" << std::endl;
    for (const auto& acc : accounts)
        std::cout << acc << " Minimal withdraw sum for you is: " << acc.get_balance() * 0.2 <<"$\n";
}

// Deposits supplied ammount to each Trust Account object in the vector
void deposit(std::vector<Trust_account>& accounts, double ammount) {
    std::cout << "\n=== Depositing to Trust Accounts ==========================" << std::endl;
    for (auto& acc : accounts) {
        if (acc.deposit(ammount))
            std::cout << "Deposited " << ammount << " to " << acc << " Now, minimal withdraw sum for you is: " << acc.get_balance() * 0.2 << "$\n";
        else
            std::cout << "Failed Deposit of " << ammount << " to " << acc << std::endl;
    }
}

// Deposit supplied ammount to 1 Trust account 
void deposit(Trust_account& account, double ammount) {
    std::cout << "\n=== Depositing to Trust Accounts ==========================" << std::endl;
    if (account.deposit(ammount)) {
        std::cout << "Deposited " << ammount << " to " << account << " Now, minimal withdraw sum for you is: " << account.get_balance() * 0.2 << "$\n";
    }
    else
        std::cout << "Failed Deposit of " << ammount << " to " << account << std::endl;
}

// Withdraw supplied ammount from each Trust Account object in the vector
void withdraw(std::vector<Trust_account>& accounts, double ammount) {
    std::cout << "\n=== Withdrawing from Trust Accounts ======================" << std::endl;
    for (auto& acc : accounts) {
        if (acc.withdraw(ammount))
            std::cout << "Withdrew " << ammount << " from " << acc << std::endl;
        else
            std::cout << "Failed Withdrawal of " << ammount << " from " << acc << std::endl;
    }
}

// Withdraw supplied ammount to 1 Trust account 
void withdraw(Trust_account& account, double ammount) {
    std::cout << "\n=== Withdrawing from Trust Accounts ======================" << std::endl;
    if (account.withdraw(ammount))
        std::cout << "Withdrew " << ammount << " from " << account << std::endl;
    else
        std::cout << "Failed Withdrawal of " << ammount << " from " << account << std::endl;
}


// Helper functions for Checking Account class

// Displays Trust Account objects in a  vector of Checking Account objects 
void display(const std::vector<Checking_Account>& accounts) {
    std::cout << "\n=== Checking Accounts ====================================" << std::endl;
    for (const auto& acc : accounts)
        std::cout << acc << std::endl;
}

// Deposits supplied ammount to each Checking Account object in the vector
void deposit(std::vector<Checking_Account>& accounts, double ammount) {
    std::cout << "\n=== Depositing to Checking Accounts =================================" << std::endl;
    for (auto& acc : accounts) {
        if (acc.deposit(ammount))
            std::cout << "Deposited " << ammount << " to " << acc << std::endl;
        else
            std::cout << "Failed Deposit of " << ammount << " to " << acc << std::endl;
    }
}

// Deposit supplied ammount to 1 Checking account 
void deposit(Checking_Account& account, double ammount) {
    std::cout << "\n=== Depositing to Checking Accounts ==========================" << std::endl;
    if (account.deposit(ammount)) {
        std::cout << "Deposited " << ammount << " to " << account << std::endl;
    }
    else
        std::cout << "Failed Deposit of " << ammount << " to " << account << std::endl;
}

// Withdraw supplied ammount from each Checking Account object in the vector
void withdraw(std::vector<Checking_Account>& accounts, double ammount) {
    std::cout << "\n=== Withdrawing from Checking Accounts ==============================" << std::endl;
    for (auto& acc : accounts) {
        if (acc.withdraw(ammount))
            std::cout << "Withdrew " << ammount << " from " << acc << std::endl;
        else
            std::cout << "Failed Withdrawal of " << ammount << " from " << acc << std::endl;
    }
}

// Withdraw supplied ammount to 1 Checking account 
void withdraw(Checking_Account& account, double ammount) {
    std::cout << "\n=== Withdrawing from Checking Accounts ======================" << std::endl;
    if (account.withdraw(ammount))
        std::cout << "Withdrew " << ammount << " from " << account << std::endl;
    else
        std::cout << "Failed Withdrawal of " << ammount << " from " << account << std::endl;
}