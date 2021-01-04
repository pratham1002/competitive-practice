#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;

int main() {
  	int n, w;
  	std::cin >> n >> w;

    ll val[n];
    ll wt[n];
 
    for (int i = 0; i < n; i++) {
        cin >> wt[i] >> val[i];
    }

    ll K[n + 1][w + 1];

    // Build table K[][] in bottom up manner 
    for (int i = 0; i <= n; i++)  
    { 
        for (int j = 0; j <= w; j++)  
        { 
            if (i == 0 || j == 0) 
                K[i][j] = 0; 
            else if (wt[i - 1] <= j) 
                K[i][j] = max(val[i - 1] + K[i - 1][j - wt[i - 1]], K[i - 1][j]); 
            else
                K[i][j] = K[i - 1][j];
        }
    }

    std::cout << K[n][w] << endl;
 
    return 0;
}
