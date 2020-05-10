#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    for(int i=0; i<t; i++)
    {
        int n;
        cin >> n;

        int count = 0;
        vector<int> summands;

        string s = "";

        while(n>0)
        {
            s.push_back((char)(n%10 + 48));
            n /= 10;
        }

        //cout << s << endl;

        int j;

        int k = 1;

        for (j = 0; j<s.size(); j++)
        {
            if(s[j]!='0')
            {
                summands.push_back(((int)s[j] - 48) * k);
            }

            k *= 10;
        }

        cout << summands.size() << endl;

        for(int p=0; p<summands.size(); p++)
            cout << summands[p] << " ";

        cout << endl;
    }
}