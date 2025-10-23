### Define search on arrays
Searching checks whether an element $$x$$ exists and returns its first index or $$-1$$ if absent.

- Linear search returns the first occurrence when scanning left-to-right.
- For a sorted array, binary search reduces time from $$O(n)$$ to $$O(\log n)$$.

```cpp
// Linear search (first occurrence), returns -1 if not found
int linear_search(const int* a, int n, int x) {
    for (int i = 0; i < n; ++i) if (a[i] == x) return i;
    return -1;
}
```

- Complexity (unsorted): worst-case $$O(n)$$, best-case $$O(1)$$ if found at index 0, space $$O(1)$$.
- Complexity (sorted with binary search): worst-case $$O(\log n)$$, space $$O(1)$$.

```cpp
// Binary search (first occurrence) on sorted array using lower_bound
#include <algorithm>
int first_index_sorted(const std::vector<int>& v, int x) {
    auto it = std::lower_bound(v.begin(), v.end(), x);
    return (it != v.end() && *it == x) ? int(it - v.begin()) : -1;
}
```

### Compare search strategies
| Scenario | Method | Precondition | Time | Notes |
|---|---|---|---|---|
| Unsorted array | Linear search | None | $$O(n)$$ | Returns first seen; stable wrt order |
| Sorted array | Binary search | Sorted ascending | $$O(\log n)$$ | Use lower_bound for first occurrence |
| Nearly uniform numeric keys | Interpolation search | Sorted + roughly uniform | Average $$O(\log \log n)$$, worst $$O(n)$$ | Sensitive to data distribution |
| Unknown size or infinite stream | Exponential search + binary | Sorted | $$O(\log i)$$ where $$i$$ is answer index | Finds a bound, then binary search |

### Insert in a fixed-size array
In-place insert at position pos (1-based in the transcript) requires free capacity and shifting the tail.

- Preconditions: current size $$s <$$ capacity $$C$$; target index $$i = \text{pos}-1$$ in $$0 \le i \le s$$.
- Steps:
  - Shift elements at indices $$i \ldots s-1$$ right by one.
  - Write $$x$$ at index $$i$$.
  - Increment size.

```cpp
// Insert into fixed buffer 'a' with capacity C; returns new size (or unchanged if full)
int insert_at(int* a, int s, int C, int pos1, int x) {
    if (s == C) return s;                 // full
    int i = pos1 - 1;                     // 1-based to 0-based
    if (i < 0 || i > s) return s;         // invalid position
    // shift right (use memmove for POD types)
    for (int k = s - 1; k >= i; --k) a[k + 1] = a[k];
    a[i] = x;
    return s + 1;
}
```

- Complexity: worst-case $$O(n)$$ when inserting at the beginning, best-case $$O(1)$$ at the end, space $$O(1)$$.
- For trivially copyable types, replace the loop with `memmove(&a[i+1], &a[i], (s - i) * sizeof(int));`.

### Insert at end in dynamic arrays
Dynamic arrays over-allocate and grow geometrically. Appends are **amortized** constant-time.

- Model: initial capacity $$c$$. For appends, when size equals capacity, allocate new capacity $$gc$$ with $$g>1$$, move/copy $$c$$ elements, then append.
- Amortized analysis with doubling $$g=2$$:
  - Total moves over $$n$$ appends is less than $$2n$$.
  - Average copies per append is bounded by a constant.
  - Therefore, append time is amortized $$O(1)$$, with occasional $$O(n)$$ spikes on growth.

$$
\text{Total work} \le n \text{ appends} + (1 + 2 + 4 + \dots + < n) \in O(n) \Rightarrow \text{avg} \in O(1)
$$

- Real-time caveat: the rare growth step is $$O(n)$$. Avoid in hard real-time paths; pre-reserve capacity or use fixed-capacity structures.

```cpp
std::vector<int> v;
v.reserve(1000);          // avoid growth spikes
for (int i = 0; i < 1000; ++i) v.push_back(i);  // amortized O(1)
```

### Operation complexities recap
| Operation | Fixed-size array | Dynamic array |
|---|---|---|
| Access by index | $$O(1)$$ | $$O(1)$$ |
| Linear search (unsorted) | $$O(n)$$ | $$O(n)$$ |
| Binary search (sorted) | $$O(\log n)$$ | $$O(\log n)$$ |
| Insert at end | $$O(1)$$ if space, else impossible | Amortized $$O(1)$$, worst $$O(n)$$ on growth |
| Insert at index | $$O(n)$$ | $$O(n)$$ |
| Delete at index | $$O(n)$$ | $$O(n)$$ |
| Space overhead | Minimal | Tracks size + capacity |

### Practical tips and edge cases
- Validate positions: with 1-based input, index is $$i=\text{pos}-1$$; valid when $$0 \le i \le s$$.
- Return the first occurrence for linear search by scanning left-to-right.
- When the array is full, insertion in a fixed-size buffer is impossible without reallocation.
- Prefer `std::vector::insert/erase` for safety; note both may invalidate iterators and move elements.
- Use `reserve`/`ensureCapacity` in dynamic arrays to minimize reallocations when you can estimate final size.
- In systems code, account for reallocation effects: pointers/iterators/references to elements become invalid after growth.

### Extra concepts to extend understanding
- Stable vs unstable edits:
  - Insert/delete is stable by default. For $$O(1)$$ “unstable delete” when order does not matter, swap-with-last then pop.
- Sentinel search optimization:
  - For raw loops, place a copy of $$x$$ at `a[n]` as a sentinel to remove bounds checks, then verify if found index < $$n$$. Useful in tight C loops.
- Exponential search:
  - For sorted, growing sequences or unknown bounds, first find a bound $$[2^k, 2^{k+1})$$ containing $$x$$, then binary search it in $$O(\log i)$$.
- Library nuances:
  - `std::vector::at()` does bounds checking; `operator[]` does not.
  - Growth factor is implementation-defined (e.g., ~1.5× in Java ArrayList). It does not change amortized $$O(1)$$, but affects constants.
- Memory moves:
  - For non-trivially copyable objects, insert/erase triggers element moves and constructors; consider `emplace` to construct in place.
- Cache behavior:
  - Shifts use `memmove`-like contiguous copies that are highly optimized and cache-friendly, making practical performance better than pointer-based structures for many workloads.