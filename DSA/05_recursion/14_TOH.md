Here are the notes on the "Tower of Hanoi" recursion problem.

## Problem: Tower of Hanoi

The Tower of Hanoi is a classic puzzle that involves moving a stack of disks from one tower to another.

* **Setup:** You have three towers (pegs):
    * **A:** The source tower, holding all $n$ disks.
    * **B:** The auxiliary (helper) tower.
    * **C:** The destination tower.
* **Initial State:** $n$ disks are stacked on tower **A** in decreasing size, with the largest disk at the bottom and the smallest at the top.
* **Goal:** Move all $n$ disks from tower **A** to tower **C**, maintaining the same order.



### Rules

1.  Only **one disk** can be moved at a time.
2.  You can only move the **topmost disk** from any tower.
3.  A larger disk can **never** be placed on top of a smaller disk.

---

## Examples of Moves

* **n = 1 disk:**
    1.  Move disk 1 from A to C.
    * *(Total moves: 1)*

* **n = 2 disks:**
    1.  Move disk 1 (small) from A to B.
    2.  Move disk 2 (large) from A to C.
    3.  Move disk 1 (small) from B to C.
    * *(Total moves: 3)*

* **n = 3 disks:**
    1.  Move disk 1 from A to C.
    2.  Move disk 2 from A to B.
    3.  Move disk 1 from C to B.
    4.  Move disk 3 (large) from A to C.
    5.  Move disk 1 from B to A.
    6.  Move disk 2 from B to C.
    7.  Move disk 1 from A to C.
    * *(Total moves: 7)*

---

## The Recursive Solution

The key insight is to solve the problem by assuming you already know how to move $n-1$ disks.

To move $n$ disks from **Source (A)** to **Destination (C)** using **Auxiliary (B)**:

1.  **Step 1:** Recursively move $n-1$ disks from **Source (A)** to **Auxiliary (B)**, using Destination (C) as the new helper.
2.  **Step 2:** Move the 1 remaining disk (the $n^{th}$, largest disk) from **Source (A)** to **Destination (C)**.
3.  **Step 3:** Recursively move the $n-1$ disks from **Auxiliary (B)** to **Destination (C)**, using Source (A) as the new helper.

### Algorithm & Base Case

Let the function be `TOH(n, src, aux, dest)`:

* **Base Case: `if (n == 1)`**
    * Simply print "Move disk 1 from `src` to `dest`".
    * `return`
* **Recursive Step: `else`**
    1.  `TOH(n-1, src, dest, aux)`  *(Move n-1 from src to aux)*
    2.  `print("Move disk " + n + " from " + src + " to " + dest)` *(Move largest disk)*
    3.  `TOH(n-1, aux, src, dest)`  *(Move n-1 from aux to dest)*

Notice how the *roles* of `aux` and `dest` are swapped in the first recursive call, and the roles of `src` and `aux` are swapped in the second. The function correctly tracks which disk number to print (`n`) while reducing the problem size (`n-1`) for the recursive calls.

---

## Analysis: Number of Movements

We can define the number of moves for $n$ disks, $T(n)$, with a recurrence relation.

* $T(n)$ consists of:
    1.  Moving $n-1$ disks: $T(n-1)$
    2.  Moving the largest disk: $1$
    3.  Moving $n-1$ disks again: $T(n-1)$

* **Recurrence Relation:** $T(n) = 2 \times T(n-1) + 1$
* **Base Case:** $T(1) = 1$

If we solve this:
* $T(1) = 1$
* $T(2) = 2 \times T(1) + 1 = 2(1) + 1 = 3$
* $T(3) = 2 \times T(2) + 1 = 2(3) + 1 = 7$
* $T(4) = 2 \times T(3) + 1 = 2(7) + 1 = 15$

This reveals a clear pattern: the total number of moves for $n$ disks is **$2^n - 1$**.

The time complexity of the algorithm is therefore exponential, **$\Theta(2^n)$**, as it must perform $2^n - 1$ moves.