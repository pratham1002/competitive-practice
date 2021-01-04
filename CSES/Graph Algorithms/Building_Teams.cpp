/*
 * There are n pupils in Uolevi's class, and m friendships between them. 
 * Your task is to divide the pupils into two teams 
 * in such a way that no two pupils in a team are friends. 
 * You can freely choose the sizes of the teams.
 * 
 * Algorithm used: DFS (greedy graph coloring)
 */

#include <bits/stdc++.h>

using namespace std;

class Graph {
    int n;  // number of node in the graph

    vector<list<int>> adj;    // ajacency list representing graph

    public:
        Graph(int n);

        void addEdge(int x, int y);

        vector<int> color();

        vector<int> DFS();

    private:
        void exploreNeighbors(int at, vector<int> &teams);
};

Graph::Graph(int n) {
    this->n = n;
    (this->adj).resize(n);
}

void Graph::addEdge(int x, int y) {
    (this->adj)[x].push_back(y);
    (this->adj)[y].push_back(x);
}

// TODO: should not stop after first connected component
vector<int> Graph::DFS() {
    vector<int> teams(this->n, 0);

    for (int i = 0; i < this->n; i++) {
        if (!teams[i]) {
            teams[i] = 1;
            exploreNeighbors(i, teams);
        }
    }

    return teams;
}

void Graph::exploreNeighbors(int at, vector<int> &teams) {
    list<int> neighbours = this->adj[at];

    for (int i: neighbours) {
        if (!teams[i])
        {
            if (teams[at] == 1) {
                teams[i] = 2;
            } else {
                teams[i] = 1;
            }
            exploreNeighbors(i, teams);
        }
        else
        {
            if (teams[i] == teams[at]) {
                teams.resize(0);
                return;
            }
        }
    }
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

    vector<int> teams = g.DFS();

    if (teams.size() == 0) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    for (int node: teams) {
        cout << node << " ";
    }

    cout << "\n";

    return 0;
}