### Bank Account Inheritance Hierarchy

This C++ console application demonstrates object-oriented programming with inheritance, polymorphism, and the interface segregation principle. It implements a simple banking system with four account types, each with its own rules for deposits and withdrawals.
## Project Structure
File	Description
I_Printable.h/cpp	Interface with pure virtual print() method and overloaded operator<<
Account.h/cpp	Abstract base class implementing I_Printable; declares pure virtual deposit/withdraw
Savings_Account.h/cpp	Derived class adding an interest rate; deposit adds interest
Checking_Account.h/cpp	Derived class adding a flat fee of $1.50 per withdrawal
Trust_account.h/cpp	Derived from Savings_Account; gives bonus $50 on deposits ≥$500, restricts withdrawals (max 3 per year, each ≤20% of balance)
Account_Util.h/cpp	Utility functions for displaying, depositing, and withdrawing on single Account* and vectors of Account*
Polymorphism.cpp	Main program – tests all account types via base class pointers
## Class Hierarchy
text

I_Printable (interface)
    ↑
Account (abstract)
    ├── Savings_Account
    │    └── Trust_account
    └── Checking_Account

## Class Features
I_Printable

    Pure virtual void print(std::ostream&) const = 0

    Friend operator<< calls print(), enabling printing any derived object via base pointer/reference.

Account

    Stores name (string) and balance (double) as protected members.

    Pure virtual deposit(double) and withdraw(double) – makes Account abstract.

    Implements print() to display name and balance.

Savings_Account (inherits Account)

    Adds int_rate (double, percentage).

    deposit(amount): adds interest (amount * int_rate/100) before calling base deposit.

    withdraw(amount): passes directly to base withdraw (no extra fee).

Checking_Account (inherits Account)

    No extra data members, but a flat fee of 1.5 is applied on every withdrawal.

    withdraw(amount): adds 1.5 to the withdrawal amount, then calls base withdraw.

    deposit(amount): simply calls base deposit.

Trust_account (inherits Savings_Account)

    Adds counter (size_t) to track number of withdrawals (max 3 per object lifetime).

    Adds allowed_summ_to_withdraw (double) – stores 20% of current balance as the maximum allowed per withdrawal.

    deposit(amount): if amount ≥ 500, an extra $50 bonus is added before interest is applied. Then the deposit (including bonus) is passed to Savings_Account::deposit().

    withdraw(amount):

        Fails if 3 withdrawals have already been made.

        Fails if the withdrawal amount exceeds 20% of the current balance.

        On success, increments counter and calls base withdraw.

## What the Main Program Does

main() in Polymorphism.cpp demonstrates polymorphic behaviour using base class pointers (Account*). It:

    Creates two Savings_Account objects, stores pointers in a vector<Account*>, displays them, deposits $1000, and withdraws $200.

    Creates two Checking_Account objects, stores pointers in a vector<Account*>, displays them, deposits $1000, and withdraws $100.

    Creates three Trust_account objects, stores pointers in a vector<Account*>, displays them, deposits $1000, and withdraws $500 (testing the withdrawal limits).

All operations use the utility functions display(), deposit(), and withdraw() from Account_Util, which work with Account* and vector<Account*>.

## Building and Running
Using Visual Studio (provided .vcxproj)

    Open Polymorphism.vcxproj in Visual Studio 2022 or later.

    Select Debug or Release configuration.

    Build and run (F5).

## Using g++ (command line)
bash

g++ -std=c++17 I_Printable.cpp Account.cpp Savings_Account.cpp Checking_Account.cpp Trust_account.cpp Account_Util.cpp Polymorphism.cpp -o bank
./bank

## Example Output (Partial)
text

======Display================================
[Savings Account: MyMan with balance: 200.00$ and initiate rate: 0.00$ ]

======Display================================
[Savings Account: MyMan with balance: 200.00$ and initiate rate: 0.00$ ]
[Savings Account: MyBoy with balance: 200.00$ and initiate rate: 2.00$ ]

======Deposit================================
Deposited 1000.00$ to [Savings Account: MyBoy with balance: 200.00$ and initiate rate: 2.00$ ]

======Withdraw================================
Withdrawed 200.00$ to [Savings Account: MyBoy with balance: 1020.00$ and initiate rate: 2.00$ ]

======Display================================
[Checking Account: Unnamed Checking account with balance: 0.00$ ]
[Checking Account: BOY with balance: 2000.00$ ]

======Deposit================================
Deposited 1000.00$ to [Checking Account: Unnamed Checking account with balance: 1000.00$ ]

======Withdraw================================
Withdrawed 100.00$ to [Checking Account: BOY with balance: 1900.00$ ]

======Display================================
[Trust Account: Unnamed trust account with balance: 0.00$ ]

======Display================================
[Trust Account: Unnamed trust account with balance: 0.00$ ]
[Trust Account: Chair with balance: 7999.00$ ]
[Trust Account: Pony with balance: 5734.00$ ]

======Deposit================================
Deposited 1000.00$ to [Trust Account: Unnamed trust account with balance: 1000.00$ ]

======Withdraw================================
Withdrawed 500.00$ to [Trust Account: Unnamed trust account with balance: 500.00$ ]

(Actual output may vary depending on interest calculations and withdrawal rules.)

## Important Notes

    The Trust_account uses a non‑static counter member, so each trust account object tracks its own withdrawals independently. The limit of 3 withdrawals is per object, not global.

    The counter is not persisted between program runs – it only tracks withdrawals during the object’s lifetime.

    Polymorphism is achieved by storing Account* pointers and calling virtual deposit, withdraw, and print methods. The utility functions in Account_Util are designed to work with base class pointers, making them reusable for any derived account type.

    All deposit/withdraw operations are reported to std::cout inside the utility functions – this is convenient for demonstration but would be separated for a production application.

## License

This project is for educational purposes. Free to use and modify.