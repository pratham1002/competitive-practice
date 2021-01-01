/*
 * Byteland has n cities, and m roads between them. 
 * The goal is to construct new roads so that there is a route between any two cities.
 * Your task is to find out the minimum number of roads required, 
 * and also determine which roads should be built.
 * 
 * Algorithm used: DFS (connected components)
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

    vector<int> findComponents();
};

Graph::Graph(int n) {
    this->n = n;
    (this->adj).resize(n);
    (this->components).resize(n);
}

void Graph::addEdge(int x, int y) {
    (this->adj)[x].push_back(y);
    (this->adj)[y].push_back(x);
}

vector<int> Graph::findComponents() {
    vector<bool> visited(this->n, false);
    int count = 0;

    for (int i = 0; i < this->n; i++) {
        if (!visited[i]) {
            count++;
            DFS(i, visited, count);
        }
    }

    return this->components;
}

void Graph::DFS(int at, vector<bool> &visited, int &count) {
    (this->components)[at] = count;
    visited[at] = true;

    list<int> neighbours = (this->adj)[at];

    for (int i: neighbours) {
        if (!visited[i]) {
            DFS(i, visited, count);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    Graph g(n);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g.addEdge(a - 1, b - 1);
    }

    vector<int> components = g.findComponents();

    int num_components = *max_element(components.begin(), components.end());

    cout << num_components - 1 << "\n";

    // find the first occurance of 1
    int first_element;
    for (int i = 0; i < components.size(); i++)
    {
        if (components[i] == 1) {
            first_element = i;
            break;
        }
    }

    for (int i = 2; i <= num_components; i++) {
        for (int j = first_element; j < components.size(); j++) {
            if (components[j] == i) {
                cout << first_element + 1 << " " << j + 1;
                first_element = j;
                break;
            }
        }
        cout << "\n";
    }
    cout << "\n";
    return 0;
}