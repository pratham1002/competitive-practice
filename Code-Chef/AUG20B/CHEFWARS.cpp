// https://www.codechef.com/AUG20B/problems/CHEFWARS

#include <bits/stdc++.h>

using namespace std;

int fight(int h, int p) {
    if (h <= 0) { 
        return 1;
    } else if (p == 0) { 
        return 0;
    } else {
        return fight(h - p, p / 2);
    }
}

int main() {
    int N;
    cin >> N;

    while (N--) { 
        int h, p;
        cin >> h >> p;

        int r = fight(h, p);

        cout << r << endl;
    }

    return 0;
}