#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;

int main() {
  	int n, w;
  	std::cin >> n >> w;

    int val[n];
    int wt[n];
 
    for (int i = 0; i < n; i++) {
        cin >> wt[i];
    }


    for (int i = 0; i < n; i++) {
        cin >> val[i];
    }

    int K[2][w + 1];

    // Build table K[][] in bottom up manner 
    for (int i = 0; i <= n; i++)  
    { 
        for (int j = 0; j <= w; j++)  
        { 
            if (i == 0 || j == 0) 
                K[i%2][j] = 0; 
            else if (wt[i-1] <= j) 
                K[i%2][j] = max(val[i-1] + K[(i+1)%2][j - wt[i-1]], K[(i+1)%2][j]); 
            else
                K[i%2][j] = K[(i+1)%2][j];
        }
    }

    std::cout << K[0][w] << endl;
 
    return 0;
}
