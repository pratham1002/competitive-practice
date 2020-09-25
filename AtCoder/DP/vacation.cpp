#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int n;
    cin >> n;

    vector<vector<int>> happiness(n, vector<int>(3, 0));
    vector<vector<int>> mem(n, vector<int>(3, 0));

    for (int i = 0; i < n; i++) 
    {
        cin >> happiness[i][0] >> happiness[i][1] >> happiness[i][2];
    }

    mem[0][0] = happiness[0][0];
    mem[0][1] = happiness[0][1];
    mem[0][2] = happiness[0][2];

    for (int i = 1; i  < n; i++) {
        mem[i][0] = happiness[i][0] + std::max(mem[i - 1][1], mem[i - 1][2]);
        mem[i][1] = happiness[i][1] + std::max(mem[i - 1][0], mem[i - 1][2]);
        mem[i][2] = happiness[i][2] + std::max(mem[i - 1][0], mem[i - 1][1]);
    }

    cout << std::max(mem[n-1][0], std::max(mem[n-1][1], mem[n-1][2])) << endl;

    return 0;
}