// https://www.codechef.com/submit/FCTRL

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    int n;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        long a;
        cin >> a;
        long p = 5, sum = 0;
        
        while(p<=a)
        {
            sum += a / p;
            p *= 5;
        }
        cout << sum << "\n";
    }
}