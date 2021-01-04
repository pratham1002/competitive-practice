/*
 * There are n cities and m roads between them. 
 * Your task is to process q queries where you have to 
 * determine the length of the shortest route between two given cities.
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
 
        long long dijkstra(int start, int end);

        vector<int> findComponents();
        void DFS(int at, vector<bool> &visited, int &count, vector<int> &comp);
};

Graph::Graph(int n) {
    this->n = n;
    (this->adj).resize(n);
}
 
void Graph::addEdge(int x, int y, int w) {
    (this->adj)[x].push_back(pair<int, int>(y, w));
    (this->adj)[y].push_back(pair<int, int>(x, w));
}
 
long long Graph::dijkstra(int start, int end) {
    // initilise the dist array
    vector<long long> dist(n, LLONG_MAX);
    dist[start] = 0;
 
    priority_queue<pair<long long, int>> pq;
    pq.push(make_pair(0, start));
 
    vector<bool> visited(n, false);
 
    while(!pq.empty()) {
        // find the minimum non frozen element index
        int u = pq.top().second;
        if (u == end) {
            return -pq.top().first;
        }
        pq.pop();
 
        if (visited[u] == true) {
            continue;
        }

        visited[u] = true;
 
        // update distance to all neighbors of the current node
        list<pair<int, int>> edges = adj[u];
 
        for (pair<int, int> e: edges) {
            int node = e.first;
            int weight = e.second;
 
            if (dist[node] > dist[u] + weight) {
                dist[node] = dist[u] + weight;
                pq.push(make_pair(-dist[node], node));
            }
        }
    }
 
    return -1;
}
 
int main() {
    int n, m, q;
    cin >> n >> m >> q;
 
    Graph g(n);
 
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        g.addEdge(a - 1, b - 1, w);
    }

    for (int i = 0; i < q; i++) {
        int s, e;
        cin >> s >> e;

        long long dist = g.dijkstra(s - 1, e - 1);
            
        cout << dist << "\n";
    }    
 
    cout << "\n";
 
    return 0;
}