/* Probems using pointer */

/* Pointers are powerful — they give you direct control over memory — but with that power comes a long list of **common problems** that can cause crashes, security issues, or weird bugs.

Here’s a breakdown:

---

## **1. Dangling Pointers**

* **What happens:** You delete or free memory, but the pointer still holds the old address.
* **Problem:** Accessing it after deletion causes undefined behavior (random crashes, corrupted data).
* **Example:**

  ```cpp
  int *p = new int(5);
  delete p; // Memory freed
  *p = 10;  // ❌ Dangling pointer — dangerous
  ```

---

## **2. Memory Leaks**

* **What happens:** You `new` or `malloc` memory but never `delete` or `free` it.
* **Problem:** Over time, your program uses more and more memory until it slows down or crashes.
* **Example:**

  ```cpp
  int *p = new int[100];
  p = new int[200]; // ❌ Old memory is lost — leak
  ```

---

## **3. Wild Pointers (Uninitialized Pointers)**

* **What happens:** A pointer is declared but never initialized before use.
* **Problem:** It points to a random memory location → writing there may corrupt other variables or crash.
* **Example:**

  ```cpp
  int *p;   // ❌ Not initialized
  *p = 10;  // Writing to random memory
  ```

---

## **4. Buffer Overflows**

* **What happens:** You write outside the bounds of allocated memory.
* **Problem:** Can corrupt memory, crash program, or create security vulnerabilities.
* **Example:**

  ```cpp
  int *p = new int[5];
  p[5] = 100; // ❌ Out of bounds (valid indexes: 0–4)
  ```

---

## **5. Double Free**

* **What happens:** You call `delete` or `free` on the same pointer twice.
* **Problem:** Can cause heap corruption and unpredictable behavior.
* **Example:**

  ```cpp
  int *p = new int;
  delete p;
  delete p; // ❌ Double delete
  ```

---

## **6. Pointer Arithmetic Errors**

* **What happens:** Wrong pointer math moves you to the wrong memory address.
* **Problem:** Reading/writing garbage values or accessing invalid memory.
* **Example:**

  ```cpp
  int arr[5] = {1,2,3,4,5};
  int *p = arr;
  p = p + 10; // ❌ Moves far outside array
  ```

---

## **7. Type Mismatch**

* **What happens:** Casting between incompatible pointer types.
* **Problem:** Misinterprets memory layout → wrong values, crashes.
* **Example:**

  ```cpp
  double d = 3.14;
  int *p = (int*)&d; // ❌ Reading wrong type
  ```

---

## **8. Null Pointer Dereference**

* **What happens:** You try to access memory via a pointer set to `nullptr`.
* **Problem:** Crashes immediately (segmentation fault).
* **Example:**

  ```cpp
  int *p = nullptr;
  *p = 10; // ❌ Null pointer dereference
  ```

---

## **9. Difficult Debugging**

* Pointer bugs often cause **random, hard-to-reproduce errors** because memory corruption doesn’t always crash instantly — it may affect something far away in the program.

---

💡 **Why modern C++ avoids raw pointers for ownership**

* Use **`std::vector`** for dynamic arrays.
* Use **`std::unique_ptr`** or **`std::shared_ptr`** for automatic memory management.
* Use raw pointers only for **non-owning references** (no `delete` responsibility).

---

If you want, I can make a **visual diagram** showing how these pointer problems mess with memory — it’s much easier to understand when you see how they break the memory layout.
 */

 #include <iostream>
using namespace std;

int main() {
    // =========================================
    // 1. Dangling Pointer
    {
        cout << "\n1. Dangling Pointer Example" << endl;
        int *p = new int(5);
        delete p;  // Memory freed
        p = nullptr; // Safe practice
        // *p = 10; // ❌ Uncomment to see crash (undefined behavior)
    }

    // =========================================
    // 2. Memory Leak
    {
        cout << "\n2. Memory Leak Example" << endl;
        int *p = new int[100];
        p = new int[200]; // ❌ Old memory is lost (leak)
        delete[] p; // Only frees last allocation, leak from first one remains
    }

    // =========================================
    // 3. Wild Pointer (Uninitialized Pointer)
    {
        cout << "\n3. Wild Pointer Example" << endl;
        int *p; // ❌ Not initialized — points to random memory
        // *p = 10; // Uncomment to see potential crash
    }

    // =========================================
    // 4. Buffer Overflow
    {
        cout << "\n4. Buffer Overflow Example" << endl;
        int *p = new int[5];
        for (int i = 0; i <= 5; i++) { // ❌ 'i <= 5' writes 1 element too far
            p[i] = i * 10;
        }
        delete[] p;
    }

    // =========================================
    // 5. Double Free
    {
        cout << "\n5. Double Free Example" << endl;
        int *p = new int;
        delete p;
        // delete p; // ❌ Uncomment to see double delete issue
    }

    // =========================================
    // 6. Pointer Arithmetic Error
    {
        cout << "\n6. Pointer Arithmetic Error Example" << endl;
        int arr[5] = {1, 2, 3, 4, 5};
        int *p = arr;
        p = p + 10; // ❌ Now points way outside the array
        // cout << *p << endl; // Undefined behavior
    }

    // =========================================
    // 7. Type Mismatch
    {
        cout << "\n7. Type Mismatch Example" << endl;
        double d = 3.14;
        int *p = (int*)&d; // ❌ Wrong type interpretation
        cout << *p << " (interpreted as int)" << endl;
    }

    // =========================================
    // 8. Null Pointer Dereference
    {
        cout << "\n8. Null Pointer Dereference Example" << endl;
        int *p = nullptr;
        // *p = 10; // ❌ Uncomment to see segmentation fault
    }

    // =========================================
    // 9. Difficult Debugging
    {
        cout << "\n9. Difficult Debugging Example" << endl;
        int *p = new int[2];
        p[0] = 1;
        p[1] = 2;
        p[5] = 100; // ❌ Out-of-bounds write (might not crash now)
        delete[] p;
        cout << "Program continues... bug hidden until later" << endl;
    }

    // unintialized pointer
    // to avoid it use
    int x = 90;
    int *p;
    p = &x;

    //or
    p = (int*)0x5638;
    p = new int[5];

    // memory leak
    int *q = new int[5];

    // first delete then assign q to null
    delete []q;
    q = NULL; // 0 or you can use nullptr
    q= 0;
    q = nullptr;

    // dangling pointer
    // q is now deleted but now if we call q it will cause runtime error ie no error during compilation but during running the code
    cout<<q;

    return 0;
}
