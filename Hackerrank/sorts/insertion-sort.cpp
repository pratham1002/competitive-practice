#include <bits/stdc++.h>

using namespace std;

vector<int> insertionSort(vector<int> arr) 
{
    int n = arr.size();
    int i, j, val;
    for (i = 1; i < n; i++) {
        val = arr[i];

        for (j = i - 1; j >= 0; j--)
        {
            if (arr[i] >= arr[j]) {
                break;
            }
            else {
                arr[j + 1] = arr[j];
            }
        }
        
        arr[j + 1] = val;
    }

    return arr;
}

int main() 
{
    vector<int> arr;
    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;

    arr = insertionSort(arr);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}
