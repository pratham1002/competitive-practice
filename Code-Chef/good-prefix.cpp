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
        string str = "";
        //getline(cin, str);

        cin >> str;

        int k, x=0;

        //scanf("%d %d", &k, &x);

        cin >> k >> x;

        int hash[26] = {0};
        int count = 0;

        for (int j = 0; j < str.length(); j++)
        {
            int c = (int)str[j] - 97;
            hash[c] += 1;

            if(k==0 && hash[c]>x)
                break;

            if(hash[c]>x)
            {
                k--;
                count--;
            }

            count++;
        }

        printf("%d\n", count);
    }

    return 0;

}