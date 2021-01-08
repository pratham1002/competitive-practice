#include<bits/stdc++.h> 
using namespace std; 
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
void solve() 
{ 
    int n;

    cin >> n;

    vector<int> mem(n+1, 9999999);

    // start building the mem table bottom up
    mem[0] = 0;

    for (int i = 1; i <= n; i++) {
        int min = INT_MAX;

        int m = i;

        while (m) {
            int d = m % 10;
            int c = 1 + mem[i - d];

            if (c < min) {
                min = c;
            }

            m /= 10;
        }

        mem[i] = min;
    }

    cout << mem[n];
} 