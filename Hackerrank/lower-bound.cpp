// https://www.hackerrank.com/challenges/cpp-lower-bound/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> v;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int temp;
        scanf("%d", &temp);
        v.push_back(temp);
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; i++)
    {   
        int a;
        cin >> a;

        std::vector<int>::iterator low,up;
        low=std::lower_bound (v.begin(), v.end(), a);

        if((*low)==a)
            cout << "Yes " << (low- v.begin() +1) << "\n";
        else
            cout << "No " << (low- v.begin() +1) << "\n";
        
    }

    return 0;
}


