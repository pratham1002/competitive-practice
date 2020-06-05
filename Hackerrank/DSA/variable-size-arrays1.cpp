// https://www.hackerrank.com/challenges/variable-sized-arrays/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 

    int n, q;
    scanf("%d %d", &n, &q);

    vector<int> v[n];

    for(int i=0; i<n; i++)
    {   
        int a;
        scanf("%d", &a);

        for(int j=0; j<a; j++)
        {
            int temp;
            scanf("%d", &temp);
            v[i].push_back(temp);
        }
    }

    for(int i=0; i<q; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n",v[a][b]);
    }

    return 0;
}