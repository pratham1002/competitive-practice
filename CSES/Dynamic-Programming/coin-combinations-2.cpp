#include <bits/stdc++.h>
#define MODULO 1000000007 

using namespace std;

int main() {
    int n, t;
    cin >> n >> t;

    vector<int> coins(n);

    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    sort(coins.begin(), coins.end());

    int combinations[n][t+1];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= t; j++) {
            if (j == 0) {
                combinations[i][j] = 1;
            }
            else  if (i == 0) {
                combinations[i][j] = j % coins[i] == 0;
            }
            else if (j < coins[i]) {
                combinations[i][j] = combinations[i - 1][j];
            }
            else {
                combinations[i][j] = (combinations[i - 1][j] + combinations[i][j - coins[i]]) % MODULO;
            }
        }
    }

    cout << combinations[n-1][t] << endl;

    return 0;
}