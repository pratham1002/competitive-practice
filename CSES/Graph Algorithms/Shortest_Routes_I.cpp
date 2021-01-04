/*
 * There are n cities and m flight connections between them. 
 * Your task is to determine the length of the shortest route
 * from Syrjälä to every city.
 * 
 * Algorithm used: Dijkstra's
 */
 
#include <bits/stdc++.h>
 
using namespace std;
 
class Graph {
    int n;  // number of node in the graph
 
    vector<list<pair<int, int>>> adj;    // ajacency list representing graph
 
    public:
        Graph(int n);
 
        void addEdge(int x, int y, int w);
 
        vector<long long> dijkstra();
};
 
Graph::Graph(int n) {
    this->n = n;
    (this->adj).resize(n);
}
 
void Graph::addEdge(int x, int y, int w) {
    (this->adj)[x].push_back(pair<int, int>(y, w));
}
 
vector<long long> Graph::dijkstra() {
    // initilise the dist array
    vector<long long> dist(n, LLONG_MAX);
    dist[0] = 0;
 
    priority_queue<pair<long long, int>> pq;
    pq.push(make_pair(0, 0));
 
    vector<bool> visited(n, false);
 
    while(!pq.empty()) {
        // find the minimum non frozen element index
        int min_index = pq.top().second;
        pq.pop();
 
        if (visited[min_index] == true) {
            continue;
        }
 
        visited[min_index] = true;
 
        // update distance to all neighbors of the current node
        list<pair<int, int>> edges = adj[min_index];
 
        for (pair<int, int> e: edges) {
            int node = e.first;
            int weight = e.second;
 
            if (dist[node] > dist[min_index] + weight) {
                dist[node] = dist[min_index] + weight;
                pq.push(make_pair(-dist[node], node));
            }
        }
    }
 
    return dist;
}
 
int main() {
    int n, m;
    cin >> n >> m;
 
    Graph g(n);
 
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        g.addEdge(a - 1, b - 1, w);
    }
 
    vector<long long> dist = g.dijkstra();
 
    for (long long node: dist) {
        cout << node << " ";
    }
 
    cout << "\n";
 
    return 0;
}