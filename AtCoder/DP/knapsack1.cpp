#include <bits/stdc++.h>
 
using namespace std;
 
long long knapsack(int n, int w, long long items[][2], vector<vector<long long>> &mem) {
    if (mem[n][w] == 0) {
        if (n == 0 || w == 0) {
            mem[n][w] = 0;
        }
        else {
            int current_item_weight = items[n][0];
            if (current_item_weight > w) {
                mem[n][w] = knapsack(n - 1, w, items, mem);
            }
            else {
                mem[n][w] = std::max(knapsack(n - 1, w, items, mem), items[n][1] + knapsack(n - 1, w - items[n][0], items, mem));
            }
        }
    }
    return mem[n][w];
}
 
int main() {
  	int n, w;
  	std::cin >> n >> w;
 
    long long items[n+1][2];
 
    vector<vector<long long>> mem(n + 1, vector<long long>(w + 1, 0));
 
    for (int i = 1; i <= n; i++) {
        std::cin >> items[i][0] >> items[i][1];
    }
 
    std::cout << knapsack(n, w, items, mem) << endl;
 
    return 0;
}
