#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int current=0, max=0;

    for(int i=0; i<n; i++)
    {
        int in, out;

        cin >> out >> in;

        current = current - out + in;

        if(current>max)
            max = current;
    }

    cout << max;
}