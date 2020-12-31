## Common Problems in Graph Theory

### Shortest Path Problem
Given a weighted graph, find the shortest path of edges from node A to node B.  
  
Algorithms
-   BFS (unweighted graph)
-   Dijkstra's
-   Bellman-Ford
-   Floyd-Warshall
-   A*

### Connectivity
Does there exist a path between node A to node B.  
  
Typical solution: Use union find data structure or any search algorithm (e.g. DFS)

### Negative Cycles
Does the weighted digraph have any negative cycles? If so, where?  
  
Algorithms
-   Bellman-Ford
-   Floyd-Warshall

### Strongly Connected Components
Self contained cycles within a digraph where every vertex in a given cycle can reach every other vertex in the same cycle.  
  
Algorithms
-   Tarjan's
-   Kosaraju's

### Travelling Salesman Problem (NP Hard)
> Given a list of cities and the distances between each pair of cities, what is the shortest possible route that visits each city exactly once and returns to the origin city?
  
Algorithms
-   Held-Karp
-   branch and bound
-   approximation algorithms

### Bridges (Cut Edge)
A bridge / cut edge is any edge in a graph whose removal increases the number of connected components.  

### Articulation Points (Cut Vertex)
An articulation point / cut vertex is any node in a graph whoes removal increases the number of connected components.

### Minimum Spanning Tree (MST)
A MST is a subset of the edges of a connected, edge-weighted graph that connects all the vertices together, without any cycles  and with the minimum possible total edge weight.  
  
Algorithms
-   Kruskal's
-   Prim's
-   Boruvka's

### Network flow: max flow
> With an infinite input source, how much "flow" can we push through the network?
  
Algorithms
-   Ford-Fulkerson
-   Edmonds-Karp
-   Dinic's