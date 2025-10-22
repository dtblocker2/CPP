Here are the notes on solving the sum of N natural numbers using recursion.

## Problem: Sum of First N Natural Numbers

The task is to find the sum of the first 'n' natural numbers.
* **Example (n=2):** $1 + 2 = 3$
* **Example (n=4):** $1 + 2 + 3 + 4 = 10$
* **Example (n=5):** $1 + 2 + 3 + 4 + 5 = 15$

(Note: A direct mathematical formula exists: $n \times (n+1) / 2$, but the goal here is to practice recursion.)

---

## The Recursive Approach 🧠

The core idea of recursion is to solve a problem using the solution to a smaller version of the same problem.

* **Recursive Idea:** We can define the sum of 'n' numbers in terms of the sum of 'n-1' numbers.
    * `Sum(n) = n + Sum(n-1)`
* **Recursive Step:** This gives us our recursive function call:
    * `getSum(n) = n + getSum(n-1)`
* **Base Case:** We must have a stopping condition to prevent infinite recursion. The smallest problem is finding the sum of 0 natural numbers.
    * `getSum(0) = 0`

---

## Execution Trace (Example: `getSum(4)`)

This shows how the function calls are "stacked" and then "unwound."

### 1. Recursive Calls (Stacking)

The function calls itself, breaking the problem down to the base case.

1.  `getSum(4)` is called. It must wait for `getSum(3)` to finish.
    * It will return `4 + getSum(3)`
2.  `getSum(3)` is called. It must wait for `getSum(2)` to finish.
    * It will return `3 + getSum(2)`
3.  `getSum(2)` is called. It must wait for `getSum(1)` to finish.
    * It will return `2 + getSum(1)`
4.  `getSum(1)` is called. It must wait for `getSum(0)` to finish.
    * It will return `1 + getSum(0)`
5.  `getSum(0)` is called.

### 2. Base Case & Unwinding (Returning)

The base case is hit, and the values are returned up the call chain.

5.  **`getSum(0)`** hits the base case (`n == 0`) and **returns 0**.
4.  `getSum(1)` gets the 0, and returns `1 + 0 =` **1**.
3.  `getSum(2)` gets the 1, and returns `2 + 1 =` **3**.
2.  `getSum(3)` gets the 3, and returns `3 + 3 =` **6**.
1.  `getSum(4)` gets the 6, and returns `4 + 6 =` **10**.

The final result, 10, is returned to the `main` function.

---

## Complexity Analysis 📊

### Time Complexity: $\Theta(n)$

* For an input `n`, the function `getSum` is called $n+1$ times (once for $n, n-1, n-2, ..., 1, 0$).
* Each function call performs a constant amount of work (one conditional check and one addition).
* The recurrence relation is $T(n) = T(n-1) + \Theta(1)$, which resolves to $\Theta(n)$.

### Auxiliary Space: $\Theta(n)$

* This space is required by the **function call stack**.
* To calculate `getSum(n)`, it must call `getSum(n-1)`, which calls `getSum(n-2)`, and so on.
* At the deepest point (when `getSum(0)` is called), there are $n+1$ function calls all waiting on the stack simultaneously.
* Because the stack grows to a size proportional to `n`, the auxiliary space complexity is $\Theta(n)$.