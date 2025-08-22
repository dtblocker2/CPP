/* The `const` qualifier in C and C++ is used to declare variables whose values cannot be changed after initialization. This is useful for protecting data from accidental modification, improving code readability, and enabling compiler optimizations.

### Basic Example

```c
#include <stdio.h>

int main() {
    const int a = 10; // 'a' is a constant, its value cannot be changed
    printf("%d\n", a);

    // a = 11; // Uncommenting this will cause a compile-time error
    return 0;
}
```
If you try to modify the value of `a` (e.g., `a = 11;`), the compiler will produce an error:  
> error: assignment of read-only variable ‘a’

### Advantages of `const`

- **Prevents Accidental Modification**: Declaring a variable as `const` ensures that its value stays the same throughout the program.[1][3][4]
- **Code Readability**: Makes it clear to other programmers that a value should not change.[5]
- **Helps in Optimization**: Compilers can optimize code knowing certain values won't change.[1][5]
- **Improves Type Safety**: Ensures that only non-modifying functions can access certain data.[3][1]

### Using `const` with Pointers

| Declaration                   | Meaning                                    | Can Change Value Pointed? | Can Change Pointer? |
|-------------------------------|--------------------------------------------|---------------------------|---------------------|
| `int *ptr`                    | Pointer to int                             | Yes                       | Yes                 |
| `const int *ptr` or `int const *ptr` | Pointer to constant int            | No                        | Yes                 |
| `int *const ptr`              | Constant pointer to int                    | Yes                       | No                  |
| `const int *const ptr`        | Constant pointer to constant int           | No                        | No                  |

- `const int *ptr;` – You can't change the value pointed by `ptr`, but can point to something else.
- `int *const ptr;` – You can't point `ptr` to another address, but can change the value at the address.
- `const int *const ptr;` – Neither the address nor the value it points to can change.[3][1]

### Practical Advice

- Use `const` for function parameters that should not be modified within the function.
- Prefer `const` over macros for constant values in code, as `const` provides type safety and scoping.

By making variables `const`, you make your intentions clear, improve code safety, and help both the compiler and other programmers avoid unnecessary errors and bugs.[4][5][1][3]

Here are all meaningful combinations of using the `const` qualifier in C++ with variables, pointers, and functions, explained with code examples and comments:

***

### 1. `const` with Variables

```cpp
const int a = 10;    // 'a' cannot be modified (read-only variable)
// a = 20; // Error!
```

***

### 2. `const` with Pointers

#### a) Pointer to `const` data

```cpp
int val1 = 5, val2 = 20;
const int* p = &val1; // data is const, pointer not const

// *p = 10; // Error! Cannot modify value through p
p = &val2; // OK: can change pointer to another address
```

#### b) `const` pointer to mutable data

```cpp
int x = 5, y = 7;
int* const q = &x; // pointer is const, data is not

*q = 42;    // OK: can modify value
// q = &y;  // Error! Cannot point to different address
```

#### c) `const` pointer to `const` data

```cpp
int z = 99;
const int* const r = &z; // both pointer and data are const

// *r = 55; // Error! Cannot modify value
// r = &y;  // Error! Cannot change address
```

#### d) `const` with pointer type equivalence

```cpp
// Both mean the same: pointer to const data
const int* s1 = &z;
int const* s2 = &z;
```

***

### 3. `const` with Function Parameters

#### a) `const` value parameter

```cpp
void fun(const int x) { 
  // x cannot be modified inside this function
}
```

#### b) `const` pointer parameter (pointer to const data)

```cpp
void print(const int* ptr) {
  // *ptr can't be modified, but ptr can point elsewhere
}
```

#### c) `const` pointer parameter (const pointer)

```cpp
void set(int* const ptr) {
  // *ptr can be changed, but ptr cannot be assigned to another address
}
```

#### d) `const` pointer to `const` data parameter

```cpp
void inspect(const int* const ptr) {
  // Neither *ptr nor ptr can be changed
}
```

***

### 4. `const` Member Functions in Classes

```cpp
class MyClass {
  int data;
public:
  int getData() const { // const guarantees this function won’t modify class members
      // data = 10; // Error!
      return data;
  }
};
```

***

### 5. `const` Objects

```cpp
class Entity {
public:
    int id;
    int getID() const { return id; }
};

const Entity myObj {42};
// myObj.id = 43; // Error! Cannot modify
```

***

### Table: `const` Use with Pointers

| Syntax                       | What is Constant?   | Example                   |
|------------------------------|---------------------|---------------------------|
| `const int* ptr`             | Data                | Cannot change *ptr        |
| `int* const ptr`             | Pointer             | Cannot change address     |
| `const int* const ptr`       | Pointer & Data      | Neither address nor value |

***

These examples cover all the main ways `const` can be combined with variables, pointers, function parameters, member functions, and objects in C++. Remember:  
- `const` before type: data is constant  
- `const` after `*`: pointer is constant  
- Both: neither the data nor the address can change.
*/