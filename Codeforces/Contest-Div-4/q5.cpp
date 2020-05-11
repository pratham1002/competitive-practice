// http://codeforces.com/contest/1352/problem/F

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    for(int i=0; i<t; i++)
    {
        int n0, n1, n2;

        cin >> n0 >> n1 >> n2;

        string res="";

        for (int j = 0; j < n0; j++)
        {
            if(j==0)
                res.push_back('0');
            res.push_back('0');
        }

        for (int j = 0; j < n2; j++)
        {
            if(j==0)
                res.push_back('1');
            res.push_back('1');
        }

        if (n1 == 0)
        {
            cout << res << endl;
            continue;
        }
        if (n1 == 1)
        {
            if (n0 == 0)
                res.insert(0, "0");
            if (n2 == 0)
                res.push_back('1');
            cout << res << endl;
            continue;
        }
        if (n1 == 2)
        {
            // make n1 equal to 1 if it is not so
            if (n0 == 0)
                res.insert(0, "0");
            if (n2 == 0)
                res.push_back('1');
            res.push_back('0');
            cout << res << endl;
            continue;
        }
        else
        {   
            // n1>=2
            // make n1 equal to 1 if it is not so
            if (n0 == 0)
                res.insert(0, "0");
            if (n2 == 0)
                res.push_back('1');
            res.push_back('0');
            // current n1 is 2 for our result
            for (int j = 2; j < n1; j++)
            {
                if(j%2==0)
                    res.push_back('1');
                else
                    res.push_back('0');
            }
            cout << res << endl;
            continue;
        }
    }

    return 0;
}