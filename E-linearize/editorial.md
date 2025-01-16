# Linearize

Linearize is solvable in $O(n \log n)$.

This is about $n \log n = 1.66\cdot 10^6$ maximum operations.

We recommend you start by testing some sample cases. This problem relies on two key observations:

**Observation 1:**

Hint: Is it ever optimal to move a point both horizontally and vertically?

The answer: No! In fact, we notice we either move all points horizontally or all points vertically (excluding points we choose not to move).

The proof:

Case 1: We are moving to a horizontal line, $y = a$.

- What is the distance between $(x_1, y_1)$ and $y=a$? It is $|y_1 - a|$.
- Furthermore, (assume $a > y_1$, the other case is just the opposite) by moving $(x_1, y_1)$ up $|y_1 - a|$ times, the point becomes $(x_1, y_1 + |y_1 - a|) = (x_1, y_1 - y_1 + a) = (x_1, a)$, which is on $y=a$. We can not optimize beyond taking $|y_1 - a|$ moves because of the first bullet (and the fact we move one unit each move)

Case 2: We are moving to a vertical line, $x = a$.

- This is just the same as case 1, but with changing $x_1$.
- I will not type it again.

The significance of this observation is that we have simplified the problem. We can find the most optimial horizontal line, the most optimal vertical line, and find which one produces the shortest point distance sum.

**Observation 2:**

The most optimal vertical line is $x = \text{the median of } x_1, x_2, \dots, x_n$.

The most optimal horizontal line is $y = \text{the median of } y_1, y_2, \dots, y_n$.

Proof (or vertical lines, but for horizontal lines is similar):

- At the median, half of points are to the right, and half are to the left (excluding the point we may be on).
- If there are odd points (the median is on the $x$ of a point):
  - Moving line to the right will increment the distance sum by a multiple of the number of points to the left and decrement by the number to the right.
  - The same follows for moving to the left.
  - The distances will get closer for a smaller number of points when we move away from the median.
- If there are even points, a similar concept applies:
  - Moving the line past the first point right of the median will cause the distance sum to increase more than decrease.
  - The same follows for the left.

Therefore, moving away from the median is (mostly, but pretty much) suboptimal, making the median optimal.

Calculate the distance sums for the most optimal horizontal and vertical lines, then output the minimum distance sum.

Notice that, although this editorial may be verbose to show proofs, the solution is guessable by trying many sample cases.
