# Bank Account System with Smart Pointers and Exception Handling

This project is an **extension** of the previous *Inheritance* and *Polymorphism* banking examples. It builds upon the same class hierarchy (`Account` → `Savings_Account`, `Checking_Account`, `Trust_account`) but introduces:

- **Smart pointers** (`std::shared_ptr`) for automatic memory management.
- **Abstract base class** (`Account` now has pure virtual `deposit()` and `withdraw()`).
- **Interface segregation** via `I_Printable` (provides a unified `operator<<` for all account types).
- **Exception handling** – custom exceptions `NegativeBalanceException` and `InsufficentFundsException` are thrown when invalid operations occur.

The main program (`Exeption_Handling.cpp`) demonstrates polymorphic behaviour using base class pointers, while safely managing resources with `shared_ptr` and gracefully catching exceptions.

---

## Project Structure

| File | Description |
|------|-------------|
| `I_Printable.h/cpp` | Interface with pure virtual `print()` and friend `operator<<` |
| `Account.h/cpp` | Abstract base class implementing `I_Printable`; declares pure virtual `deposit`/`withdraw`; constructor throws `NegativeBalanceException` if balance < 0; `withdraw()` throws `InsufficentFundsException` if insufficient funds |
| `Savings_Account.h/cpp` | Derived class adding interest rate; overrides `deposit()` to add interest; overrides `print()` |
| `Checking_Account.h/cpp` | Derived class adding a flat fee of $1.50 per withdrawal; overrides `withdraw()` to add fee |
| `Trust_account.h/cpp` | Derived from `Savings_Account`; adds bonus $50 on deposits ≥$500; restricts withdrawals (max 3 per year, each ≤20% of balance); maintains `allowed_summ_to_withdraw` and `counter` |
| `Account_Util.h/cpp` | Utility functions for `display()`, `deposit()`, `withdraw()` working with `std::shared_ptr<Account>` and vectors thereof |
| `NegativeBalanceException.h` | Custom exception class derived from `std::exception` |
| `InsufficentFundsException.h` | Custom exception class derived from `std::exception` |
| `Exeption_Handling.cpp` | Main program – creates accounts via `make_shared`, tests operations, and catches exceptions |

---

## Class Hierarchy

I_Printable (interface)
↑
Account (abstract)
├── Savings_Account
│ └── Trust_account
└── Checking_Account
text


---

## Key Features

### `I_Printable`
- Pure virtual `void print(std::ostream&) const = 0`.
- Friend `operator<<` calls `print()`, allowing any derived object to be printed via base pointer/reference.

### `Account` (abstract)
- Stores `name` (string) and `balance` (double) as `protected` members.
- Constructor throws `NegativeBalanceException` if `balance < 0`.
- Pure virtual `deposit(double)` and `withdraw(double)` – makes the class abstract.
- `withdraw()` throws `InsufficentFundsException` if the resulting balance would be negative.
- Implements `print()` to show name and balance.

### `Savings_Account`
- Adds `int_rate` (double, percentage).
- `deposit()`: adds interest (`amount * int_rate/100`) before calling base deposit.
- `withdraw()`: directly calls base withdraw (no extra fee).

### `Checking_Account`
- No extra data members, but a flat fee of **$1.50** is applied on every withdrawal.
- `withdraw()`: adds `1.5` to the requested amount, then calls base withdraw.
- `deposit()`: simply calls base deposit.

### `Trust_account`
- Adds `counter` (size_t) – limits withdrawals to **3 per account lifetime**.
- Adds `allowed_summ_to_withdraw` (double) – stores **20% of current balance** as the maximum allowed per withdrawal.
- `deposit()`: if `amount ≥ 500`, adds a **$50 bonus** before applying interest.
- `withdraw()`:
  - Fails if `counter >= 3` (prints a message).
  - Fails if `amount > allowed_summ_to_withdraw` (prints a message).
  - On success, increments `counter` and calls base `withdraw()`.
  - Throws `InsufficentFundsException` if balance is insufficient (handled in base).

---

## What the Main Program Does

`Exeption_Handling.cpp` creates accounts using `std::shared_ptr` and `make_shared`. It tests each account type separately inside `try` blocks, catching both custom exceptions.

### Savings Account Test
- Creates `Savings_Account` with a positive balance, and one with a **negative** balance (commented out) to test `NegativeBalanceException`.
- Displays, deposits, and withdraws from the account.
- Also tests a withdrawal larger than the balance (commented out) to trigger `InsufficentFundsException`.

### Checking Account Test
- Creates a `Checking_Account`.
- Performs deposit and withdrawal (fee applied automatically).

### Trust Account Test
- Creates a `Trust_account`.
- Performs deposit (bonus applied if ≥500) and withdrawal (checks 20% limit and 3‑withdrawal rule).

All operations are performed via base class pointers (`shared_ptr<Account>`), demonstrating **polymorphism**. Utility functions in `Account_Util` work with `shared_ptr` and vectors of `shared_ptr`.

---

## Building and Running

### Using Visual Studio (provided `.vcxproj`)
- Open the `.vcxproj` file in Visual Studio 2022 or later.
- Select `Debug` or `Release` configuration.
- Build and run (F5).

### Using g++ (command line)
```bash
g++ -std=c++17 I_Printable.cpp Account.cpp Savings_Account.cpp Checking_Account.cpp Trust_account.cpp Account_Util.cpp Exeption_Handling.cpp -o bank
./bank

Example Output (Partial)
text

======Display================================
[Savings Account: Boy with balance: 200.00$ and initiate rate: 0.00$ ]

======Display================================
[Savings Account: Boy with balance: 200.00$ and initiate rate: 0.00$ ]

======Deposit================================
Deposited 1000.00$ to [Savings Account: Boy with balance: 1200.00$ and initiate rate: 0.00$ ]

======Deposit================================
Deposited 10.00$ to [Savings Account: Boy with balance: 1210.00$ and initiate rate: 0.00$ ]

======Withdraw================================
Withdrawed 200.00$ to [Savings Account: Boy with balance: 1010.00$ and initiate rate: 0.00$ ]

++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
...
======Display================================
[Checking Account: BOY with balance: 2000.00$ ]

======Deposit================================
Deposited 1000.00$ to [Checking Account: BOY with balance: 3000.00$ ]

======Withdraw================================
Withdrawed 500.00$ to [Checking Account: BOY with balance: 2498.50$ ]

...
======Display================================
[Trust Account: Pony with balance: 5734.00$ and int rate 5.60$ ]

======Deposit================================
Deposited 1000.00$ to [Trust Account: Pony with balance: 6734.00$ and int rate 5.60$ ]

======Withdraw================================
Withdrawed 500.00$ to [Trust Account: Pony with balance: 6234.00$ and int rate 5.60$ ]

(Actual output may vary depending on interest rates and withdrawal limits.)
```

# Important Notes

- Smart pointers ensure automatic memory deallocation – no manual `delete` needed.
- The `Trust_account` uses a non-static `counter` member, so each object tracks its own withdrawals independently.
- The exception handling demonstrates how to enforce business rules (non-negative balance, sufficient funds).
- This project is a direct evolution of the previous Inheritance and Polymorphism examples.

# License

This project is for educational purposes. Free to use and modify.