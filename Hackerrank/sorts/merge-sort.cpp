#include <bits/stdc++.h>

using namespace std;

int min(int a, int b) 
{
    return a < b ? a : b;
}

vector<int> merge(vector<int> arr1, vector<int> arr2) 
{
    vector<int> arr;
    int n1 = arr1.size();
    int n2 = arr2.size();

    int p1 = 0, p2 = 0;

    while (p1 < n1 && p2 < n2) {
        if(arr1[p1] <= arr2[p2]) {
            arr.push_back(arr1[p1++]);
        }
        else {
            arr.push_back(arr2[p2++]);
        }
    }
    // insert remaining elements
    for(int i = p1; i < n1; i++) {
        arr.push_back(arr1[i]);
    }
    for(int i = p2; i < n2; i++) {
        arr.push_back(arr2[i]);
    }

    return arr;
}

vector<int> mergeSort(vector<int> arr) 
{
    int n = arr.size();

    // if the array cannot be divided anymore
    if (n == 1) {
        return arr;
    }
    // else split the array into 2 parts
    vector<int> arr1, arr2;

    for(int i = 0; i < n/2; i++) {
        arr1.push_back(arr[i]);
    }
    for (int i = n / 2; i < n; i++) {
        arr2.push_back(arr[i]);
    }
        
    return merge(mergeSort(arr1), mergeSort(arr2));
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

    arr = mergeSort(arr);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}