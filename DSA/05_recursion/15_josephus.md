Here are structured, exam-ready notes on the Josephus problem from your transcript with derivation, examples, and code.

***

### Define the Josephus problem
- You have $$n$$ people in a circle, indexed 0 to $$n-1$$.
- Starting at index 0, eliminate every $$k$$-th person in circular order.
- After each elimination, continue counting from the next person.
- Goal: return the index of the lone survivor (0-based unless noted otherwise).

### Worked examples (0-based)
- $$n=7, k=3$$: elimination order 2, 5, 1, 6, 4, 0 → survivor 3.
- $$n=4, k=2$$: elimination order 1, 3, 2 → survivor 0.
- $$n=5, k=3$$: elimination order 2, 0, 4, 1 → survivor 3.

### Derive the recurrence
- After the first elimination, the person at index $$k-1$$ dies. The next person (index $$k$$) becomes the new “0,” i.e., the circle is reindexed by a shift of $$+k$$.
- Let $$J(n,k)$$ be the survivor index for 0-based numbering.
- Base case: $$ \mathbf{J(1,k) = 0} $$.
- Shift argument: if the survivor of the reduced problem $$J(n-1,k)$$ is measured in the reindexed circle, convert it back to the original indices by adding the shift $$k$$ and wrapping modulo $$n$$.
- Recurrence: $$ \mathbf{J(n,k) = \big(J(n-1,k) + k\big) \bmod n} $$.

### Dry run for $$n=5, k=3$$
$$
\begin{aligned}
J(1,3) &= 0 \\
J(2,3) &= (0+3)\bmod 2 = 1 \\
J(3,3) &= (1+3)\bmod 3 = 1 \\
J(4,3) &= (1+3)\bmod 4 = 0 \\
J(5,3) &= (0+3)\bmod 5 = 3
\end{aligned}
$$

### Algorithms

- Recursive (direct from recurrence):
```python
def josephus_recursive(n: int, k: int) -> int:
    if n == 1:
        return 0
    return (josephus_recursive(n - 1, k) + k) % n
```

- Iterative (O(1) space, same O(n) time):
```python
def josephus_iterative(n: int, k: int) -> int:
    res = 0  # J(1,k) = 0
    for m in range(2, n + 1):
        res = (res + k) % m
    return res
```

- C++ iterative:
```cpp
int josephus(int n, int k) {
    int res = 0; // J(1,k) = 0
    for (int m = 2; m <= n; ++m) {
        res = (res + k) % m;
    }
    return res;
}
```

### Complexity
- Time: $$ \Theta(n) $$ from the recurrence $$T(n) = T(n-1) + \Theta(1)$$.
- Space: Recursive $$ \Theta(n) $$ call stack, iterative $$ \Theta(1) $$.

### Indexing variants
- 1-based answer: $$ \text{Ans}_{1\text{-based}} = J(n,k) + 1 $$.
- Arbitrary start index $$s$$ (0-based): starting from person $$s$$, survivor index in original labeling is $$ (J(n,k) + s) \bmod n $$.

### Special case $$k=2$$ (closed form)
- Write $$ n = 2^m + L $$ with $$ 0 \le L < 2^m $$.
- 0-based: $$ J(n,2) = 2L $$.
- 1-based: $$ 1 + 2L $$.
- Quick computation trick:
```python
def josephus_k2(n: int) -> int:  # 0-based
    msb = 1 << (n.bit_length() - 1)  # 2^m
    return 2 * (n - msb)
```

### Common pitfalls
- Off-by-one: in 0-based indexing the first elimination is at index $$k-1$$, but the recurrence uses a shift of $$+k$$, not $$k-1$$.
- Modulo base changes each step: always modulo current circle size $$m$$, not original $$n$$.
- Be consistent about 0-based vs 1-based answers; convert only at the end.

### Induction proof sketch
- Base: $$J(1,k)=0$$ holds.
- Inductive step: assume formula holds for $$n-1$$. After eliminating index $$k-1$$ and reindexing by a shift of $$+k$$, the survivor in the original labels is $$(J(n-1,k)+k)\bmod n$$. Hence the recurrence holds for $$n$$.

***

Would you like me to add a full induction proof with diagrams, or provide a simulator that outputs the elimination order for given n and k?