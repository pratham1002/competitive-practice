// http://codeforces.com/contest/1352/problem/D

#include <bits/stdc++.h>

using namespace std;

vector<int> candies;

int a, b, max_candies;

int movefp(int fp, int bp)
{
    // cout << "movefp fp = " << fp << endl;
    int current_sum=0;

    for(int i=fp; i<=bp; i++)
    {
        // cout << candies[i] << endl;
        current_sum += candies[i];

        if(current_sum>max_candies)
        {
            fp=i+1;
            break;
        }

        if(i==bp)
        {
            fp=bp+1;
            break;
        }
    }
    max_candies = current_sum;
    a += current_sum;
    return fp;
}

int movebp(int fp, int bp)
{
    // cout << "movefp bp = " << bp << endl;
    int current_sum=0;

    for(int i=bp; i>=fp; i--)
    {
        // cout << candies[i] << endl;
        current_sum += candies[i];

        if(current_sum>max_candies)
        {
            bp=i-1;
            break;
        }
        if(i==fp)
        {
            bp = fp - 1;
            break;
        }
    }
    max_candies = current_sum;
    b += current_sum;
    return bp;
}

int main()
{
    int t;
    cin >> t;

    for(int i=0; i<t; i++)
    {
        candies.clear();
        a = 0;
        b = 0;

        int n;
        cin >> n;

        for(int i=0; i<n; i++)
        {
            int num;
            cin >> num;
            candies.push_back(num);
        }

        // cout << candies.size() << endl;

        max_candies=0;

        int fp = 0;
        int bp=candies.size()-1;

        int turn = 0;
        int moves = 0;

        while(fp<=bp)
        {
            if(turn==0)
            {
                fp = movefp(fp, bp);
                // cout << "Max candies = " << max_candies << endl;
                moves++;
                turn = 1;
            }
            else if(turn==1)
            {
                bp = movebp(fp, bp);
                // cout << "Max candies = " << max_candies << endl;
                moves++;
                turn = 0;
            }
        }
        cout << moves << " " << a << " " << b << endl;
    }

    return 0;
}