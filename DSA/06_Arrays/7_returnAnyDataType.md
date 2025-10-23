Just like with `std::vector`, a standard C++ function must declare **one specific return type** in its signature (e.g., `int myFunction()` or `string myFunction()`).

To return *different* possible types from a single function, you use the exact same tools we just discussed: `std::any` or `std::variant`.

-----

## 1\. Using `std::any` (The "Dynamic" Way)

You can declare a function that returns `std::any`. This function can then return an integer, a string, a double, or any other type.

  * **Pro:** The most flexible. Truly returns "any" type.
  * **Con:** The code that *calls* the function **must know** what type to expect and cast it correctly, or the program will crash.

### `std::any` Example:

```cpp
#include <iostream>
#include <string>
#include <any>

using namespace std;

// This function's return type is 'any'
std::any getData(bool returnString) {
    if (returnString) {
        return string("Hello from function!"); // Returns a std::string
    } else {
        return 12345; // Returns an int
    }
}

int main() {
    // --- Get the string version ---
    std::any val1 = getData(true);
    // We must cast it to the type we expect (string)
    cout << "Got string: " << std::any_cast<string>(val1) << endl;


    // --- Get the int version ---
    std::any val2 = getData(false);
    // We must cast it to the type we expect (int)
    cout << "Got int: " << std::any_cast<int>(val2) << endl;

    // --- DANGER ---
    // This would crash:
    // std::any val3 = getData(false); // val3 contains an int
    // cout << std::any_cast<string>(val3); // Crash! (bad_any_cast)

    return 0;
}
```

**Output:**

```
Got string: Hello from function!
Got int: 12345
```

-----

## 2\. Using `std::variant` (The "Safer" Way)

This is the preferred modern C++ method. You define a `std::variant` that lists *all possible* types the function might return.

  * **Pro:** **Type-safe.** The compiler knows all possibilities. The calling code can safely check what type was *actually* returned.
  * **Con:** Less flexible. You must define all possible return types in advance.

### `std::variant` Example:

```cpp
#include <iostream>
#include <string>
#include <variant>

using namespace std;

// Define a type that can be EITHER an int OR a string
using IntOrString = std::variant<int, string>;

// This function MUST return one of the types in IntOrString
IntOrString getData(bool returnString) {
    if (returnString) {
        return string("Hello from function!"); // Returns a string
    } else {
        return 12345; // Returns an int
    }
}

int main() {
    IntOrString val1 = getData(true); // val1 contains a string
    IntOrString val2 = getData(false); // val2 contains an int

    // We can safely check what's inside val1
    if (std::holds_alternative<string>(val1)) {
        cout << "val1 has a string: " << std::get<string>(val1) << endl;
    }

    // We can safely check what's inside val2
    if (std::holds_alternative<int>(val2)) {
        cout << "val2 has an int: " << std::get<int>(val2) << endl;
    }
    
    // This would NOT compile, which is good!
    // double d = std::get<double>(val2); 

    return 0;
}
```

**Output:**

```
val1 has a string: Hello from function!
val2 has an int: 12345
```