// https://www.codechef.com/LRNDSA08/problems/MARLA

#include<bits/stdc++.h> 
using namespace std; 

typedef long long ll;
const int MOD = 1e9+7;

void solve(); 
int main() 
{ 
   ios_base::sync_with_stdio(false);cin.tie(NULL); 
   
   int t=1; 
   while(t--) 
   { 
      solve(); 
      cout<<"\n"; 
   } 
   
   return 0; 
} 

int countBanks(int n, int m, int i, int j, vector<vector<int>> &country, vector<vector<bool>> &visited) {
    visited[i][j] = true;

    int banks = 1;

    // up
    if (i > 0 && !visited[i-1][j] && country[i][j] == country[i-1][j]) {
        banks += countBanks(n, m, i-1, j, country, visited);
    }

    // down
    if (i+1 < n && !visited[i+1][j] && country[i][j] == country[i+1][j]) {
        banks += countBanks(n, m, i+1, j, country, visited);
    }

    // left
    if (j > 0 && !visited[i][j-1] && country[i][j] == country[i][j-1]) {
        banks += countBanks(n, m, i, j-1, country, visited);
    }

    // right
    if (j+1 < m && !visited[i][j+1] && country[i][j] == country[i][j+1]) {
        banks += countBanks(n, m, i, j+1, country, visited);
    }

    return banks;
}
void solve() 
{ 
    int n, m;
    cin >> n >> m;

    vector<vector<int>> country(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> country[i][j];
        }
    }

    // form (security, num_banks)
    vector<pair<int, int>> states;

    vector<vector<bool>> visited(n, vector<bool>(m, false));

    // count the number of banks in each state
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j]) {
                states.push_back(make_pair(country[i][j], countBanks(n, m, i, j, country, visited)));
            }
        }
    }

    int min_security = INT_MAX;
    int max_banks = INT_MIN;

    for(pair<int, int> i: states) {
        if ((i.second > max_banks) || (i.second == max_banks && i.first < min_security)) {
            min_security = i.first;
            max_banks = i.second;
        }
    }

    cout << min_security << " " << max_banks;
} 