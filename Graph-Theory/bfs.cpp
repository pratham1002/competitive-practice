/* 
 * Algorithm: Depth First Search (DFS)
 * Type: Traversal Algorithm
 * Time Complexity: O(V + E), Space Complexity: O(V)
 * 
 * Fundamental search algorithm that used to explore nodes and edges of a graph
 * Often used as a building block in other algorithms
 * 
 * Use cases:
 *  Shortest path on unweighted graphs
 * 
 * Implementation:
 *  BFS starts at some arbitrary node of a graph
 *  Explores the neighbour nodes first
 *  Then moves to the next level neighbours.
 * 
 *  Start at node 0
 *  Visit all neighbours of node 0
 *  Then visit all neighbours of the neighbours of node 0
 *  Maintains a queue of which node to visit next.
 * 
 * Pseudo code
 *  # Global or class scope variables
 *  n = number of node in the graph
 *  g = ajacency list representing graph
 * 
 *  # s = start node
 *  function bfs(s):
 *      q = queue data structure with enqueue and dequeue
 *      q.enqueue(s)
 * 
 *      visited = [false, ..., false]   # size n
 *      visited[s] = true
 * 
 *      while !q.isEmpty():
 *          node = q.dequeue()
 *          neighbours = g.get(node)
 *          
 *          for (next: neighbours):
 *              if !visited[next]:
 *                  q.enqueue(next)
 *                  visited[next] = true
 */

#include <bits/stdc++.h>

using namespace std;

class Graph {
    int n;  // number of node in the graph

    vector<list<int>> adj;    // ajacency list representing graph

    public:
        Graph(int n);

        void addEdge(int x, int y);

        void BFS(int s);
};

Graph::Graph(int n) {
    this->n = n;
    (this->adj).resize(n);
}

void Graph::addEdge(int x, int y) {
    (this->adj)[x].push_back(y);
}

void Graph::BFS(int s) {
    queue<int> q;
    q.push(s);

    vector<bool> visited(this->n, false);
    visited[s] = true;

    cout << s << " ";

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        list<int> neighbours = (this->adj)[node];

        for (int next: neighbours) {
            if (!visited[next]) {
                q.push(next);
                visited[next] = true;
                cout << next << " ";
            }
        }
    }
}

int main()
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
    g.BFS(2);

    cout << "\n";
    return 0;
}