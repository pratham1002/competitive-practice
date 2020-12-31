/*
 * Finding the connected components of a Graph
 * Assign an integer value to each group to be able to tell them apart
 * 
 * Algorithm used: DFS
 * 
 * Implementation:
 *  First, label the nodes from [0, n)
 *  Start DFS at every node unless it has already been visited
 *  Mark all reachable nodes as being part of the same component
 * 
 * Pseudo Code:
 *  # Global or class scope variables
 *  n = number of node in the graph
 *  graph = ajacency list representing graph
 *  count = 0
 *  components = empty integer array    # size n
 *  visited = [false, ..., false]   # size n
 * 
 *  function findComponents():
 *      for (i = 0; i < n; i++):
 *          if !visited[i]:
 *              count++
 *              dfs(i)
 *      return (count, components)
 * 
 *  function dfs(at):
 *      visited[at] = true
 *      components[at] = count
 *      
 *      for (next: g[at]):
 *          if !visited[next]:
 *              dfs(next)
 */

#include <bits/stdc++.h>

using namespace std;

class Graph {
    int n;  // number of node in the graph

    vector<list<int>> adj;    // ajacency list representing graph

    vector<int> components;     // store the component each vertex is a part of

public:
    Graph(int n);

    void addEdge(int x, int y);

    void DFS(int at, vector<bool> &visited, int &count);

    int findComponents();
};

Graph::Graph(int n) {
    this->n = n;
    (this->adj).resize(n);
    (this->components).resize(n);
}

void Graph::addEdge(int x, int y) {
    (this->adj)[x].push_back(y);
}

int Graph::findComponents() {
    vector<bool> visited(this->n, false);
    int count = 0;

    for (int i = 0; i < this->n; i++) {
        if (!visited[i]) {
            count++;
            DFS(i, visited, count);
        }
    }

    return count;
}

void Graph::DFS(int at, vector<bool> &visited, int &count) {
    visited[at] = true;
    cout << at << " " << count << endl;

    list<int> neighbours = (this->adj)[at];

    for (int i: neighbours) {
        if (!visited[i]) {
            DFS(i, visited, count);
        }
    }
}

int main()
{
    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);

    cout << "The number of connected componnets in the given graph are: \n" << g.findComponents();

    cout << "\n";
    return 0;
}