// http://codeforces.com/problemset/problem/490/C
// time limit exceeded.

#include <bits/stdc++.h>

using namespace std;

string public_key;

// checks divisibilty
bool is_divisible(int start_index, int end_index, int divisor)
{
    // try to divide as you would do manually by iterating

    if(public_key[start_index] == '0')
        return false;

    int temp = 0;

    for (int i = start_index; i < end_index; i++)
        temp = (temp * 10 + public_key[i] - '0') % divisor;

    return (temp == 0);
}

int main()
{
    // bool res = is_divisible("88", 8);

    // cout << res << endl;

    int a, b;

    // input
    cin >> public_key >> a >> b;

    // if conditions are satisfied, flag will be made 1
    int flag = 0;
    // cout << public_key << " " << a << " " << b << endl;
    int size = public_key.length();

    int remainder_left = 0;

    // cout << temp << endl;
    // partion the public key and pass the partitions to be checked for divisibility
    for (int i = 1; i < size; i++)
    {
        // the character is index i the first character of the left number

        // check divisiblility of left side within this loop itself
        remainder_left = (remainder_left * 10 + public_key[i-1] - '0') % a;

        // check for divisibility with a for right number and with b for left number
        if (remainder_left == 0 && is_divisible(i, size, b))
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