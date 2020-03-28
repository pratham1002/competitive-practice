// https://www.codechef.com/problems/

#include <bits/stdc++.h>
#include <cstdio>
using namespace std;


int main() 
{
    int t;

    cin >> t;
    
    for (int i = 0; i < t; i++)
    {
        int a, b;
        cin >> a >> b;
        int p1, p2, p3, p4;

        if(a<10)
        {
            p1 = 0;
            p2 = a;
        }
        else
        {
            p2 = a % 10;
            p1 = (a / 10) % 10;
        }

        if(b<10)
        {
            p3 = 0;
            p4 = b;
        }
        else
        {
            p4 = b % 10;
            p3 = (b / 10) % 10;
        }

        int sum1, sum2, sum3;

        sum1 = a + b;
        sum2 = p2 * 10 + p1 * 10 + p3 + p4;
        sum3 = p4 * 10 + p3 * 10 + p1 + p2;

        if (sum1>=sum2 && sum1>=sum3)
            cout << sum1 << endl;
        else if(sum2>=sum1 && sum2>=sum3)
            cout << sum2 << endl;
        else
            cout << sum3 << endl;
    }

    return 0;

}