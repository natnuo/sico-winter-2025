# Flood

Flood is solvable in $O(nm)$.

This is about $nm = 2.5\cdot 10^4$ maximum operations.

Summarize the problem statement simply:

- Water tiles expand.
- We must make one water into land; choose the water tile that minimizes total expansion time.

Let's start with a subproblem. How can we calculate the time to make all tiles water, supposing we do not change a water tile?

The answer will be the time that the last land tile becomes water. We are calculating distances! We want to know: which land tile is furthest from a water tile, and how far?

To calculate minimum distances. We very often use some variation of BFS. Since all water tiles can expand, in this case, we are using Multisource BFS.

Multisource BFS will give us each tile's distance from water, but what about which water tile to make land?

Well, consider what changes when a water tile $A$ becomes land.

- If a land tile's closest water tile was $A$, then its closest water tile becomes what was its second closest water tile.
- If a land tile's closest water tile was not $A$, then its closest water tile remains the same.

Notice that we need to know only the *two* closest water tiles. We can simply adapt our Multisource BFS to record these two tiles!

Then, we can calculate the new water distances of each land tile after removing each water tile. The time to make all land tiles water, after changing a water tile to land, follows as the maximum distance of a land tile to water (after the change).

To calculate these ``maximum distances'' efficiently, we store a grid $dist\_on\_removal$ that maps water tiles to the maximum distance of a land to water if this water tile is changed. The distance for each water tile defaults to the answer under no changes. For each land tile, we set the $dist\_on\_removal$ value of the closest water tile to the maximum of the current value and the distance from the land tile to the second closest water tile (good luck trying to understand that phrasing).
