# Square Subarray

Square Subarray is solvable in $O(n \sqrt n)$.

This is about $n \sqrt n = 3.16 \cdot 10^7$ maximum operations.

The idea of finding sums of subarrays should immediately lead you to think...

<details><summary>Think</summary>
Prefix sums.

Next, we should check what time complexities could work. The problem involves perfect squares, so checking $O(n \sqrt n)$ is reasonable, and as shown above, $n \sqrt n$ is less than $10^8$ and should pass.

Now the solution is simple.

<details><summary>Think</summary>

1. Create a global sum, the answer.
2. Establish a prefix sum.
3. Iterate over $a$. For each index:
   1. Iterate over all subarrays starting from this index of perfect square length.
   2. Check the sum of all elements in that suarray using a prefix sum.
   3. Add that sum to the global sum.
4. Output the solution

</details>
</details>
