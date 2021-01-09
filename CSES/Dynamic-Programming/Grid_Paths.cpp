#include<bits/stdc++.h> 
using namespace std; 

const int MOD   = 1e9 + 7;

void solve(); 
int main() 
{ 
   ios_base::sync_with_stdio(false);cin.tie(NULL);  
   
   int t=1; 
   while(t--) 
   { 
      solve(); 
      std::cout<<"\n"; 
   } 
   
   return 0; 
} 
void solve() 
{ 
    int n;
    cin >> n;

    vector<vector<char>> grid(n+1, vector<char>(n+1));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> grid[i][j];
        }
    }

    vector<vector<int>> mem(n+1, vector<int>(n+1, 0));

    // base case
    mem[1][1] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (grid[i][j] == '*') {
                mem[i][j] = 0;
            } else {
                // up
                if (i > 0) {
                    mem[i][j] = (mem[i][j] + mem[i-1][j]) % MOD;
                }
                // left
                if (j > 0) {
                    mem[i][j] = (mem[i][j] + mem[i][j-1]) % MOD;
                }
            }
        }
    }

    std::cout << mem[n][n];
} 