/*
 * Syrjälä's network has n computers and m connections. 
 * Your task is to find out if Uolevi can send a message to Maija, 
 * and if it is possible, 
 * minimum number of computers on such a route.
 * 
 * Algorithm used: BFS (shortest path)
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
    (this->adj)[y].push_back(x);
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
    int n, m;
    cin >> n >> m;
    Graph g(n);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g.addEdge(a - 1, b - 1);
    }

    vector<int> path = g.shortestPath(0, n - 1);

    if (path.size() == 0) {
        cout << "IMPOSSIBLE" << "\n";
        return 0;
    }
    cout << path.size() << "\n";

    for (int node: path) {
        cout << node + 1 << " ";
    }

    cout << endl;

    return 0;
}