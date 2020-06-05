#include <bits/stdc++.h>

using namespace std;

// Complete the candies function below.
long candies(int n, vector<int> arr) {

    if (arr.size() == 1) {
        return 1;
    }

    vector<long> v(arr.size(), 1);
    
    for(long i = 1; i < arr.size(); i++)
    {
        if(arr[i]>arr[i-1])
        {
            if(v[i]<=v[i-1]) {
                // cout << "adding l to r " << v[i-1]+1 <<endl;
                v[i] = v[i-1]+1;
            }
        }
    }

    for(long i = arr.size()-2; i >= 0; i--)
    {
        if(arr[i]>arr[i+1])
        {
            if(v[i]<=v[i+1])
                v[i] = v[i+1]+1;
        }
    }

    // for(long i = 0; i < arr.size(); i++) {
    //     cout << v[i] << " ";
    // }

    // long sum = accumulate(v.begin(), v.end(), 0);

    long sum = 0;
    for(long i = 0; i < v.size(); i++) {
        sum = sum+ v[i];
        cout << sum << endl;
    }

    return sum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item;
        cin >> arr_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        arr[i] = arr_item;
    }

    long result = candies(n, arr);

    cout << result << "\n";

    fout.close();

    return 0;
}
