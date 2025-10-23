### Delete operation in arrays
- Given an array and an element $$x$$, delete its **first occurrence** if present.
- After deletion, size decreases by one; capacity remains unchanged.
- To delete:
  - Search for $$x$$.
  - If found at index $$i$$, shift all elements from index $$i+1$$ to end one position left.
  - Decrease the size by one.
- If $$x$$ is not found, leave the array unchanged.

### Example
Initial array: `[5][12][20][10][6]` (size=5, capacity=5), delete $$12$$:

- Find $$12$$ at index 1.
- Shift `[20][10][6]` left by one position.
- Result: `[5, 20, 10, 6, ?]` (size=4; last element is logically ignored).

If deleting the last element (e.g., 6):

- Just reduce size by one: size=4, no shifting needed.

### Pseudocode for delete operation
```cpp
int delete_element(int* a, int n, int x) {
    int i = 0;
    // Search for x
    while (i < n && a[i] != x) ++i;
    if (i == n) return n;  // Not found, size unchanged
    // Shift elements left from i+1 to end
    for (int j = i; j < n - 1; ++j)
        a[j] = a[j + 1];
    return n - 1;  // New size
}
```

### Time complexity
- Worst-case $$\Theta(n)$$:
  - Search may scan entire array.
  - Shift up to $$n-1$$ elements.
- Best-case $$O(1)$$ when deleting the last element (just reduce size).

### Overview of operations on arrays
| Operation           | Typical Time Complexity               | Notes                              |
|---------------------|-------------------------------------|----------------------------------|
| Random access       | $$O(1)$$                           | Access/update element by index   |
| Search (unsorted)    | $$O(n)$$                           | Linear scan                      |
| Search (sorted)      | $$O(\log n)$$                      | Binary search                    |
| Insert at beginning  | $$O(n)$$                           | Shift elements right             |
| Insert at end        | $$O(1)$$ if space available        | Just place element               |
| Delete at beginning  | $$O(n)$$                           | Shift elements left              |
| Delete at end        | $$O(1)$$                          | Reduce size                     |

### Key points
- Insert/delete at the end is efficient if extra capacity exists (fixed arrays) or amortized (dynamic arrays).
- Insert/delete in middle or beginning requires element shifting, making it $$O(n)$$.
- Arrays excel at random access and cache-friendly sequential access.
- Other data structures like hash tables provide faster insert/delete/search but sacrifice cache locality and random access speed.

Would you like me to provide example code for all these operations or comparisons with other data structures next?