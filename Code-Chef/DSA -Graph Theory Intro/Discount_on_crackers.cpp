// https://www.codechef.com/LRNDSA08/problems/ACM14KG3
// Algorithm: DFS

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

void solve() 
{ 
    string x, y;
    cin >> x >> y;

    if (x.length() != y.length()) {
        cout << "NO";
        return;
    }

    // the adjacency matrix for characters
    vector<list<int>> adj(26);

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        string l;
        cin >> l;
        adj[l[0]-'a'].push_back(l[3]-'a');
    }

    vector<vector<bool>> reachable(26, vector<bool>(26, false));

    // run DFS for each node to find reachable nodes
    for (int i = 0; i < 26; i++) {
        stack<int> s;
        s.push(i);

        vector<bool> visited(26, false);
        visited[i] = true;
        reachable[i][i] = true;

        while(!s.empty()) {
            int node = s.top();
            s.pop();

            list<int> neighbors = adj[node];

            for (int n: neighbors) {
                if (!visited[n]) {
                    s.push(n);
                    visited[n] = true;
                    reachable[i][n] = true;
                }
            }
        }
    }

    for (int i = 0; i < x.length(); i++) {
        if (!reachable[x[i]-'a'][y[i]-'a']) {
            cout << "NO";
            return;
        }
    }

    cout << "YES";
} 