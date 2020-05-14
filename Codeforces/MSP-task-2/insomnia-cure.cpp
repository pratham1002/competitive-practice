// http://codeforces.com/problemset/problem/148/A

#include <bits/stdc++.h>

using namespace std;

int lcm(int a, int b)
{
    int lcm, increment;
    if (a > b)
    {
        lcm = a; 
        increment = a;
    }
    else
    {
        lcm = b;
        increment = b;
    }
    while (1)
    {
        if (lcm % a == 0 && lcm % b == 0)
        {
            break;
        }
        lcm+=increment;
    }

    return lcm;
}

int main()
{
    int a, b, c, d, t;

    cin >> a >> b >> c >> d >> t;

    int na = t / a;
    int nb = t / b;
    int nc = t / c;
    int nd = t / d;

    int nab = t / lcm(a, b);
    int nbc = t / lcm(b, c);
    int ncd = t / lcm(c, d);
    int nda = t / lcm(d, a);
    int nac = t / lcm(a, c);
    int nbd = t / lcm(b, d);

    int nabc = t / lcm(lcm(a, b), c);
    int nbcd = t / lcm(lcm(b, c), d);
    int ncda = t / lcm(lcm(c, d), a);
    int ndab = t / lcm(lcm(d, a), b);

    int nabcd = t / lcm(lcm(a, b), lcm(c, d));

    int count = (na + nb + nc + nd) - (nab + nbc + ncd + nda + nac + nbd) + (nabc+nbcd+ncda+ndab) - (nabcd);

    cout << count;
}