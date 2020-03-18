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
            scanf("%lld", &s[j]);
        }
  
        sort(s, s+n);
        
        long long int sum1 = 0;
        long long int sum2 = 0;
        
        for (int j = 0; j < k; j++)
        {
            sum1+=s[j];
        }
        for (int j = k; j < n; j++)
        {
            sum2+=s[j];
        }

        cout << abs(sum1-sum2) << "\n";
    }

    return 0;
}