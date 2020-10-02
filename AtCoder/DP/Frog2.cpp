#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;

    long long h[n + 1];
    vector<long long> mem(n + 1, LLONG_MAX);

    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }

    mem[1] = 0;

    for (int i = 2; i <= n; i++) {
        vector<long long> costs(k+1, LLONG_MAX);

            for (int j = 1; j <= k; j++) {
                if (i - j <= 0) {
                    break;
                }
                costs[j] = mem[i - j] + std::abs(h[i] - h[i - j]);
            }

            mem[i] = *(std::min_element(costs.begin(), costs.end()));
    }

    cout << mem[n] << endl;

    return 0;
}