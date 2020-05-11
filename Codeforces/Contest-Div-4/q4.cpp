// http://codeforces.com/contest/1352/problem/E

#include <bits/stdc++.h>

using namespace std;

vector<int> arr;

int checkSpecial(int num)
{
    //cout << "num = " << num << endl;
    if (arr.size() == 0)
        return 0;

    int fp = 0;
    int k = 0;
    int sum = arr[fp];
    for (int i = 1; i< arr.size(); i++)
    {
        //cout << "sum = " << sum << endl;
        sum += arr[i];
        while (sum > num)
        {
            sum = sum - arr[fp];
            fp += 1;
        }
        if (sum == num && fp!=i)
        {
            k = 1;
            break;
        }
    }

    // if(k)
    //     cout << "yes " << num << endl;

    return k;
}

int main()
{
    int t;
    cin >> t;
    // cout << t;
    for (int i = 0; i < t; i++)
    {
        int count = 0;
        arr.clear();
        int n;
        cin >> n;

        for(int j=0; j<n; j++)
        {
            int num;
            cin >> num;
            arr.push_back(num);
        }

        for(int j=0; j<arr.size(); j++)
        {
            count += checkSpecial(arr[j]);
        }

        cout << count << endl;
    }

    return 0;
}