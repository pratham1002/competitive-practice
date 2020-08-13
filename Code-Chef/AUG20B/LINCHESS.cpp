// https://www.codechef.com/AUG20B/problems/LINCHESS

#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) { 
        int N, K;

        cin >> N >> K;

        int max = -1;

        for (int i = 0; i < N; i++) { 
            int p;
            cin >> p;

            if (K % p == 0 && p > max) { 
                max = p;
            }
        }

        cout << max << endl;
    }

    return 0;
}