#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <iomanip>

using namespace std;

int main() {
    // 1. vector ==> array that dynamically manages it size depending upon no of elements
    vector<int> v = {10, 20, 30};
    cout << "Vector elements: ";
    for (int x : v) cout << x << " ";
    cout << "\nSize: " << v.size() << "\n\n";

    // 2. list
    list<int> l = {1, 2, 3, 4};
    l.push_front(0);
    l.remove(3);
    cout << "List elements: ";
    for (int x : l) cout << x << " ";
    cout << "\n\n";

    // 3. deque
    deque<int> d;
    d.push_back(10);
    d.push_front(20);
    cout << "Deque elements: ";
    for (int x : d) cout << x << " ";
    cout << "\n\n";

    // 4. set
    set<int> s = {5, 1, 4, 2, 2, 3};
    s.insert(6);
    s.erase(1);
    cout << "Set elements (unique, sorted): ";
    for (int x : s) cout << x << " ";
    cout << "\n\n";

    // 5. map
    map<string, int> age;
    age["Alice"] = 25;
    age["Bob"] = 30;
    age.erase("Bob");
    cout << "Map elements (key-value):\n";
    for (auto& p : age)
        cout << p.first << ": " << p.second << "\n";
    cout << "\n";

    // 6. unordered_set
    unordered_set<int> us = {3, 1, 4, 1, 5};
    cout << "Unordered set elements (unique, no order): ";
    for (auto x : us) cout << x << " ";
    cout << "\n\n";

    // 7. unordered_map
    unordered_map<string, int> um;
    um["x"] = 100;
    um["y"] = 200;
    cout << "Unordered map elements:\n";
    for (auto& p : um)
        cout << p.first << ": " << p.second << "\n";
    cout << "\n";

    // 8. stack
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    cout << "Stack elements popped: ";
    while(!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << "\n\n";

    // 9. queue
    queue<int> q;
    q.push(100);
    q.push(200);
    q.push(300);
    cout << "Queue elements popped: ";
    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << "\n\n";

    // 10. priority_queue
    priority_queue<int> pq;
    pq.push(10);
    pq.push(30);
    pq.push(20);
    cout << "Priority queue elements popped: ";
    while(!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << "\n\n";

    // Manipulators example
    int num = 255;
    double pi = 3.141592653589793;

    cout << "Integer output formats:\n";
    cout << "Decimal: " << dec << num << "\n";
    cout << "Hexadecimal: " << hex << num << "\n";
    cout << "Octal: " << oct << num << "\n";
    cout << dec; // back to decimal

    cout << "\nFloating-point output formats:\n";
    cout << "Default: " << pi << "\n";
    cout << fixed << setprecision(4);
    cout << "Fixed (4 decimals): " << pi << "\n";
    cout << scientific << setprecision(4);
    cout << "Scientific (4 decimals): " << pi << "\n";
    cout.unsetf(ios::fixed | ios::scientific);

    cout << "\nText alignment and width manipulators:\n";
    cout << left << setw(10) << "Left" << "|" << right << setw(10) << "Right" << "|\n";
    cout << left << setw(10) << 123 << "|" << right << setw(10) << 456 << "|\n";

    return 0;
}


/* The C++ Standard Template Library (STL) provides a set of powerful, generic template classes and functions, widely used for efficient data management and algorithms. Below is a detailed explanation of the core STL template classes, their purposes, and example codes demonstrating their use.

***

# 1. **vector**

- **Description:** Dynamic array that can resize itself automatically when elements are added or removed.
- **Use cases:** When the number of elements is unknown or changes frequently, and random access is required.
- **Key feature:** Elements stored contiguously, supports fast access by index.

### Example:

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v; // declare vector of int
    v.push_back(10); // add elements
    v.push_back(20);
    v.push_back(30);

    cout << "Vector elements: ";
    for (int x : v)
        cout << x << " ";
    cout << endl;

    cout << "Element at index 1: " << v[1] << endl;
    v.pop_back(); // remove last element
    cout << "Size after pop_back: " << v.size() << endl;
    return 0;
}
```

***

# 2. **list**

- **Description:** Doubly linked list.
- **Use cases:** When frequent insertion and deletion of elements, especially in the middle, are needed (slow random access).
- **Key feature:** Fast insert/delete at any position, but slower indexed access.

### Example:

```cpp
#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> l = {1, 2, 3, 4};

    l.push_front(0); // Add at beginning
    l.push_back(5);  // Add at end

    cout << "List elements: ";
    for (int x : l)
        cout << x << " ";
    cout << endl;

    l.pop_front(); // remove first element
    l.remove(3);   // remove element with value 3

    cout << "After removals: ";
    for (int x : l)
        cout << x << " ";
    cout << endl;
    return 0;
}
```

***

# 3. **deque**

- **Description:** Double-ended queue.
- **Use cases:** When frequent insertions/removals at both front and back are required.
- **Key feature:** Provides random access like vector, but more efficient insertions/removals at both ends.

### Example:

```cpp
#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<int> d;

    d.push_back(10);
    d.push_front(20);

    cout << "Deque elements: ";
    for (int x : d)
        cout << x << " ";
    cout << endl;

    d.pop_back();
    d.pop_front();

    cout << "Size after pops: " << d.size() << endl;
    return 0;
}
```

***

# 4. **set**

- **Description:** Sorted collection of unique elements.
- **Use cases:** When you need to store unique elements in sorted order and perform fast lookup, insertion, and deletion.
- **Key feature:** Automatically sorts elements, no duplicates allowed.

### Example:

```cpp
#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> s = {5, 1, 4, 2, 2, 3};

    cout << "Set elements (sorted, no duplicates): ";
    for (int x : s)
        cout << x << " ";
    cout << endl;

    s.insert(6);

    // Check if element exists
    if (s.find(3) != s.end())
        cout << "3 found in set" << endl;
    else
        cout << "3 not found" << endl;

    s.erase(1); // Remove element

    cout << "Set after erase: ";
    for (auto x : s)
        cout << x << " ";
    cout << endl;

    return 0;
}
```

***

# 5. **map**

- **Description:** Sorted associative container that stores key-value pairs with unique keys.
- **Use cases:** When you need fast key-based lookups with automatic sorting by keys.
- **Key feature:** Keys are unique and sorted, values can be accessed via `map[key]`.

### Example:

```cpp
#include <iostream>
#include <map>
using namespace std;

int main() {
    map<string, int> age;
    age["Alice"] = 25;
    age["Bob"] = 30;

    cout << "Alice's age: " << age["Alice"] << endl;

    for (auto& p : age)
        cout << p.first << ": " << p.second << endl;

    age.erase("Bob");

    cout << "After erasing Bob:" << endl;
    for (auto& p : age)
        cout << p.first << ": " << p.second << endl;

    return 0;
}
```

***

# 6. **unordered_set**

- **Description:** Unordered collection of unique elements, implemented as a hash table.
- **Use cases:** Fast lookup and insertion without order guarantee.
- **Key feature:** Average constant time complexity operations.

### Example:

```cpp
#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    unordered_set<int> us = {3, 1, 4, 1, 5};

    cout << "Unordered set elements: ";
    for (auto x : us)
        cout << x << " ";
    cout << endl;

    return 0;
}
```

***

# 7. **unordered_map**

- **Description:** Unordered associative container storing key-value pairs with unique keys, implemented as hash table.
- **Use cases:** Fast key-based access without sorting.
- **Key feature:** Average O(1) access time.

### Example:

```cpp
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<string, int> um;
    um["x"] = 100;
    um["y"] = 200;

    cout << "Value of x: " << um["x"] << endl;

    for (auto& p : um)
        cout << p.first << ": " << p.second << endl;

    return 0;
}
```

***

# 8. **stack**

- **Description:** Container adapter that provides LIFO (last-in, first-out) stack functionality.
- **Use cases:** When you need a simple stack for storing elements.
- **Key feature:** Supports `push`, `pop`, and `top`.

### Example:

```cpp
#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Stack top: " << st.top() << endl;
    st.pop();
    cout << "Stack top after pop: " << st.top() << endl;

    return 0;
}
```

***

# 9. **queue**

- **Description:** Container adapter for FIFO (first-in, first-out) queue.
- **Use cases:** When you need a queue for processing elements in order.
- **Key feature:** Supports `push`, `pop`, and `front/back`.

### Example:

```cpp
#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;
    q.push(100);
    q.push(200);
    q.push(300);

    cout << "Queue front: " << q.front() << endl;
    q.pop();
    cout << "Queue front after pop: " << q.front() << endl;

    return 0;
}
```

***

# 10. **priority_queue**

- **Description:** Container adapter for a max-heap (by default).
- **Use cases:** When you need the largest element quickly.
- **Key feature:** Supports `push`, `pop`, and `top`.

### Example:

```cpp
#include <iostream>
#include <queue>
using namespace std;

int main() {
    priority_queue<int> pq;
    pq.push(10);
    pq.push(30);
    pq.push(20);

    cout << "Top element (max): " << pq.top() << endl;
    pq.pop();
    cout << "Top element after pop: " << pq.top() << endl;

    return 0;
}
```

***

# Summary Table of Common STL Template Classes:

| Class           | Purpose                                         | Key Characteristics                 |
|-----------------|------------------------------------------------|------------------------------------|
| `vector`        | Dynamic array, random access                    | Fast index access, resizeable      |
| `list`          | Doubly linked list                              | Fast insert/remove anywhere        |
| `deque`         | Double-ended queue                              | Fast insert/remove front/back      |
| `set`           | Sorted collection of unique elements            | No duplicates, sorted              |
| `map`           | Sorted key-value store                           | Unique keys, sorted keys           |
| `unordered_set` | Unordered unique elements (hash table)          | Fast average operations            |
| `unordered_map` | Unordered key-value store (hash table)          | Fast average access                |
| `stack`         | LIFO stack                                      | Push/pop/top                      |
| `queue`         | FIFO queue                                      | Push/pop/front/back               |
| `priority_queue`| Max-heap priority queue                         | Always gives max element on top  |

***

If you want, I can provide deeper examples or explanations of any one container or STL algorithms that work with them! */