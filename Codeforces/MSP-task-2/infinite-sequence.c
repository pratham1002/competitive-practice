// http://codeforces.com/problemset/problem/622/A

#include <stdio.h>

int main()
{
    long long int t;
    scanf("%lld", &t);
    long long int n = 1;

    while(n*(n+1)/2 < t)
        n++;

    printf("%lld\n", t - n*(n-1)/2);

    return 0;
}