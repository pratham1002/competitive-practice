#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int n;
    cin >> n;
    
    int count = 0;

    char c1;

    cin >> c1;

    for(int i=1; i<n; i++)
    {
        char c;
        cin >> c;

        if(c == c1)
            count++;
        else
            c1=c;
    }

    cout << count;
}