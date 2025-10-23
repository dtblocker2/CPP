### Detailed Notes on Checking if an Array is Sorted in Non-Decreasing Order

***

#### Problem Statement
- Given an array, determine if it is sorted in **non-decreasing order**.
- Non-decreasing order means each element is **greater than or equal to** the previous element.
- Examples:
  - Array `[1][2][15]` → Sorted
  - Array `[5][5][5][5]` → Sorted (equal allowed)
  - Single element arrays (e.g., `[10]`) → Sorted by definition
  - Array `[100][20]` → Not sorted since 100 > 20
  - Reverse sorted arrays (e.g., `[200][100]`) → Not sorted according to this definition

***

#### Naive Approach (Time Complexity: $$O(n^2)$$)
- For each element, check **all elements to its right**.
- For any element $$a_i$$, verify that no element to the right $$a_j$$ (where $$j>i$$) is smaller than $$a_i$$.
- If any such smaller-right element found, array is not sorted.
- If no violation found after checking all elements, array is sorted.

##### Example:
- Array: `[5][20][80][100]`
- $$a_0=5$$, check elements `[20][80][100]` — all greater.
- $$a_1=20$$, check elements `[80][100]` — all greater.
- $$a_2=80$$, check element `[100]` — greater.
- $$a_3=100$$, no elements to right.
- No violations found → array is sorted.

##### Algorithm:
```python
def is_sorted_naive(arr):
    n = len(arr)
    for i in range(n):
        for j in range(i+1, n):
            if arr[j] < arr[i]:   # Violation
                return False
    return True
```

##### Time Complexity:
- Worst case: $$O(n^2)$$ when array is sorted, needs complete checking.
- Best case: $$O(1)$$ when first two elements violate order.

***

#### Efficient Linear Approach (Time Complexity: $$O(n)$$)

**Key idea:**
- Traverse array once from left to right.
- For each adjacent pair $$a[i-1], a[i]$$, check if $$a[i]$$ < $$a[i-1]$$.
- If any such pair found, array not sorted → return False immediately.
- If full array traversed without violation, array is sorted → return True.

##### Algorithm:
```python
def is_sorted(arr):
    n = len(arr)
    for i in range(1, n):
        if arr[i] < arr[i-1]:    # Adjacent violation
            return False
    return True
```

##### Explanation:
- If elements up to $$i-1$$ are sorted and $$a[i]$$ < $$a[i-1]$$, array breaks sorting at $$i$$.
- Early exit reduces unnecessary checks.
- Arrays of size 0 or 1 automatically considered sorted (loop skipped).

***

#### Examples of Efficient Approach:

- Array: `[10][20][30][40]` → fully traversed, return `True`.
- Array: `[10][5][20][30]` → At i=1, 5 < 10 → early return `False`.

***

#### Comparing Time Complexities

| Approach        | Worst Case      | Best Case          | Description                  |
|-----------------|-----------------|--------------------|------------------------------|
| Naive approach  | $$O(n^2)$$     | $$O(1)$$          | Check all elements to right  |
| Efficient approach | $$O(n)$$       | $$O(1)$$           | Check adjacent pairs only    |

***

#### Space Complexity
- Both methods use constant auxiliary space: $$O(1)$$.

***

#### Additional Points
- The efficient method is most practical and widely preferred.
- The method assumes non-decreasing order (allows equal elements); strictly increasing check would use `arr[i] <= arr[i-1]` violation condition.
- Handling edge cases:
  - Empty array: considered sorted.
  - Single element: considered sorted.
- Can be applied to arrays of numbers, strings (lexicographic sort), or any comparable types.

***

#### Sample Code Snippets

**Python:**

```python
def is_sorted(arr):
    return all(arr[i] >= arr[i-1] for i in range(1, len(arr)))
```

**C++:**

```cpp
bool isSorted(const std::vector<int>& arr) {
    for (int i = 1; i < arr.size(); ++i) {
        if (arr[i] < arr[i-1])
            return false;
    }
    return true;
}
```

**Java:**

```java
boolean isSorted(int[] arr) {
    for (int i = 1; i < arr.length; i++) {
        if (arr[i] < arr[i-1])
            return false;
    }
    return true;
}
```

***

### Summary
- Problem: Check if array is sorted in non-decreasing order.
- Naive method: double loop, compare each element with all to right → $$O(n^2)$$.
- Efficient method: single loop, check adjacent pairs → $$O(n)$$.
- Early exit when violation found improves best-case runtime.
- Edge cases handle empty and single-element arrays correctly.
- This efficient linear approach is standard in practical coding.

***

If desired, additional notes on related problems such as checking for strictly increasing, decreasing, or nearly sorted lists, or identifying how close an array is to sorted can be provided.

[1](https://www.geeksforgeeks.org/dsa/time-complexities-of-all-sorting-algorithms/)
[2](https://www.wscubetech.com/resources/dsa/time-space-complexity-sorting-algorithms)
[3](https://www.boardinfinity.com/blog/time-complexity-of-sorting-algorithms/)
[4](https://www.shiksha.com/online-courses/articles/time-and-space-complexity-of-sorting-algorithms-blogId-152755)
[5](https://builtin.com/machine-learning/fastest-sorting-algorithm)
[6](https://interviewkickstart.com/blogs/learn/time-complexities-of-all-sorting-algorithms)
[7](https://www.geeksforgeeks.org/dsa/analysis-of-different-sorting-techniques/)
[8](https://en.wikipedia.org/wiki/Sorting_algorithm)
[9](https://www.bigocheatsheet.com)