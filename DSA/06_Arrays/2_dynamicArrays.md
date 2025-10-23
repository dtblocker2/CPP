### Classify array types
Arrays can be classified by whether their size can change after creation.

- Fixed-size arrays: capacity is set at allocation and cannot grow.
- Dynamic arrays: capacity expands automatically as elements are appended.

### Fixed-size arrays in C and C++
- Stack-allocated, compile-time size:
  ```cpp
  int a[100];                // C/C++, size known at compile time
  ```
- Heap-allocated, runtime size:
  ```cpp
  int* p = (int*)malloc(n * sizeof(int));  // C
  int* q = new int[n];                     // C++
  // remember: free(p); and delete[] q;
  ```
- Aggregate initialization (size inferred):
  ```cpp
  int b[] = {1, 2, 3, 4};   // size is 4
  ```
- Modern fixed array wrapper:
  ```cpp
  std::array<int, 100> a{}; // C++, fixed size, stack or embedded
  ```
- Important caveat:
  - C++ does not support Variable Length Arrays (VLAs) in the standard; code like:
    ```cpp
    int n; std::cin >> n;
    int a[n]; // non-standard (GCC extension), avoid in portable C++
    ```
    Use `std::vector<int> a(n);` instead.
  - C (C99) added VLAs for stack allocation, but they are optional in later standards and can risk stack overflows for large n.

### Java arrays and ArrayList
- Arrays are always heap objects:
  ```java
  int[] a = new int[100];
  int[] b = {1, 2, 3, 4};
  ```
- Arrays have fixed length `a.length` and default-initialize elements to zeros or nulls.
- Dynamic array wrapper:
  ```java
  ArrayList<Integer> list = new ArrayList<>();
  list.add(42);
  list.ensureCapacity(100); // optional capacity hint
  ```
- Prefer `int[]` over `ArrayList<Integer>` when avoiding boxing of primitives is important for performance and memory.

### Python lists and typed arrays
- Python list is a dynamic array of object references:
  ```python
  a = [0]*4
  a.append(5)
  ```
- Lists grow with over-allocation to keep appends amortized $$O(1)$$.
- For dense numeric data:
  ```python
  import array
  arr = array.array('i', [1,2,3,4])  # typed, compact
  ```
- For large numeric workloads, use NumPy arrays (contiguous, homogeneous, vectorized).

### Fixed vs dynamic arrays
| Aspect | Fixed-size array | Dynamic array |
|---|---|---|
| Capacity | Fixed at creation | Grows automatically |
| Append at end | Not possible beyond capacity | Amortized $$O(1)$$ |
| Insert/delete middle | $$O(n)$$ with shifting | $$O(n)$$ with shifting |
| Index access | $$O(1)$$ | $$O(1)$$ |
| Memory layout | Contiguous | Contiguous; may relocate on growth |
| Typical APIs | C/C++ raw arrays, `std::array`, Java `T[]` | C++ `std::vector`, Java `ArrayList`, Python `list` |

### How dynamic arrays grow internally
- Strategy:
  - Keep a buffer with logical size $$s$$ and capacity $$c$$.
  - On append when $$s=c$$, allocate a new buffer with capacity $$c' = g \cdot c$$ where $$g>1$$ (commonly around 1.5–2), copy/move $$c$$ elements, then append.
- Amortized analysis:
  - Total number of element copies over $$n$$ appends is bounded by a geometric series, so average copies per append is constant.
  - A simple bound when doubling each time: total moves < $$2n$$ ⇒ amortized append cost $$O(1)$$.
- Practical notes:
  - Growth factor is implementation-specific: C++ `std::vector` does not specify $$g$$; Java `ArrayList` often grows by ~1.5×; Python `list` uses an over-allocation heuristic.
  - Resizing invalidates raw pointers/iterators/references into the array in C++; in Java, the `ArrayList` object stays, but its internal array reference changes.

### Memory placement and lifetime
- Stack vs heap (C/C++):
  - Stack arrays have automatic lifetime, fast allocation, but limited size and risk of stack overflow.
  - Heap arrays support large sizes and dynamic lifetimes; manage with `delete[]`/`free()` or prefer RAII containers (`std::vector`, `std::array`).
- Java:
  - All arrays are heap objects, managed by GC.
- Python:
  - Objects and internal buffers are heap-managed with reference counting/GC.

### Core operations and complexities
- Indexing: $$O(1)$$.
- Sequential iteration: $$O(n)$$ and cache-friendly due to contiguity.
- Search unsorted: $$O(n)$$.
- Search sorted with binary search: $$O(\log n)$$.
- Append at end:
  - Fixed-size: not allowed past capacity.
  - Dynamic: amortized $$O(1)$$, occasional $$O(n)$$ on resize.
- Insert/delete at position $$i$$: $$O(n)$$ due to shifting tail elements.
- Remove last (pop back): $$O(1)$$ on dynamic arrays.

### Capacity management tips
- C++:
  ```cpp
  std::vector<int> v;
  v.reserve(100000);    // pre-allocate to avoid multiple reallocations
  v.shrink_to_fit();    // non-binding request to reduce capacity
  ```
- Java:
  ```java
  ArrayList<int[]> list = new ArrayList<>();
  list.ensureCapacity(100000);
  ```
- Python:
  - No explicit reserve API; appends are already amortized $$O(1)$$. Prefer `list.extend(iterable)` for batch growth.

### Multidimensional and jagged arrays
- Contiguous 2D in C/C++:
  ```cpp
  int M=3, N=4;
  std::vector<int> A(M*N);
  auto idx = [&](int i, int j){ return i*N + j; };
  A[idx(2,3)] = 7;  // row-major layout
  ```
- `std::vector<std::vector<int>>` and Python `list[list[int]]` are jagged; only each row is contiguous.
- Java `int[][]` is an array of arrays (jagged), not a single contiguous block.

### Performance and systems considerations
- Cache locality: contiguous layout improves spatial locality and enables hardware prefetching.
- Alignment: aligned arrays can improve SIMD throughput on numeric workloads.
- Real-time systems: a resize can cause an unbounded pause; pre-size with `reserve`/`ensureCapacity` or use a fixed-capacity ring buffer.
- Large allocations: need a single contiguous block; fragmentation can cause allocation failures despite available total memory.

### Language-specific gotchas
- C/C++:
  - Out-of-bounds access is undefined behavior; no bounds checks on raw arrays or `std::vector::operator[]`.
  - Use `at()` for bounds-checked access when safety matters.
  - Prefer `std::vector`/`std::array` over raw `new[]`/`delete[]`.
- Java:
  - Arrays have a fixed `length`; `ArrayIndexOutOfBoundsException` on invalid indices.
  - `ArrayList<Integer>` boxes primitives; prefer `int[]` or specialized primitive collections for performance.
- Python:
  - `list.insert(0, x)` and `pop(0)` are $$O(n)$$; use `collections.deque` for fast operations at both ends.
  - Lists hold references; storing many small numbers has overhead. Use `array` or NumPy for compact numeric storage.

### Extra concepts to deepen understanding
- Size vs capacity: dynamic arrays track logical size and reserved capacity; managing capacity reduces reallocations.
- Stable vs unstable deletion:
  - Stable delete maintains order but costs $$O(n)$$.
  - Unstable delete can be $$O(1)$$ by swap-with-last then pop when order is irrelevant.
- Structure of Arrays (SoA) vs Array of Structures (AoS):
  - SoA can improve vectorization and cache efficiency when processing one field at a time.
- Slicing and views:
  - C++: views via `std::span` avoid copies.
  - Python: list slicing creates copies; NumPy slicing returns views without copying.
- Iterator/reference stability:
  - `std::vector` invalidates on growth; `std::deque` has different guarantees; choose accordingly.

### Quick, idiomatic examples
- C++ dynamic array usage:
  ```cpp
  std::vector<int> v;
  v.reserve(1024);
  for (int i = 0; i < 1000; ++i) v.push_back(i);
  // safe, checked access
  int x = v.at(10);
  ```
- Java dynamic array usage:
  ```java
  ArrayList<Integer> list = new ArrayList<>(1024);
  for (int i = 0; i < 1000; i++) list.add(i);
  int x = list.get(10);
  ```
- Python dynamic array usage:
  ```python
  a = []
  a.extend(range(1000))
  x = a[10]
  ```