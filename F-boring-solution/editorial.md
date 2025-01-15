# Boring Solution

**Solution 1:**

Boring Solution is solvable in $O(n \log n)$.

This is about $n \log n = 1.66\cdot 10^6$ maximum operations.

We need to quickly find the number of integers larger than a number.

We can sort $a$, then binary search for the index of first element greater than or equal to for each $a[i] + k$.

Reorder $a$ to represent the original order, and output. You can save how the indexes moved throughout sorting by saving $a$ as a series of $(\text{value}, \text{index})$ pairs before sorting.

**Solution 2:**

Boring Solution is solvable in $O(n \log n)$.

This is about $n \log n = 1.66\cdot 10^6$ maximum operations.

First, sort $a$ in nonincreasing order.

Let $j=0$.

For each $i$ from $0$ to $n-1$, increment $j$ until $a[j] - a[i] \ge k$ (0-indexed). Each time $j$ is incremented, update a counter, representing the number of values at least $k$ greater than $a[i]$. Save these values for each index.

Reorder the integers-$k$-over count array. You may save $a$ as $(\text{value}, \text{index})$ pairs before sorting, thereby tracking how indexes were moved during sorting, allowing you to reverse the process.

After re-configuring the integers-$k$-over count array to match the original order of $a$, output that array, and the problem is solved.
