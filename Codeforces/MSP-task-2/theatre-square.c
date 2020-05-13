// http://codeforces.com/problemset/problem/1/A

#include <stdio.h>
#include <math.h>

int main()
{
    long int n, m, a;

    scanf("%ld %ld %ld", &n, &m, &a);

    printf("%lld", (long long int)ceil((double)n / a) * (long int)ceil((double)m / a));

    return 0;
}