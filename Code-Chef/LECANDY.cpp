// https://www.codechef.com/problems/LECANDY

#include <cstdio>
using namespace std;

int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    long t;

    scanf("%ld", &t);

    for (long i = 0; i < t; i++)
    {
        int n;
        long c;
        scanf("%d %ld", &n, &c);

        int sum = 0;

        for (int j = 0; j < n; j++)
        {
            int temp;
            scanf("%d", &temp);
            sum += temp;
        }

        if(sum>c)
            printf("Yes");
        else
            printf("No");
    }

    return 0;

}