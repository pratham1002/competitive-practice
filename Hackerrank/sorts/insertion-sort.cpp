#include <bits/stdc++.h>

using namespace std;

vector<int> insertionSort(vector<int> arr) 
{
    int i,j;
    int value;
    for (i = 1; i < arr.size(); i++)
    {
        value = arr[i];
        j = i - 1;
        while (j >= 0 && value < arr[j])
        {
            arr[j + 1] = arr[j];
            j -= 1;
        }
        arr[j + 1] = value;
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
