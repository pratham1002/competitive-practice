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
    int n, m;
    cin >> n >> m;

    vector<int> dns(m);
    vector<int> steps(n+1, INT_MIN);

    for (int i = 0; i < m; i++) cin >> dns[i];

    sort(dns.begin(), dns.end());

    // base case - currently we are at step 0  and can move to step 1 or step 2
    if (!binary_search(dns.begin(), dns.end(), 1))
        steps[1] = 1;
    if (!binary_search(dns.begin(), dns.end(), 2)) {
        steps[2] = 1;

        if (steps[1] != INT_MIN)
            steps[2] = 2;
    }

    int p = 3;

    while(p <= n) {
        if (binary_search(dns.begin(), dns.end(), p)) 
            ;

        else if (steps[p-1] != INT_MIN && steps[p-2] != INT_MIN)
            steps[p] = (steps[p-1] + steps[p-2]) % 1000000007;
        
        else if (steps[p-1] != INT_MIN && steps[p-2] == INT_MIN)
            steps[p] = steps[p - 1];

        else if (steps[p-1] == INT_MIN && steps[p-2] != INT_MIN)
            steps[p] = steps[p - 2];
        
        else if (steps[p-1] == INT_MIN && steps[p-2] == INT_MIN)
            break;

        p++;
    }

    if (steps[n] != INT_MIN)
        cout << steps[n];
    else
        cout << 0;
}