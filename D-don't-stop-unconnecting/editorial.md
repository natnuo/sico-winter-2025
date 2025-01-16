# Don't Stop Unconnecting

Don't Stop Unconnecting is solvable in $O(n \log n)$.

This is about $n \log n = 1.66\cdot 10^6$ maximum operations.

To solve, translate the elements of the problem.

Type two queries ask for ``the number of nodes that can be reached from node $i$ by only traveling along the graph's edges''.

We want all the nodes reachable from $i$... so the component of $i$. We need the size of the component of $i$.

Edge deletion affects the sizes of these components. Can we track component sizes efficiently after deleting edges?

The answer: Use a link cut tree! (No, just kidding. Platinum concepts are not needed, Kenneth.)

However, the idea of managing components in $O(n \log n)$ should make you consider the DSU data structure, and notice how edge deletion is simply edge creation, reversed.

How do we reverse the edge deletions?

We can iterate backwards through the queries, save our answers (edge deletion becomes creation), and reverse our answers to obtain the correct final result.

Type 1 operations therefore become the DSU ``unite'' operation, and finding component sizes with a DSU fairly trivial.
