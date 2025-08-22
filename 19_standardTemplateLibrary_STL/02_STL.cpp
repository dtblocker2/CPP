#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <deque>
#include <queue>
#include <stack>
#include <set>

using namespace std;

int main() {
    // 1. vector - dynamic array, fast random access
    vector<int> v = {1, 2, 3};
    v.push_back(4);
    cout << "Vector elements: ";
    for (int x : v) cout << x << " ";
    cout << "\n";

    // 2. list - doubly linked list, fast insertion/removal anywhere
    list<int> lst = {10, 20, 30};
    lst.push_front(5);
    lst.remove(20);
    cout << "List elements: ";
    for (int x : lst) cout << x << " ";
    cout << "\n";

    // 3. forward_list - singly linked list, less memory, no size(), fast insert after/before head
    forward_list<int> fl = {100, 200, 300};
    fl.push_front(50);
    fl.remove(200);
    cout << "Forward List elements: ";
    for (int x : fl) cout << x << " ";
    cout << "\n";

    // 4. deque - double-ended queue, fast insert/remove at both ends, random access
    deque<int> dq;
    dq.push_back(7);
    dq.push_front(3);
    cout << "Deque elements: ";
    for (int x : dq) cout << x << " ";
    cout << "\n";

    // 5. priority_queue - max heap by default, fast access to largest element
    priority_queue<int> pq;
    pq.push(30);
    pq.push(10);
    pq.push(20);
    cout << "Priority queue elements popped: ";
    while (!pq.empty()) {
        cout << pq.top() << " "; // largest element
        pq.pop();
    }
    cout << "\n";

    // 6. stack - LIFO container adapter, push/pop/top operations only
    stack<int> st;
    st.push(5);
    st.push(15);
    st.push(10);
    cout << "Stack elements popped: ";
    while(!st.empty()) {
        cout << st.top() << " "; // last inserted element
        st.pop();
    }
    cout << "\n";

    // 7. set - sorted unique elements, fast search/insert/delete
    set<int> s = {4, 2, 7, 4, 2}; // duplicates ignored
    s.insert(5);
    cout << "Set elements (unique, sorted): ";
    for (int x : s) cout << x << " ";
    cout << "\n";

    // 8. multiset - sorted elements, duplicates allowed
    multiset<int> ms = {4, 2, 7, 4, 2};
    ms.insert(5);
    cout << "Multiset elements (duplicates allowed): ";
    for (int x : ms) cout << x << " ";
    cout << "\n";

    return 0;
}

/* 
Here is a summary of the **time complexity costs** for insertion, deletion, and sorting (if applicable) for the STL containers you asked about:

| Container       | Insertion Cost                              | Deletion Cost                              | Sorting Cost                          |
|-----------------|--------------------------------------------|--------------------------------------------|-------------------------------------|
| **vector**      | Amortized O(1) at end, O(n) at arbitrary position | O(n) at arbitrary position (shifts elements) | N/A (elements kept in insertion order, can call std::sort: O(n log n)) |
| **list**        | O(1) at known position (front/back/iterator)     | O(1) at known position (front/back/iterator)  | N/A (elements are not contiguous; can call list.sort() with O(n log n)) |
| **forward_list**| O(1) at front or after a known element            | O(1) at front or after a known element        | N/A (supports forward_list.sort() in O(n log n))                  |
| **deque**       | O(1) at front or back                               | O(1) at front or back                               | N/A (like vector, can use std::sort on iterators, O(n log n))     |
| **priority_queue** | O(log n) for insertion (push)                   | O(log n) for deletion (pop)                        | N/A (no direct sorting; internally maintained heap)               |
| **stack**       | O(1) push                                        | O(1) pop                                           | N/A (no sorting; LIFO container)                                  |
| **set**         | O(log n) insertion (balanced BST)                | O(log n) deletion (balanced BST)                   | N/A (kept sorted always)                                          |
| **multiset**    | O(log n) insertion (balanced BST)                | O(log n) deletion (balanced BST)                   | N/A (kept sorted always)                                          |

***

### Notes:

- For **vector**, inserting/removing elements in the middle or front requires shifting subsequent elements — O(n).
- **list** and **forward_list** allow fast O(1) insertion and deletion at known positions via iterators.
- **deque** provides O(1) insertion and deletion at both ends, but O(n) in the middle.
- **priority_queue** maintains a heap structure — inserting/deleting elements takes O(log n).
- **stack** is a wrapper around another container (usually vector or deque) and supports only LIFO operations, O(1).
- **set** and **multiset** are implemented as balanced binary search trees, providing O(log n) insert and delete, always sorted.
- Sorting is not applicable to containers that maintain sorted order internally (`set`, `multiset`) or container adapters without random access (`stack`, `priority_queue`).
- For containers with random access iterators (`vector`, `deque`), `std::sort()` runs in O(n log n).

Let me know if you want more detailed example performance analysis!
*/