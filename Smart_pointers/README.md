# Smart Pointers Demonstration

This C++ console application demonstrates modern memory management using smart pointers (`std::unique_ptr` and `std::shared_ptr`). It creates a dynamic collection of `Test` objects managed by smart pointers, illustrating automatic resource cleanup without manual `delete`. The program also uses `auto` for type deduction and modern C++ features.

## Project Structure

| File | Description |
|------|-------------|
| `Smart_pointers.cpp` | Single‑file program containing the `Test` class and all functions: `make()`, `fill()`, `display()`, and `main()` |

## Class: `Test`

A simple class used to demonstrate object lifetime with smart pointers.

| Member | Description |
|--------|-------------|
| `int data` | Stores an integer value |
| `Test()` | Default constructor – sets `data = 0` and prints a message |
| `Test(int data)` | Parameterized constructor – sets `data` and prints a message |
| `int get_data() const` | Returns the stored value |
| `~Test()` | Destructor – prints a message showing which `data` value is being destroyed |

## Smart Pointer Usage

The program showcases three types of smart pointers:

| Smart Pointer | Purpose |
|---------------|---------|
| `std::unique_ptr<std::vector<std::shared_ptr<Test>>>` | Owns the entire vector exclusively. The vector itself holds `shared_ptr<Test>` elements. |
| `std::shared_ptr<Test>` | Used for each `Test` object inside the vector. Multiple `shared_ptr`s could theoretically point to the same `Test`, but here each element gets its own distinct object. |
| `std::make_unique` / `std::make_shared` | Creates smart pointers safely and efficiently (exception‑safe, single allocation for control block + object in `make_shared`). |

### Function Overview

| Function | Signature | Description |
|----------|-----------|-------------|
| `make()` | `auto make()` (returns `std::unique_ptr<std::vector<std::shared_ptr<Test>>>`) | Creates an empty `unique_ptr` pointing to a newly allocated vector of `shared_ptr<Test>`. Returns the pointer. Uses `auto` return type deduction. |
| `fill()` | `void fill(std::vector<std::shared_ptr<Test>>& vec, size_t num)` | Prompts the user to enter `num` integers. For each integer, creates a `shared_ptr<Test>` (using `make_shared`) and pushes it into the vector. |
| `display()` | `void display(const std::vector<std::shared_ptr<Test>>& vec)` | Iterates through the vector, calls `get_data()` on each `Test` object, prints the value along with its index, and adds a decorative line at the end. |
| `main()` | – | Calls `make()` to get the `unique_ptr`, asks the user for the number of data points, calls `fill()` and `display()`, then exits. All memory is automatically freed when `vec_ptr` goes out of scope. |

## What the Main Program Does

1. Creates a `unique_ptr` to a `vector<shared_ptr<Test>>` via `make()`.
2. Asks the user: “How many data points do you want to enter: ”
3. Calls `fill(*vec_ptr, num)` – prompts for each integer, creates `shared_ptr<Test>` objects, and stores them in the vector.
4. Calls `display(*vec_ptr)` – prints all entered values with a decorative separator before and after.
5. Ends – the `unique_ptr` goes out of scope, destroying the vector, which in turn destroys all `shared_ptr<Test>` elements. Each `shared_ptr`’s reference count drops to zero, automatically calling the destructor of each `Test` object.

## Building and Running

### Using g++ (command line)
```bash
g++ -std=c++17 Smart_pointers.cpp -o smart
./smart
```

### Using Visual Studio (without provided project file)
- Create a new Console Application project.
- Add `Smart_pointers.cpp` as the source file.
- Build and run (F5).

## Example Output

```
How many data points do you want to enter: 3
==========================================

Enter a number for data in [0] place: 42
Test constructor with data 42

Enter a number for data in [1] place: 100
Test constructor with data 100

Enter a number for data in [2] place: 7
Test constructor with data 7
==========================================
Data at segment [0]: 42
Data at segment [1]: 100
Data at segment [2]: 7
==========================================
destructor called for 42
destructor called for 100
destructor called for 7
```

(The destructor messages appear after `return 0` – when `vec_ptr` is destroyed.)

## Important Notes

- No raw `new` or `delete` are used anywhere. Memory management is fully automatic.
- `make_unique` and `make_shared` are preferred over `unique_ptr<T>(new T)` and `shared_ptr<T>(new T)` because they are exception‑safe and (for `make_shared`) more efficient.
- The `unique_ptr` owns the vector exclusively – it cannot be copied, only moved. The program does not need to move it; it simply returns and stores it.
- The `fill` function receives the vector by **non‑const reference** because it modifies the vector.
- The `display` function receives the vector by **const reference** because it only reads.
- The `make()` function uses `auto` return type deduction (C++14 and later), making the code more concise while preserving type safety.
- Each `shared_ptr<Test>` independently manages its own `Test` object. Reference counting for each pointer stays at 1 until the vector is destroyed.
- Destructor messages clearly show when each `Test` object is destroyed, confirming that there are no memory leaks.

## License

This project is for educational purposes. Free to use and modify.