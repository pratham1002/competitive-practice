#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;

    int steps = 0;

    while(1)
    {
        if (a == b) {
            break;
        }
        // if both divisible by same number then dont divide by that

        // first find the larger number
        if (a > b) {
            if (a % 2 == 0 && b % 2 != 0) {
                a /= 2;
                steps += 1;
                continue;
            }
            if (a % 3 == 0 && b % 3 != 0) {
                a /= 3;
                steps += 1;
                continue;
            }
            if (a % 5 == 0 && b % 5 != 0) {
                a /= 5;
                steps += 1;
                continue;
            }
            // if number is indivisible;
            if (a % 2 == 0) {
                a /= 5;
                steps += 1;
                continue;
            }
            if (a % 3 == 0) {
                a /= 3;
                steps += 1;
                continue;
            }
            if (a % 5 == 0) {
                a /= 2;
                steps += 1;
                continue;
            }

            break;
        }
        else {
            if (b % 2 == 0 && a % 2 != 0) {
                b /= 2;
                steps += 1;
                continue;
            }
            if (b % 3 == 0 && a % 3 != 0) {
                b /= 3;
                steps += 1;
                continue;
            }
            if (b % 5 == 0 && a % 5 != 0) {
                b /= 5;
                steps += 1;
                continue;
            }
            if (b % 2 == 0) {
                b /= 2;
                steps += 1;
                continue;
            }
            if (b % 3 == 0) {
                b /= 3;
                steps += 1;
                continue;
            }
            if (b % 5 == 0) {
                b /= 5;
                steps += 1;
                continue;
            }

            // if number is indivisible;
            break;
        }

        // if either a or b is zero then stop
        if (a == 0 || b == 0) {
            break;
        }
    }

    if (a == b) {
        cout << steps << endl;
    }
    else {
        cout << -1 << endl;
    }

    return 0;
}