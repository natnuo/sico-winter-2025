<!-- NOTE: TEST CHECKER -->
# NOTE TO SELF TEST TEAMS CHECKER

# Teams

Teams is solvable in $O(n^2K_a)$.

This is about $n^2K_a = 10^7$ operations.

First, we always want to simplify the problem as much as possible. What can we remove without losing information?

Well, we can merge friends into one, as if they were one person. Friends are guaranteed to be in the same final team, so we are really adding these “friend groups” to teams.

If we imagine the players as nodes and friendships as edges (which should be a reasonable starting point), a friend group represents a connected component of the undirected graph. These connected components can be found in the standard manner: iterating over each node and starting a DFS at each unvisited node.

How do we maintain skill data in friend groups?

We can let the “skill” of a friend group be equal to the sum of the skills of the players in that group.

Furthermore, since the problem requires the groups have equal player counts and requests information about the players, we must also give each friend group a “player count” property.

This is a definition for a friend group, in C++.

```cpp
struct friend_group {
        int skill;
        vector<int> players;
};
```

Let $n_f$ be the number of friend groups.

So, we have $n_f$ friend groups, and we need to partition these friend groups into two teams, each with $\frac{n}{2}$ players.

Focusing on Team A, we need to choose friend groups that will not have a total skill over $K_a$, but have a total player count of $\frac{n}{2}$.

Do you see the next step?

Yes, we now use Knapsack DP. The team is our “knapsack”, the friend groups are our “stones”, the skills are our “profits”, the player counts are our “weights”, and $K_a$ is our maximum weight!

YAY!

The transitions are somewhat-standard for Knapsack DP. First, we solve a slightly simpler problem:

Let $dp[i][v][w]$ represent whether (`true`/`false`) we can use the first $i$ friend groups (any consistent order) to achieve exactly $v$ profit and $w$ weight.

How do we use this information to tell if a solution is possible?

First, define $w_{total}$ as the total weight of all the friend groups.

We iterate over all $dp[i][\frac{n}{2}][w]$, $1 \le i \le n_f$, $1 \le w \le K_a$. Intuitively, this means we iterate over all relavant (last friend group processed, weight) combinations. For each reachable combination ($dp[i][\frac{n}{2}][w]$ is `true`), notice that if we choose to assign to Team A exactly the friend groups that led up to $dp[i][\frac{n}{2}][w]$, we have $w$ weight in Team A (I will now call $w$ as $w_a$). Since all other friend groups must be assigned to a team, all other groups go to Team B, giving Team B $w_b = w_{total} - w_a$ weight. If and only if $w_b \le K_b$ is the combination for Team B valid, making the whole arrangement valid.

- (Optional Read) You may wonder if you can iterate only over all $dp[n_f][\frac{n}{2}][w]$, $1 \le w \le K_a$ instead. The answer is, it depends on your implementation. This decision may be a bit complicated (and it might make more sense once the rest of the solution is discusses), but basically, if your implementation does not track *how* a DP state was reached and only from where it was reached, then you likely want to find the earilest $i$ that is reachable (because you likely want to backtrack the DP to get the player combinations, and would prefer to start on a state that involves a friend group that was just added).

Consider the choices we have if we are finding $dp[i][v][w]$. In the general case, we can:

- Add the $i$-th friend group. Define the skill of the $i$-th friend group as $v_i$; the weight, $w_i$. Define $v' = v - v_i$ and $w' = w - w_i$. This “adding” option is available if and only if $dp[i-1][v'][w']$ is `true` (meaning that a valid way to reach this state is from $dp[i-1][v'][w']$, which is itself a valid state).
- Not add the $i$-th friend group. This “non-adding” option is available if and only if $dp[i-1][v][w]$ is `true`.

If and only if either option is available, then $dp[i][v][w]$ is reachable therefore `true`.

We are so close to solving the problem! We only need to find a combination of assignments that lead to a correct answer. We need to maintain the last added friend group in our DP states. To do this:

- For each time our DP chooses to add the $i$-th friend group, we set $dp[i][v][w]$ to point to $dp[i-1][v'][w']$.
- For each time our DP chooses to not add the $i$-th friend group, we set $dp[i][v][w]$ to point to what $dp[i-1][v][w]$ points to.

As a result, $dp[i][v][w]$ points to the last state where a friend group was added in a combination to achieve exactly $v$ profit and $w$ weight using only the first $i$ friend groups (in any consistent order).

Our base case is that $dp[0][0][0]$ exists and equals some “Origin” value. All other $dp[i][v][w]$ are initialized to some “Nonexistent”/“DNE” value (you have to determine ways to represent Origin and DNE).

Now, once we iterate and find a working $dp[i][\frac{n}{2}][w]$ state, we only need to iterate “backwards” by travelling from each state to the pointed state, until we inevitably reach the origin, and save all the players of the friend groups of the visited states to Team A.
