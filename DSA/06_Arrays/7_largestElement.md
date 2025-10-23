### Problem: Find the index of the largest element in an array

***

### Naive approach (time complexity: $$O(n^2)$$)
- For each element, compare it with all other elements.
- If no element is greater than the current element, return its index.
- Otherwise, continue checking.
- This approach uses nested loops:
  - Outer loop runs $$n$$ times.
  - Inner loop runs up to $$n$$ times for each outer iteration.
- Inefficient because of repeated comparisons.

### Example analysis of naive approach
- Array: 
- Check 5: compared with 8 (greater → discard 5)
- Check 8: compared with 20 (greater → discard 8)
- Check 20: no element greater → 20 is largest
- Return index 2

### Efficient approach (time complexity: $$\Theta(n)$$)
- Traverse the array once.
- Track the index of the largest element found so far.
- For each element at index $$i$$, compare with element at the largest index.
- If current element is greater, update the largest index.
- At end, return the largest index.

### Explanation
- This leverages the idea that the maximum can be found by incremental comparison.
- For a stream of data, given the maximum of first $$i-1$$ elements, the maximum including the $$i^{th}$$ element can be found in $$O(1)$$ time by comparing elements at indexes.
- Total time complexity: $$\Theta(n)$$, best and worst case the same.
- Space complexity: $$O(1)$$ (only an index stored).

### Example walk-through
- Array: 
- Start result = 0 (index of 5)
- i=1: 8 > 5 → result = 1
- i=2: 20 > 8 → result = 2
- i=3: 10 < 20 → result remains 2
- Return 2

### C++/Java code structure (efficient solution)

```cpp
// C++ version
int getLargestIndex(int arr[], int n) {
    int largest = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[largest]) {
            largest = i;
        }
    }
    return largest;
}
```

```java
// Java version
int getLargestIndex(int[] arr) {
    int largest = 0;
    for (int i = 1; i < arr.length; i++) {
        if (arr[i] > arr[largest]) {
            largest = i;
        }
    }
    return largest;
}
```

### Key points:
- Always initializes largest at index 0 assuming array size > 0.
- No need to check if array is empty (can add safety if needed).
- No early break; entire array must be traversed.
- Always returns the index of the **first occurrence** of the largest element.

### Time complexity analysis:
- Linear time $$\Theta(n)$$.
- Every element visited once.
- No nested loops, constant extra space.

### Summary:  
The efficient one-pass solution outperforms the naive $$O(n^2)$$ approach with much better scalability for large arrays.

Would you like me to explain common variations, such as finding second largest or largest value itself?