// http://codeforces.com/problemset/problem/80/A

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};

    int n, m;
    cin >> n >> m;

    if(m == *(std::upper_bound(primes, primes+15, n)))
        cout << "YES\n";
    else
        cout << "NO\n";
}