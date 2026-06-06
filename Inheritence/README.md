# Bank Account Inheritance Hierarchy

This C++ console application demonstrates object-oriented programming with inheritance, polymorphism, and operator overloading. It implements a simple banking system with four account types, each with its own rules for deposits and withdrawals.

## Project Structure

| File | Description |
|------|-------------|
| `Account.h/cpp` | Base `Account` class with name, balance, deposit/withdraw methods |
| `Savings_Account.h/cpp` | Derived class that adds an interest rate; deposit adds interest |
| `Checking_Account.h/cpp` | Derived class that adds a flat fee of $1.50 per withdrawal |
| `Trust_account.h/cpp` | Derived from `Savings_Account`; gives bonus $50 on deposits ≥$500, and restricts withdrawals (max 3 per year, each ≤20% of balance) |
| `Account_Util.h/cpp` | Utility functions to operate on vectors of accounts (display, deposit, withdraw) and on single accounts |
| `Inheritence.cpp` | Main program – tests all account types (Account, Savings_Account, Trust_account, Checking_Account) |

## Class Hierarchy

Account
├── Savings_Account
│ └── Trust_account
└── Checking_Account
text


### Class Features

#### `Account`
- Stores `name` (string) and `balance` (double).
- `deposit(amount)`: adds positive amount.
- `withdraw(amount)`: subtracts amount if sufficient funds.

#### `Savings_Account` (inherits `Account`)
- Adds `int_rate` (double, percentage).
- `deposit(amount)`: adds interest before calling base deposit:  
  `amount += amount * (int_rate/100)`.

#### `Checking_Account` (inherits `Account`)
- No extra data member, but flat fee `1.5` per withdrawal.
- `withdraw(amount)`: adds `1.5` to the amount, then calls base withdraw.

#### `Trust_account` (inherits `Savings_Account`)
- Overrides `deposit`: if amount ≥ 500, adds extra $50 bonus.
- Overrides `withdraw` with two restrictions:
  - No more than **3 withdrawals** per account (the `counter` member is non‑static, so each account tracks its own withdrawals).
  - Each withdrawal cannot exceed **20%** of the current balance.
- After a successful deposit, the utility function prints the minimal allowed withdrawal amount (`balance * 0.2`).

## What the Main Program Does

The `main()` function in `Inheritence.cpp` sequentially:

1. Creates a `vector<Account>` with 4 accounts, displays them, deposits $1000 to all, deposits another $1000 to the 4th account (`Curly`), and withdraws $100 from the first account.
2. Creates a `vector<Savings_Account>` with 4 accounts (different interest rates), displays them, deposits $1000 to all, deposits another $1000 to the 3rd account (`Batman`), and withdraws $100 from the first account.
3. Creates a `vector<Trust_account>` with 4 accounts, displays them, deposits $1000 to all, deposits another $1000 to the 2nd account (`MRBALL`), then performs multiple withdrawals to test the 3‑withdrawal limit and the 20% rule.
4. Creates a `vector<Checking_Account>` with 3 accounts, displays them, deposits $1000 to all, deposits another $1000 to the 2nd account, then withdraws $500 from all and again from the 2nd account individually.

All utility functions (`display`, `deposit`, `withdraw`) are overloaded for vectors and single accounts of each specific type.

## Building and Running

### Using Visual Studio (provided `.vcxproj`)
- Open `Inheritence.vcxproj` in Visual Studio 2022 (or later).
- Select `Debug` or `Release` configuration.
- Build and run (F5).

### Using g++ (command line)
```bash
g++ -std=c++17 Account.cpp Account_Util.cpp Savings_Account.cpp Trust_account.cpp Checking_Account.cpp Inheritence.cpp -o bank
./bank

Example Output (Partial)
text

=== Accounts ==========================================
[Account: Unnamed Account: 0.00]
[Account: Larry: 0.00]
[Account: Moe: 2000.00]
[Account: Curly: 5000.00]

=== Depositing to Accounts =================================
Deposited 1000.00 to [Account: Unnamed Account: 1000.00]
Deposited 1000.00 to [Account: Larry: 1000.00]
Deposited 1000.00 to [Account: Moe: 3000.00]
Deposited 1000.00 to [Account: Curly: 6000.00]

=== Depositing to Accounts ==========================
Deposited 1000.00 to [Account: Curly: 7000.00]

=== Withdrawing from Accounts ==============================
Withdrew 100.00 from [Account: Unnamed Account: 900.00]
...
=== Trust Accounts ====================================
[Trust_Account: Unnamed trust account: 0.00, 0.00%] Minimal withdraw sum for you is: 0.00$
[Trust_Account: MRBALL: 0.00, 0.00%] Minimal withdraw sum for you is: 0.00$
[Trust_Account: GANDON: 2000.00, 0.00%] Minimal withdraw sum for you is: 400.00$
[Trust_Account: Markplier: 5000.00, 2.00%] Minimal withdraw sum for you is: 1000.00$

=== Depositing to Trust Accounts ==========================
Deposited 1000.00 to [Trust_Account: Unnamed trust account: 1000.00, 0.00%] Now, minimal withdraw sum for you is: 200.00$
Deposited 1000.00 to [Trust_Account: MRBALL: 1000.00, 0.00%] Now, minimal withdraw sum for you is: 200.00$
Deposited 1000.00 to [Trust_Account: GANDON: 3000.00, 0.00%] Now, minimal withdraw sum for you is: 600.00$
Deposited 1000.00 to [Trust_Account: Markplier: 6000.00, 2.00%] Now, minimal withdraw sum for you is: 1200.00$

... (further output shows withdrawal attempts and the 3‑withdrawal limit)

Important Notes

    The Trust_account uses a non‑static counter member (declared as size_t counter {}; in the header). This means every trust account object has its own withdrawal counter. The limit of 3 withdrawals is per object, not global.

    The counter is not persisted between program runs – it only tracks withdrawals during the object’s lifetime.

    The provided code does not use virtual functions, so the utility functions rely on compile‑time overloading for the correct account type. This works because each vector holds objects of a specific derived type. For polymorphic behaviour, you would need base class pointers and virtual methods.

    All deposit/withdraw operations are reported to std::cout directly inside the utility functions – this is convenient for demonstration but could be separated for a real application.

## License

This project is for educational purposes. Free to use and modify.