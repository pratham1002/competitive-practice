#include <bits/stdc++.h> 

using namespace std;

long long spiral(long long row, long long col) {
    // 1. row, even
    if (row > col && row % 2 == 0) {
        return row * row - col + 1;
    }
    // 2. row, odd
    if (row > col && row % 2 == 1) {
        return (row-1) * (row - 1) + col;
    }
    // 3. col, even
    if (col > row && col % 2 == 0) {
        return (col - 1) * (col - 1) + row;
    }
    // 4. col, odd
    if (col > row && col % 2 == 1) {
        return (col) * (col) - row + 1;
    }
    if (row == col) {
        return (row * row) - (row - 1);
    }

    return 0;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long row, col;
        cin >> row >> col;

        cout << spiral(row, col) << endl;
    }

    return 0;
}