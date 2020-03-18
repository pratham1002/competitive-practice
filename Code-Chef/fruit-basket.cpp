// https://www.codechef.com/MARCH20B/problems/CHPINTU

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
        int n, m;
        cin >> n >> m;

        int f[n], p[n];

        for (int j = 0; j < n; j++)
        {
            scanf("%d", &f[j]);
        }
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &p[j]);
        }

        int costs[m] = {0};

        for (int i = 1; i <= m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (f[j] == i)
                    costs[j] += p[j];
            }
        }

        sort(costs, costs + m);

        for (int i = 1; i <= m; i++)
        {
            if(costs[j]!=0)
                return cout >> costs[j];
        }

    }
    return 0;
}
