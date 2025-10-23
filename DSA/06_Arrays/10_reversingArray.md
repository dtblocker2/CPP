### Detailed Notes on Reversing an Array In-Place

***

#### Problem Overview
- Given an array, the task is to **reverse its elements** in-place.
- After reversal, the first element becomes the last, the second becomes the second last, etc.
- Example:
  - Input: `[10][5][7][30]`
  - Output: `[30][7][5][10]`
- Reversal modifies the input array directly without using extra space for another array.

***

#### Approach — Two Pointer Technique

- Maintain two pointers:
  - `low` initialized to the first index (0).
  - `high` initialized to the last index (n-1).
- Swap the elements at `low` and `high`.
- Move `low` forward by 1 and `high` backward by 1 to narrow the window.
- Continue swapping until `low` meets or crosses `high`.
- Terminate loop when pointers meet or cross.

***

#### Step-by-Step Example

Initial Array: `[10][5][7][30]`

- `low = 0`, `high = 3`
- Swap elements at index `0` and `3`: swap `10` and `30`
- Array becomes `[30][5][7][10]`
- Increment `low` to `1`, decrement `high` to `2`

- `low = 1`, `high = 2`
- Swap elements `5` and `7`
- Array becomes `[30][7][5][10]`
- Increment `low` to `2`, decrement `high` to `1`

- Now `low > high` → stop.

Result: `[30][7][5][10]` (Reversed array)

***

#### Handling Odd-Even Number of Elements

- Odd length example: `[37][6][5][10][7]`
- Swapping first-last and second-second_last works similarly.
- Middle element remains in place once `low == high`.

***

#### Pseudocode

```pseudo
function reverseArray(arr, n):
  low = 0
  high = n - 1
  while low < high:
    swap(arr[low], arr[high])
    low = low + 1
    high = high - 1
```

***

#### Time Complexity
- Each iteration swaps two elements and moves pointers closer.
- Loop runs approximately $$ \frac{n}{2} $$ times.
- Time complexity is $$ \Theta(n) $$.

***

#### Space Complexity
- Only a few variables (`low`, `high`, temporary variable for swap).
- Constant extra space $$ \Theta(1) $$.

***

#### Key Takeaways
- In-place reversal requires no extra space.
- Two-pointer method uses swaps and converging indices.
- Efficient and simple to implement.
- Works with any array size (empty, single-element, odd/even length).
- Avoids overhead of creating auxiliary arrays.

***

#### Sample Code Snippets

**C++**

```cpp
void reverseArray(int arr[], int n) {
    int low = 0, high = n - 1;
    while (low < high) {
        int temp = arr[low];
        arr[low] = arr[high];
        arr[high] = temp;
        low++;
        high--;
    }
}
```

**Java**

```java
void reverseArray(int[] arr) {
    int low = 0, high = arr.length - 1;
    while (low < high) {
        int temp = arr[low];
        arr[low] = arr[high];
        arr[high] = temp;
        low++;
        high--;
    }
}
```

**Python**

```python
def reverse_array(arr):
    low, high = 0, len(arr) - 1
    while low < high:
        arr[low], arr[high] = arr[high], arr[low]
        low += 1
        high -= 1
```

***

#### Additional Notes

- Many languages like JavaScript, Python offer built-in `.reverse()` methods that reverse in-place.
- For immutable sequences (like strings), reversal returns a new reversed sequence.
- The reversal technique is foundational for more advanced algorithms, such as rotation of arrays.
- Variants exist for reversing a subarray by changing the bounds of `low` and `high`.

***

### Summary

Reversing an array in place is an efficient, linear time algorithm using two pointers and swaps, requiring constant extra space. It is a fundamental operation widely used in various algorithmic problems.

If you would like, detailed examples on array rotations or string reversal related to this can also be provided.

[1](https://www.geeksforgeeks.org/dsa/program-to-reverse-an-array/)
[2](https://www.geeksforgeeks.org/dsa/program-for-array-rotation-continued-reversal-algorithm/)
[3](https://stackoverflow.com/questions/22977859/reversing-an-array-in-place)
[4](https://takeuforward.org/data-structure/reverse-a-given-array/)
[5](https://www.scaler.com/topics/reverse-an-array-in-java/)
[6](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/reverse)
[7](https://youcademy.org/reverse-an-array/)
[8](https://afteracademy.com/blog/reverse-an-array)
[9](https://www.youtube.com/watch?v=QyzcvkZgPxE)