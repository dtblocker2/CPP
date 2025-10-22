Here are the notes from the video on counting subsets with a given sum.

## Problem: Count Subsets with Given Sum

* **Goal:** Given an array (or set) of numbers and a target `sum`, find the *count* of subsets whose elements add up exactly to that `sum`.
* **Subsets:** An array of size $n$ has $2^n$ possible subsets, including the empty set and the entire array itself.

---

## Examples

* **Example 1:**
    * `arr = {10, 5, 2, 3, 6}`
    * `sum = 8`
    * **Output: 2**
    * *Why?* The two valid subsets are `{5, 3}` and `{2, 6}`.

* **Example 2:**
    * `arr = {1, 3}`
    * `sum = 4`
    * **Output: 1**
    * *Why?* The only valid subset is `{1, 3}`.

* **Example 3:**
    * `arr = {10, 20, 15}`
    * `sum = 37`
    * **Output: 0**
    * *Why?* No combination of these numbers sums to 37.

---

## Key Corner Case: `sum = 0`

* The output will always be at least **1**.
* This is because the **empty set (`{}`)** is a valid subset of any array, and its sum is 0.

---

## The Recursive Idea (Decision Tree) 🌳

The core recursive strategy is to build a "decision tree" by processing one element at a time (the video traverses from the end of the array).

For **every element**, we have two choices:
1.  **Exclude:** We do *not* include the element in our subset.
2.  **Include:** We *do* include the element in our subset.

The total count is the sum of the results from these two branches.
`Total Count = (Count of subsets excluding the element) + (Count of subsets including the element)`

---

## Implementation: The "Remaining Sum" Trick

Instead of building all $2^n$ subset arrays (which is inefficient), we can track the `sum` we still need to find.

The recursive function `count(arr, n, sum)` will represent "the count of subsets in `arr` using the first `n` elements that add up to `sum`."

1.  **Exclude `arr[n-1]`:** We make a recursive call *without* the last element, and the target `sum` remains the same.
    * `count(arr, n-1, sum)`

2.  **Include `arr[n-1]`:** We make a recursive call *without* the last element, but we *subtract* its value from the target `sum`.
    * `count(arr, n-1, sum - arr[n-1])`

**The recursive step is the sum of these two calls.**

### Base Case (Stopping Condition)

The recursion stops when we have no more elements to consider (i.e., `n = 0`).

* If `sum == 0`: We have found a valid subset (the elements we "included" added up perfectly). **Return 1**.
* If `sum != 0`: This path was unsuccessful. **Return 0**.

These `1`s and `0`s are then added up the call stack to produce the final total count.

---

## Complexity Analysis

* **Time Complexity: $\Theta(2^n)$**
    * The function makes two new calls for each `n` elements, creating a binary recursion tree.
    * This tree has $2^n$ leaf nodes (base cases) and $2^n - 1$ internal nodes (recursive steps).
    * The total number of operations is proportional to $2^n$, which is exponential.

* **Auxiliary Space: $\Theta(n)$**
    * The space is determined by the maximum *depth* of the recursion, not the total number of calls.
    * Since we process one element at each level, the function call stack will be at most $n$ levels deep.

* **Future Optimization:** This exponential solution is a basic approach. The video notes it can be optimized using Dynamic Programming to achieve a pseudo-polynomial time complexity of $\Theta(n \times sum)$.