### Why prefer vectors over arrays
Vectors solve two practical issues with raw arrays:
- Dynamic size: They grow and shrink as needed, avoiding over-allocation when the final size is unknown or fluctuates.
- Safer, richer API: They carry their own size, manage memory automatically, and provide many utility operations.

### Key properties of std::vector
- Contiguous storage: elements are in one block, suitable for C APIs and SIMD; `data()` returns a pointer to the first element.
- Random access: indexing is $$O(1)$$.
- Append amortization: `push_back`/`emplace_back` are amortized $$O(1)$$ due to geometric growth.
- Value semantics: copy is $$O(n)$$ (copies/moves elements), move is $$O(1)$$ (pointer steal).

### Size, capacity, and growth
- size(): current element count.
- capacity(): allocated slots without reallocation.
- reserve(n): ensure capacity ≥ $$n$$; prevents reallocations during future appends.
- shrink_to_fit(): non-binding request to reduce capacity to near size.
- Growth factor: implementation-defined (often around 1.5–2×). Reallocation copies/moves all elements and invalidates pointers/iterators.

### Core construction and access
```cpp
#include <vector>
#include <string>

std::vector<int> a;                 // empty, size=0, capacity=0
std::vector<int> b(100);            // size=100, elements value-initialized to 0
std::vector<int> c(100, 42);        // size=100, all 42
std::vector<int> d = {1,2,3,4};     // list-initialization
int x = d[2];                       // unchecked access
int y = d.at(2);                    // bounds-checked, throws on error
int* p = d.data();                  // raw pointer to contiguous block
```

### Modifying operations
```cpp
std::vector<int> v;
v.reserve(1024);                    // pre-allocate (performance)
for (int i = 0; i < 1000; ++i) v.push_back(i);    // amortized \(O(1)\)
v.emplace_back(1001);               // constructs in-place (avoids a copy)
v.pop_back();                       // remove last, \(O(1)\)

v.insert(v.begin()+5, 99);          // \(O(n)\) shift tail
v.erase(v.begin()+5);               // \(O(n)\) shift tail
v.clear();                          // size=0, capacity unchanged
v.resize(200, -1);                  // grow with fill value or shrink
```

### Deletion patterns (stable vs unstable)
- Stable (preserve order): $$O(n)$$ shift on each erase.
- Unstable (don’t preserve order): swap-with-last then pop, $$O(1)$$.
```cpp
// Unstable removal by index i
v[i] = v.back();
v.pop_back();
```
- Erase-remove idiom (remove by value, stable):
```cpp
v.erase(std::remove(v.begin(), v.end(), 5), v.end());
```

### Passing to and returning from functions
- Don’t pass raw arrays plus separate length. Vectors store their size.
- Prefer passing by reference to avoid copies:
```cpp
void process(const std::vector<int>& v);  // read-only
void fill(std::vector<int>& v);           // mutate
std::vector<int> make_vec();              // return by value; NRVO/move makes it cheap
```

### Iterator and reference validity
- On reallocation (growth): all pointers/references/iterators become invalid.
- On insert/erase without reallocation:
  - Insert/erase at position invalidates iterators/references at and after that position.
  - `push_back` may invalidate only if growth occurs; reserve to avoid this.

### Defaults and initialization semantics
- `std::vector<int> v(100);` value-initializes 100 ints to 0.
- `v.reserve(100);` does not create elements; size stays 0.
- Contrast: raw arrays of automatic storage have indeterminate values unless explicitly initialized.

### Performance tips
- Call `reserve()` when element count is predictable to avoid multiple reallocations.
- Use `emplace_back(args...)` to construct elements in place.
- Iterate with contiguous-friendly patterns for cache efficiency.
- For real-time systems, avoid unpredictable reallocations; pre-size with `reserve` or use fixed-capacity structures (e.g., ring buffer).

### Special cases and gotchas
- `std::vector<bool>` is a packed bitset-like specialization with proxy references; avoid for performance-sensitive code; use `std::vector<char>`/`std::vector<uint8_t>` or `std::bitset`/`boost::dynamic_bitset`.
- Large contiguous allocations can fail; catch exceptions (`std::bad_alloc`) and consider chunked designs if necessary.
- `shrink_to_fit()` is non-binding; a stronger idiom:
```cpp
std::vector<int>(v).swap(v);  // force capacity drop to size
```
- Copy vs move:
```cpp
std::vector<int> a = /*...*/;
std::vector<int> b = a;             // deep copy, \(O(n)\)
std::vector<int> c = std::move(a);  // move, \(O(1)\), a becomes valid-but-empty
```

### Interop and contiguous guarantees
```cpp
extern "C" void c_api_use(double* ptr, size_t n);
std::vector<double> buf(n);
c_api_use(buf.data(), buf.size());   // safe: contiguous storage
```

### Complexity summary
| Operation | Complexity |
|---|---|
| Index access | $$O(1)$$ |
| Front/back access | $$O(1)$$ |
| push_back/emplace_back | Amortized $$O(1)$$, worst $$O(n)$$ on growth |
| pop_back | $$O(1)$$ |
| insert/erase at middle | $$O(n)$$ |
| clear | $$O(n)$$ to destroy elements; capacity unchanged |
| copy vector | $$O(n)$$ |
| move vector | $$O(1)$$ |

### Vectors vs arrays vs deque
| Aspect | Vector | Raw array | Deque |
|---|---|---|---|
| Size mutability | Dynamic | Fixed | Dynamic |
| Contiguity | Yes | Yes | No (block-chunked) |
| Random access | $$O(1)$$ | $$O(1)$$ | $$O(1)$$ |
| Fast push/pop front | No | No | Yes |
| Iterator stability on growth | Invalidated | N/A | Better than vector |
| C API interop | Excellent | Excellent | Poor |

### Extra concepts to know
- Allocators: `std::vector<T, Alloc>` allows custom memory strategies; for arena-based allocation, see `std::pmr::vector`.
- Exception safety: vector operations provide strong/basic guarantees; reallocation can throw on element copy/construct.
- SoA vs AoS: for compute kernels, a “structure of arrays” layout can improve SIMD and cache bandwidth over “array of structures”.
- Parallel algorithms: contiguous layout enables efficient use of `std::sort`, `std::reduce`, and execution policies.
- Debug vs release: bounds checks with `.at()` in hot paths can be costly; prefer `operator[]` when validated externally.