// https://www.codechef.com/problems/COPS

#include <cstdio>
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;


int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    long t;

    scanf("%ld", &t);

    for (long z = 0; z < t; z++)
    {
        vector<int> lows;
        vector<int> highs;
        int M, x, y;
        scanf("%d %d %d",&M,&x,&y);

        int num_houses = x * y;
        bool houses[100];

        for (int j = 0; j < 100; j++)
        {
            houses[j] = true;
        }

        for (int j = 0; j < M; j++)
        {
            int temp;
            scanf("%d", &temp);
            temp--;
            int low = (temp - num_houses > 0) ? temp - num_houses : 0;
            // cout << low << endl;
            int high = (temp + num_houses < 100) ? temp + num_houses : 99;
            // cout << high << endl;

            int flag = 1;

            if(lows.size()==0)
            {
                lows.push_back(low);
                highs.push_back(high);
                continue;
            }

            for (int i = 0; i < lows.size(); i++)
            {
                if (low < lows[i] && high > lows[i])
                {
                    lows[i] = low;
                    flag = 0;
                }
                if (high > highs[i] && low < highs[i])
                {
                    highs[i] = high;
                    flag = 0;
                }
                if(low >= lows[i] && high <= highs[i])
                    flag = 0;
            }

            if(flag==1)
            {
                lows.push_back(low);
                highs.push_back(high);
            }

        }
        for (int i = 0; i < lows.size(); i++)
        {
            for (int j = lows[i]; j <= highs[i]; j++)
            {
                houses[j] = false;
            }
        }

        int count = 0;

        for (int j = 0; j < 100; j++)
        {
            if(houses[j] == true)
            {
                // cout << j << endl;
                count++;
            }
        }

        printf("%d\n", count);
    }

    return 0;

}