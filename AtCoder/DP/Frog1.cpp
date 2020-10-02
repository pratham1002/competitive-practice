#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    int h[n + 1];
    vector<int> mem(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }

    mem[1] = 0;
    mem[2] = std::abs(h[1] - h[2]);

    for (int i = 3; i <= n; i++) {
        mem[i] = std::min(mem[i-2] + std::abs(h[i] - h[i - 2]), mem[i - 1] + std::abs(h[i] - h[i - 1]));
    }

    cout << mem[n] << endl;

    return 0;
}