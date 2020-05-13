// http://codeforces.com/problemset/problem/490/C
// time limit exceeded.

#include <bits/stdc++.h>

using namespace std;

// checks divisibilty
bool is_divisible(const string &num, int divisor)
{
    // try to divide as you would do manually by iterating

    if(num[0] == '0')
        return false;

    int temp = 0;

    for (int i = 0; i < num.length(); i++)
        temp = (temp * 10 + num[i] - '0') % divisor;

    return (temp == 0);
}

int main()
{
    // bool res = is_divisible("88", 8);

    // cout << res << endl;

    string public_key;

    int a, b;

    // input
    cin >> public_key >> a >> b;

    // if conditions are satisfied, flag will be made 1
    int flag = 0;
    // cout << public_key << " " << a << " " << b << endl;

    // partion the public key and pass the partitions to be checked for divisibility
    for(int i=1; i<public_key.length(); i++)
    {
        // the character is index i the first character of the left number

        // check for divisibility with a for right number
        if (is_divisible(public_key.substr(0, i), a) && is_divisible(public_key.substr(i), b))
        {
            flag = 1;
            cout << "YES" << endl;
            cout << public_key.substr(0, i) << endl;
            cout << public_key.substr(i) << endl;
            break;
        }
    }

    if(!flag)
        cout << "NO" << endl;

    return 0;
}