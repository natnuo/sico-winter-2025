# Digit Product

Digit Product I is solvable in $O\left(r \log_{10}r\right)$ using brute force.

This is about $r \log_{10} r = 6 \cdot 10^6$ operations.

1. Define a count.
2. Iterate every $v$ in $(l, r]$. For each $v$:
   1. Find the digit product.
   2. Increment the count if the digit product is in $[x, y]$.
3. Output the count.

---

Digit Product IV is solvable in $O\left(y \log_{10}r\right)$ using DP. Specifically what DP?

<details><summary>Think</summary>

Digit DP.

We choose Digit DP because the problem mentions finding all numbers within some bounds ($[l+1, r]$) with some property (digit product in $[x, y]$), the classic format of a Digit DP problem.

This is about $y \log_{10}r = 7 \cdot 10^5$ operations.

To find the transitions of the Digit DP, we want to begin with simple cases.

Let $ans(l, r, x, y)$ output the correct answer given the arguments. Can you simplify this calculation into a format better analyzed in DP? Maybe by reducing the first and third arguments to zero?

<details><summary>Think</summary>

**Simplification:**

$ans(l, r, x, y)$
$= ans(0, r, x, y) - ans(0, l, x, y)$
$= (ans(0, r, 0, y) - ans(0, r, 0, x-1)) - (ans(0, l, 0, y) - ans(0, l, 0, x-1))$.

And if we define $ans(0, r, 0, y)$ as $ans'(r, y)$,

$ans(l,r,x,y) = (ans'(r,y) - ans'(r,x-1)) - (ans'(l,y)-ans'(l,x-1))$.

<details><summary>Why? Try to justify this simpification.</summary>

The count of *good* numbers in $(l, r]$ is the count between $(0, r]$, minus the count between $(0, l]$ ($0$ will also never be counted, which is fine).

By a similar principle, we can break up $[x, y]$ into $[0, y]$ and $[0, x]$.

This simplification helps because the lower bound is zero, crucial in many Digit DP (and DP in general) problems (and we most definitely want to use Digit DP).

Now, let's solve an easier problem. In Digit DP, you often want to try to obtain a solution that works under “no restrictions”. What does this mean?

Let $dp[n][x]$ equal the number ways to use exactly $n$ digits to achieve a digit product of $x$.

- $dp[1][4] = 1$ because $4$ is the only way to achieve a digit product of four with exactly one digit.
- $dp[2][4] = 3$ because $14$, $22$, and $41$ all achieve a digit product of four with exactly two digits.

<details><summary>Quick check... Only continue if everything above makes sense.</summary>

Never think more than one layer deep for DP! Assume you have $dp[n-1][1] + dp[n-1][2] + dp[n-1][3] + \dots + dp[n-1][x-1] + dp[n-1][x]$ (i.e. all $dp$ values with $n-1$).

To find $dp[n][x]$, we can choose different values for the $n$-th digit, then sum the counts from all choices for digits.

Let's say the $n$-th digit is $1$.

```txt
1______________
   n-1 digits
```

The remaining $n-1$ digits must have a product of $x$. That adds $dp[n-1][x]$ to $dp[n][x]$.

Let's say the $n$-th digit is $2$.

```txt
2______________
   n-1 digits
```

The remaining $n-1$ digits must have a product of...

<details><summary>Think</summary>

The remaining $n-1$ digits must have a product of $\frac{x}{2}$.

That adds $dp[n-1][\frac{x}{2}]$ to $dp[n][x]$.

Notice a problem? $\frac{x}{2}$ may not be an integer. You will want to check that $\frac{x}{2}$ is integer $\left(x \cong 0 \mod 2\right)$ before attempting to add $dp[n-1][\frac{x}{2}]$ to $dp[n][x]$. (No digit products are non-integers, so you would add $0$ to $dp[n][x]$ if $\frac{x}{2}$ is a noninteger).

Let's say the $n$-th digit is $3$.

```txt
3______________
   n-1 digits
```

Learning from last time, we first check if $x\cong 0 \mod 3$. If not, we continue because the number with $n-1$ digits cannot exist. If so, $\frac{x}{3}$ is an integer, and we add...

<details><summary>Think</summary>

We add $dp[n][\frac{x}{3}]$ to $dp[n][x]$.

Generalizing, we get $dp[n][x] = \sum_{d \in S} dp[n-1][\frac{x}{d}]$, where $S$ is the set of digits $d$ where $x \cong 0 \mod d$.

Now, what about those “restrictions”?

Well, we cannot choose every $d$ in $S$. For example, if $r = 54321$ and we are choosing the leftmost digit, then $d$ must be less than or equal to $5$. This is a “restriction”.

Another problem arises if we choose $d=5$ for the leftmost digit. The restriction carries; since we secured $5$ for the leftmost digit, the second digit from the left must be less than or equal to $4$.

<details><summary>Make sure everything above makes sense...</summary>

In Digit DP, we often handle restrictions by adding a state.

Let $dp[n][x][0]$ equal the number ways to use exactly $n$ digits to achieve a digit product of $x$ **without restrictions**.
Let $dp[n][x][1]$ equal the same, but **with restrictions**.

When we have restrictions, for $n$ the digit (from the right), our DP may ONLY consider digits ($d$) less than or equal to the $n$-th digit from the right in $r$.

FURTHERMORE, when $d$ equals the $n$-th digit, we have to “carry” the restriction.

In other words, $dp[n][x][1] = \sum_{d \in S} dp[n-1][\frac{x}{d}][0]$, where $S$ is the set of digits $d$ where $x \cong 0 \mod d$ and $d$ is strictly less than the $n$-th digit from the right in $r$. Denote the $n$-th digit from the right in $r$ as $r_n$.

Then, if $x \cong 0 \mod r_n$, we must add $dp[n-1][\frac{x}{r_n}][1]$ to $dp[n][x][1]$. This “carries” the restriction.

<details><summary>All good?</summary>

Finally, we need our base case. For my code, I let $dp[1][d][0] = 1$ for all $d \in [1, 9]$ and $dp[1][d][1] = 1$ for all $d \in [1, r_1]$. This makes sense. One digit can make a digit product of $1$, once (with $1$). One digit can make a digit product of $2$ once (with $2$). With restrictions, the same applies, except $d$ cannot surpass $r_1$ (or else we are counting numbers greater than $r$).

To get $ans'(r, y)$, we iterate over every $n$ up to the number of digits in $r$, and for each $n$, we add all $dp[n][x][0]$ ($x \in [1, y]$) to a counter (or $dp[n][x][1]$ if $n$ equals the number of digits in $r$). $ans'(r, y)$ will equal the final value of the counter.

The reason we only add the restriction when $n$ equals the number of digits in $r$ is because...

<details><summary>Think</summary>

The reason we only add the restriction when $n$ equals the number of digits in $r$ is because in all other cases, we are considering numbers with fewer digits than $r$, which will inevitably be smaller than $r$ and in the range $(0, r]$ (or the number will be $0$, which has a digit product of $0$, which is not considered in the problem).

Now, calculate $(ans'(r,y) - ans'(r,x-1)) - (ans'(l,y)-ans'(l,x-1))$. This is our answer.

</details>
</details>
</details>
</details>
</details>
</details>
</details>
</details>
</details>
