#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> combinations(n+1, 0);

    // base case
    combinations[1] = 1;

    for (int i = 2; i <= n; i++) {
        if (i <= 6) {
            for (int j = 1; j < i; j++) {
                combinations[i] += combinations[i - j];
            }
            combinations[i] += 1;
        }
        else {
            for (int j = 1; j <= 6; j++) {
                combinations[i] = (combinations[i] + combinations[i - j]) % 1000000007;
            }
        } 
    }
    cout << combinations[n] << endl;

    return 0;
}