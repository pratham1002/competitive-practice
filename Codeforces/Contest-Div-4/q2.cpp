#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    for(int i=0; i<t; i++)
    {
        int k, n;

        cin >> n >> k;

        int res;

        // cout << "k = " << k << " n = " << n << endl;
        if (k % (n - 1) == 0)
            res = (k / (n - 1)) * n - 1;
        else
            res = (k / (n - 1)) * n + (k % (n - 1));

        cout << res << endl;
    }

    return 0;
}