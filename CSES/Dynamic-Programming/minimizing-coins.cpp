#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> coins(n);
    vector<int> min_sums(x + 1, -1);

    min_sums[0] = 0;

    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    sort(coins.begin(), coins.end());

    // iterate from 1 to x
    for (int i = 1; i <= x; i++) {
        // store the minimum number of coins for each case
        vector<int> temp(n, -1);

        // iterate over the coins
        for (int j = 0; j < n; j++) {
            if (i - coins[j] >= 0 && min_sums[i - coins[j]] != -1) {
                temp[j] = 1 + min_sums[i - coins[j]];
            }
        }

        int min = -1;

        for (int j = 0; j < n; j++) {
            if (temp[j] >= 1) {
                min = temp[j];
            }
        }
        for (int j = 0; j < n; j++) {
            if (temp[j] >= 1 && temp[j] < min) {
                min = temp[j];
            }
        }

        min_sums[i] = min;
    }

    cout << min_sums[x] << endl;

    return 0;
}