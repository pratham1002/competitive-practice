#include <bits/stdc++.h>
using namespace std;

// recursive solution
long long cost (long long n, long long k, long long h[], vector<long long> &mem) {
    if (mem[n] == LLONG_MAX) {
        if (n <= 1)
        {
            mem[n] = 0;
        }
        else 
        {
            vector<long long> costs(k+1, LLONG_MAX);

            for (int i = 1; i <= k; i++) {
                if (n - i <= 0) {
                    break;
                }
                costs[i] = cost(n - i, k, h, mem) + std::abs(h[n] - h[n - i]);
            }

            mem[n] = *(std::min_element(costs.begin(), costs.end()));
        }
    }
    return mem[n];
}

int main() {
    long long N, K;
    cin >> N >> K;

    long long heights[N + 1];
    vector<long long> mem(N + 1, LLONG_MAX);

    for (int i = 1; i <= N; i++) {
        cin >> heights[i];
    }

    cout << cost(N, K, heights, mem) << endl;

    return 0;
}