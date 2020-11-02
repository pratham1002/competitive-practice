#include <bits/stdc++.h>
#define MODULO 1000000007 

using namespace std;

int main() {
    int n, t;
    cin >> n >> t;

    vector<int> coins(n);
    vector<int> combinations(t + 1, 0);

    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    sort(coins.begin(), coins.end());

    for (int i = 0; i <= t; i++) {
        for (int j = 0; j < n; j++) {
            if (i - coins[j] < 0) {
                continue;
            }
            if (i - coins[j] == 0) {
                combinations[i] += 1;
            }
            else {
                combinations[i] = (combinations[i] + combinations[i - coins[j]]) % MODULO;
            }
        }
    }

    cout << combinations[t] << endl;

    return 0;
}