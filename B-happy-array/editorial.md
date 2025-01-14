# Happy Array

Happy Array is solvable in $O(n)$.

This is about $n = 10^7$ operations.

Let's try simple cases:

If $a = [-1]$, then we need two operations.

If $a = [-2]$, then we need three operations.

If $a = [-3]$, then we need four operations.

Generalizing, it makes sense that if $a = [-v]$, then we need $v+1$ operations.

What about $a$ of length two?

If $a = [-1, -1]$, then we need two operations.

- $a_0$ (0-indexed) becomes positive in two operations. $a_0$ must increase by $2$, and each operation, it increases by $1$.
- $a_1$ (0-indexed) becomes positive in one operation. $a_1$ must increase by $2$, and each operation, it increases by $2$.

We can also test on values such as $a = [-1, -3]$, $a = [-2, -1]$, $a = [-1, -3, -5]$, just to name a few arbitrary examples that cover slightly different cases.

Since the value of $a_i$ does not impact the value of $a_j$ ($i \neq j$), all values can be considered independently.

From our analysis, a reasonable conclusion is that the $i$-th index (0-indexed) takes $\lceil\frac{1-a_i}{i+1}\rceil$ operations. To justify: $a_i$ has to increase by at least $1-a_i$ to become positive, $a_i$ increases by $i+1$ each operation, and we ceiling because we must take an integer number greater than $\frac{1-a_i}{i+1}$ operations (and the smallest such integer number, for that matter).

Therefore, the answer is the maximum value of $\lceil\frac{1-a_i}{i+1}\rceil$ for all $0 \le i \le n-1$.

Note that there is one crucial caveat. Because of floating point imprecision, you MUST calculate $\lceil\frac{1-a_i}{i+1}\rceil$ as $\lfloor\frac{1-a_i-1}{i+1}\rfloor + 1$ or $\lfloor\frac{-a_i}{i+1}\rfloor + 1$. We highly recommend you memorize that, for all **positive** $y$, $\lceil\frac{x}{y}\rceil = \lfloor\frac{x-1}{y}\rfloor + 1$ (it will save you some Codeforces rounds).

Although this editorial may be verbose to justify the answer and detail the solving process, the problem can be solved fairly simply by testing values, finding the math formula, understanding the formula works, and coding.
