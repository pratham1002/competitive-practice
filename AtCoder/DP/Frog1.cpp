#include <bits/stdc++.h>
#define NIL -999999

using namespace std;

// recursive solution
int cost (int n, int h[], vector<int> &mem) {
    if (mem[n] == NIL) {
        if (n == 1)
        {
            mem[n] = 0;
        }
        else if (n == 2) 
        {
            mem[n] = std::abs(h[1] - h[2]);
        }
        else 
        {
            mem[n] = std::min(cost(n - 2, h, mem) + std::abs(h[n] - h[n - 2]), cost(n - 1, h, mem) + std::abs(h[n] - h[n - 1]));
        }
    }
    return mem[n];
}

int main() {
    int N;
    cin >> N;

    int heights[N + 1];
    vector<int> mem(N + 1, NIL);

    for (int i = 1; i <= N; i++) {
        cin >> heights[i];
    }

    cout << cost(N, heights, mem) << endl;

    return 0;
}