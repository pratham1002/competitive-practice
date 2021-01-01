/*
 * Finding the shortest path between 2 nodes
 * 
 * Algorithm used: BFS
 * 
 * Pseudo code
 *  # Global or class scope variables
 *  n = number of node in the graph
 *  g = ajacency list representing graph
 * 
 *  # s = start node, e = end node, 0 <= e, s < n
 *  function bfs(s, e):
 *      
 *      # Do a BFS starting at node s
 *      prev = solve(s)
 * 
 *      # Return reconstructed path from s -> e
 *      return reconstructPath(s, e, prev)
 *  
 *  function solve(s):
 *      q = queue data structure with enqueue and dequeue
 *      q.enqueue(s)
 * 
 *      visited = [false, ..., false]   # size n
 *      visited[s] = true
 * 
 *      prev = [null, ..., null]    # size n
 *      while !q.isEmpty():
 *          node = q.dequeue()
 *          neighbours = g.get(node)
 *          
 *          for (next: neighbours):
 *              if !visited[next]:
 *                  q.enqueue(next)
 *                  visited[next] = true
 *                  prev[next] = node 
 *      return prev
 * 
 *  function reconstructPath(s, e, prev):
 *      # Reconstruct the path going backwards from e
 *      path = []
 *      for (at = e; at != null; at = prev[at]):
 *          path.add(at)
 * 
 *      path.reverse()
 * 
 *      # If s and e are connected, return the path
 *      if path[0] == s:
 *          return path
 *      return []
 */

#include <bits/stdc++.h>

using namespace std;

class Graph {
    int n;  // number of node in the graph

    vector<list<int>> adj;    // ajacency list representing graph

    public:
        Graph(int n);

        void addEdge(int x, int y);

        vector<int> shortestPath(int s, int e);

    private:
        vector<int> BFS(int s);
        vector<int> reconstructPath(int s, int e, vector<int> path);
};

Graph::Graph(int n) {
    this->n = n;
    (this->adj).resize(n);
}

void Graph::addEdge(int x, int y) {
    (this->adj)[x].push_back(y);
}

vector<int> Graph::shortestPath(int s, int e) {
    // Do a BFS starting at node s
    vector<int> prev = BFS(s);
    // Return reconstructed path from s -> e
    return reconstructPath(s, e, prev);
}

vector<int> Graph::BFS(int s) {
    queue<int> q;
    q.push(s);

    vector<bool> visited(this->n, false);
    visited[s] = true;

    vector<int> prev(this->n, INT_MIN);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        list<int> neighbours = (this->adj)[node];

        for (int next: neighbours) {
            if (!visited[next]) {
                q.push(next);
                visited[next] = true;
                prev[next] = node;
            }
        }
    }

    return prev;
}

vector<int> Graph::reconstructPath(int s, int e, vector<int> prev) {
    // Reconstruct the path going backwards from e
    vector<int> path;

    for (int at = e; at != INT_MIN; at = prev[at]) {
        path.push_back(at);
    }

    reverse(path.begin(), path.end());

    // If s and e are connected, return the path
    if (path[0] == s) {
        return path;
    }
    return vector<int>();
}

int main() {
    Graph g(8);
    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(3, 4);
    g.addEdge(3, 7);
    g.addEdge(4, 5);
    g.addEdge(4, 6);
    g.addEdge(4, 7);
    g.addEdge(5, 6);
    g.addEdge(6, 7);

    int source = 0, dest = 7;

    vector<int> path = g.shortestPath(source, dest);

    for (int node: path) {
        cout << node << " ";
    }

    cout << endl;

    return 0;
}