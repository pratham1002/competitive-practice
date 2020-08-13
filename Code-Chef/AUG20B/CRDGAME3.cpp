// https://www.codechef.com/AUG20B/problems/CRDGAME3

#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) { 
        double c, r;
        cin >> c >> r;

        if (ceil(c / 9) == ceil(r / 9)) { 
            // rick cheats and wins
            cout << 1 << " " << ceil(c / 9) << endl;
        } else if (ceil(c / 9) < ceil(r / 9)) { 
            // chef wins
            cout << 0 << " " << ceil(c / 9) << endl;
        } else { 
            // ricl wins
            cout << 1 << " " << ceil(r / 9) << endl;
        }
    }

    return 0;
}