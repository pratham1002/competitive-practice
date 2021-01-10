// https://www.codechef.com/LRNDSA08/problems/FIRESC
// Algorithm: DFS Connected Components

#include<bits/stdc++.h> 
using namespace std; 

typedef long long ll;
const int MOD = 1e9+7;

void solve(); 
int main() 
{ 
   ios_base::sync_with_stdio(false);cin.tie(NULL); 
   
   int t=1; 
   cin>>t; 

   while(t--) 
   { 
      solve(); 
      cout<<"\n"; 
   } 
   
   return 0; 
} 


class Graph {
    int n;  // number of node in the graph

    vector<list<int>> adj;    // ajacency list representing graph

public:
    Graph(int n);

    void addEdge(int x, int y);

    void DFS(int at, vector<int> &visited, int &count);

    vector<int> findComponents();
};

Graph::Graph(int n) {
    this->n = n;
    (this->adj).resize(n);
}

void Graph::addEdge(int x, int y) {
    (this->adj)[x].push_back(y);
    (this->adj)[y].push_back(x);
}

vector<int> Graph::findComponents() {
    vector<int> components(this->n, 0);
    int count = 0;

    for (int i = 0; i < this->n; i++) {
        if (!components[i]) {
            count++;
            DFS(i, components, count);
        }
    }

    return components;
}

void Graph::DFS(int at, vector<int> &components, int &count) {
    components[at] = count;

    list<int> neighbours = (this->adj)[at];

    for (int i: neighbours) {
        if (!components[i]) {
            DFS(i, components, count);
        }
    }
}

int multiply (int a, int b) {
   int res = 0;

   a = a % MOD;
   while (b > 0)
   {
      // If b is odd, add 'a' to result
      if (b % 2 == 1)
         res = (res + a) % MOD;

      // Multiply 'a' with 2
      a = (a * 2) % MOD;

      // Divide b by 2
      b /= 2;
   }

   return res;
}

void solve() 
{ 
   int n, q;

   cin >> n >> q;

   Graph g(n);

   for (int i = 0; i < q; i++) {
      int a, b;
      cin >> a >> b;
      g.addEdge(a-1, b-1);
   }

   vector<int> components = g.findComponents();

   int num_components = *max_element(components.begin(), components.end());

   cout << num_components << " ";

   vector<int> counts(num_components+1, 0);

   for (int i: components) {
      counts[i] += 1;
   }

   int res = 1;

   for (int i = 1; i <= num_components; i++) {
      res = multiply(res, counts[i]);
   }

   cout << res;
} 