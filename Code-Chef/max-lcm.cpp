// https://www.codechef.com/problems/

#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

vector<int> primes;

// list all primes upto M 
void getPrimes()
{
    primes.push_back(2);

    for (int i = 3; i < 9999; i++)
    {
        int i1 = (int)sqrt(i);

        for (int j = 0; j < primes.size(); j++)
        {
            if (primes[j] > i1)
            {
                primes.push_back(i);
                break;
            }
            if(i%primes[j]==0)
                break;
        }
    }
}

int main() 
{
    getPrimes();
    int t;

    cin >> t;
    
    for (int i = 0; i < t; i++)
    {
        // if the the prime is a multiple of the number pop it out

        int n, m;

        cin >> n >> m;

        // cout << n << " " << m << endl;

        vector<int> primes2; //copy of primes

        for (int j = 0; j < primes.size(); j++)
        {   
            if(primes[j]>m)
                break;
            else
                primes2.push_back(primes[j]);
        }

        // for (int j = 0; j < primes2.size(); j++)
        // {
        //     cout << primes2[j] << " ";
        // }

        // cout << endl;

        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            // cout << x << " ";
            for (int k = 0; k < primes2.size(); k++)
            { 
                if(x%primes2[k]==0)
                    primes2.erase(primes2.begin() + k);
            }
        }

        // cout << endl;

        if (primes2.size() == 0)
            cout << "1" << endl;
        else 
            cout << primes2[primes2.size() - 1] << endl; // return largest prime left
    }

    return 0;
}