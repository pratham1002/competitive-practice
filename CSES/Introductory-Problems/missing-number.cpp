#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n; 
    std::cin >> n;

    vector<int> hash(n, 0);

    for (int i = 0; i < n-1; i++) {
        int temp;
        cin >> temp;
        hash[temp - 1] = 1;
    }

    cout << std::find(hash.begin(), hash.end(), 0) - hash.begin() + 1;

    cout << endl;
    return 0;
}