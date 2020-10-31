#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;


    if (n == 1) {
        cout << 1 << endl;
    }
    else if (n < 4) {
        cout << "NO SOLUTION" << endl;
    }
    else {
        // go from 1, 3, 5, .... then n, n - 2, n - 4, ....
        int i;

        // n is odd
        if (n % 2 == 1) {
            i = n;
            while (i >= 1) {
                cout << i << " ";
                i -= 2;
            }
            i = n - 1;
            while (i >= 1) {
                cout << i << " ";
                i -= 2;
            }
            cout << endl;
        }
        // n is even
        if (n % 2 == 0) {
            i = n - 1;
            while (i >= 1) {
                cout << i << " ";
                i -= 2;
            }
            i = n;
            while (i >= 1) {
                cout << i << " ";
                i -= 2;
            }
        }
        cout << endl;
    }
    return 0;
}