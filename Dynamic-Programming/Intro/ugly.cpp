#include <bits/stdc++.h>

using namespace std;

bool is_ugly(int n) {
    while (n % 2 == 0) { 
        n /= 2;
    }
    while (n % 3 == 0) { 
        n /= 3;
    }
    while (n % 5 == 0) { 
        n /= 5;
    }

    return n == 1 ? true : false;
}

// brute force
// int ugly(int n) {
//     int count = 0, p = 1;

//     while (count < n) { 
//         if (is_ugly(p++)) { 
//             count++;
//         }
//     }

//     return --p;
// }

// dynamic  programming
int ugly(int n) {
    vector<int> nums(n, 0);

    nums[0] = 1;

    int i_2 = 0, i_3 = 0, i_5 = 0;

    int next_2 = nums[i_2]*2;
    int next_3 = nums[i_3]*3;
    int next_5 = nums[i_5]*5;

    // multiply the numbers with 2, 3 and 5 to reach 150 numbers
    for (int i = 1; i < 150; i++) { 
        nums[i] = min(next_2, min(next_3, next_5));

        if (nums[i] == next_2) { 
            i_2++;
            next_2 = nums[i_2]*2;
        }
        if (nums[i] == next_3) { 
            i_3++;
            next_3 = nums[i_3]*3;
        }
        if (nums[i] == next_5) { 
            i_5++;
            next_5 = nums[i_5]*5;
        }
    }

    return nums[n-1];
}

int main() {
    int n = 150;

    cout << ugly(n) << endl;

    return 0;
}