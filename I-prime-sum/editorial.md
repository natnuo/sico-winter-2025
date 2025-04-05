# Prime Sum

Prime Sum is solvable in approximately $O(n\cdot\frac{\max{a_i}}{\ln \max{a_i}})$.

This is about $n\cdot\frac{\max{a_i}}{\ln \max{a_i}} = 5.87 \cdot 10^7$ operations.

First, since we are dealing with primes, it might seem helpful to calculate all possible primes we can add to (all possible results of $a_i + a_j$). We can do this with the famous...

<details><summary>Think</summary>

Sieve of Eratosthenes

Running Sieve up to $2 \max{a_i}$, we can produce a list of 2,262 primes. Of course, in contest, you likely will not know this number off the top of your head, but you can approximate the number of primes under a given positive integer $x$ as $\frac{x}{\ln x}$. So, $\frac{2 \max{a_i}}{\ln \left(2 \max{a_i}\right)} \approx 2019.49$... we have a fairly good estimate!

Now, with all possible sums, we can find the number of $a_i + a_j$ combinations that work by...

<details><summary>Think</summary>

Iterating over all $a_i$ and primes, and finding the count of $a_j$.

Let's make nested loops, such that we have $a_i$ and the prime, $p$, fixed within the nested loops. This gives us a fixed $a_j$, since $a_i + a_j = p$, so $a_j = p - a_i$.

Therefore, we can just precompute the counts of every number in $a$, and in this case, add the count of $a_j$ to our answer.

However, we must be cautious of one thing...

<details><summary>Think</summary>

We must not double-count!

To resolve this, we simply add to our vector of counts only when a number has finished processing. This means that our ``counts'' vector stores only the prefix counts (i.e. the counts before the current $a_i$).

Also note that this means, in our nested loops, iterating for $a_i$ should come outside iterating for $p$.

</details>

</details>

</details>
