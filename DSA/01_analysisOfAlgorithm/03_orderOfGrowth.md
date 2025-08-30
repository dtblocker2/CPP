Here’s a **clear and structured note summary** for the transcript you shared on **Order of Growth**:

---

# 📘 Notes on **Order of Growth**

### 🔹 Purpose

* Given a problem with **multiple solutions**, we need to decide **which solution is more efficient**.
* Method:

  1. Write the **time functions** (polynomials) for each solution.
  2. Compare their **order of growth**.
  3. The solution with the **least order of growth** is considered efficient.

---

### 🔹 Comparing Orders of Growth

* A function **f(n)** grows faster than **g(n)** if:

  $$
  \lim_{n \to \infty} \frac{g(n)}{f(n)} = 0
  $$

* Interpretation:

  * If **f(n)** grows faster → algorithm with **f(n)** is **less efficient (bad)**.
  * If **g(n)** grows slower → algorithm with **g(n)** is **better**.

* **Always analyze for large n (n → ∞)**.

* Practical exceptions (like small input ranges) are ignored in asymptotic analysis.

---

### 🔹 Example: Constants vs Growth

* Let:

  * $f(n) = n + 1$ (linear)
  * $g(n) = 1000$ (constant)

* For **small n ≤ 999**, $f(n) < g(n)$.

* For **large n > 999**, $f(n) > g(n)$.

* Asymptotically:

  * $f(n)$ grows unbounded → **higher order of growth**.
  * Thus, $f(n)$ is **less efficient** than constant $g(n)$.

---

### 🔹 Example: Quadratic vs Linear

* $f(n) = n^2 + n + 6$
* $g(n) = 2n + 5$

$$
\frac{g(n)}{f(n)} = \frac{2n+5}{n^2+n+6}
$$

* Divide numerator and denominator by $n^2$:

  $$
  \frac{\frac{2}{n} + \frac{5}{n^2}}{1 + \frac{1}{n} + \frac{6}{n^2}} \to 0 \quad \text{as } n \to \infty
  $$

* ⇒ $f(n)$ grows faster (quadratic > linear).

* ⇒ Algorithm with $f(n)$ is **worse**.

---

### 🔹 Direct Way to Find Order of Growth

1. **Ignore lower order terms** (e.g., constants, smaller powers).
2. **Ignore constants of leading terms**.
3. What remains = **order of growth**.

#### Examples

* $f(n) = 2n^2 + n + 6$ → Order = $n^2$ (**quadratic**)
* $g(n) = 100n + 50$ → Order = $n$ (**linear**)

---

### 🔹 Growth Hierarchy (in increasing order)

$$
1 \;<\; \log\log n \;<\; \log n \;<\; n^{1/3} \;<\; \sqrt{n} \;<\; n \;<\; n \log n \;<\; n^2 \;<\; n^3 \;<\; 2^n \;<\; n^n
$$

* **Constants grow slowest**, **exponentials grow fastest**.
* Use this sequence to compare two functions quickly.

---

### 🔹 Comparison Examples

1. $f(n) = \log n$, $g(n) = n$

   * Order: $\log n < n$ → **g(n) worse**.

2. $f(n) = n^2$, $g(n) = n \log n$

   * Cancel one $n$: compare $n$ vs $\log n$.
   * $n > \log n$ → $f(n)$ worse.

---

### ✅ Key Takeaways

1. **Ignore constants and lower terms** → only the leading term matters.
2. **Higher order of growth = worse efficiency**.
3. Always analyze for **large input sizes (n → ∞)**.
4. Growth hierarchy helps quickly compare complexities.

---

⚡ Do you want me to also make a **cheat sheet table** (functions vs their Big-O) with some **graph sketches** of growth rates (like O(1), O(log n), O(n), O(n²), O(2^n)) for quick revision?
