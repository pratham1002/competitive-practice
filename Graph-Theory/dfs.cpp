/* 
 * Algorithm: Depth First Search (DFS)
 * Type: Traversal Algorithm
 * Time Complexity: O(V + E), Space Complexity: O(V)
 * 
 * Fundamental search algorithm that used to explore nodes and edges of a graph
 * Often used as a building block in other algorithms
 * 
 * Use cases:
 *  Count connected components
 *  Determine connectivity
 *  Compute MST
 *  Detect and find cycles in a graph
 *  Check if a graph is bipartite
 *  Find strongly connected components
 *  Topologically sort the nodes of a graph
 *  Find bridges / articulation points
 *  Find augmenting paths in a flow network
 *  Generate mazes
 * 
 * Implementation:
 *  DFS plunges depth first into a graph 
 *  without regard for which edge ot takes
 *  until it cannot go any further
 *  at which point it backtracks and continues.
 * 
 *  Start at node 0
 *  Pick an edge outwards from node 0, say node 9
 *  Once at node 9, pick an outward edge from node 9
 *  Do not revisit nodes, 
 *  Instead backtrack to find unvisited nodes
 * 
 * Pseudo code
 *  # Global or class scope variables
 *  n = number of node in the graph
 *  graph = ajacency list representing graph
 *  visited = [false, ..., false]   # size n
 * 
 *  function dfs(at):
 *      if visited[at]: return
 *      visited[at] = true
 *      
 *      neigbours = graph[at]
 *      
 *      for next in neighbours:
 *          dfs(next)
 * 
 *  start_node = 0
 *  dfs(start_node)
 */

#include <bits/stdc++.h>

using namespace std;

class Graph {
    int n;  // number of node in the graph

    vector<list<int>> adj;    // ajacency list representing graph

    public:
        Graph(int n);

        void addEdge(int x, int y);

        void DFS(int at, vector<bool> visited);
};

Graph::Graph(int n) {
    this->n = n;
    (this->adj).resize(n);
}

void Graph::addEdge(int x, int y) {
    (this->adj)[x].push_back(y);
}

void Graph::DFS(int at, vector<bool> visited) {
    if (visited[at]) return;
    visited[at] = true;
    cout << at << " ";
    list<int> neighbours = (this->adj)[at];

    for (auto it = neighbours.begin(); it != neighbours.end(); it++) {
        DFS(*it, visited);
    }
}

main()
{
    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Following is Depth First Traversal (starting from vertex 2) \n";
    g.DFS(2, vector<bool>(4, false));

    cout << "\n";
    return 0;
}