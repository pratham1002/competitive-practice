// https://www.codechef.com/MAXDIFF

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;


int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    int t;

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int k, n;
        cin >> n >> k;

        int s[n];

        for (int j = 0; j < n; j++)
        {
            scanf("%d", &s[j]);
        }
  
        sort(s, s+n);

        cout << abs(accumulate(arr, arr + k) - accumulate(arr + k, arr + n)) << "\n";
    }

    return 0;
}