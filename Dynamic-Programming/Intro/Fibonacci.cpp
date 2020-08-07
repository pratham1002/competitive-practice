#include <bits/stdc++.h>
#define NIL -1
#define MAX 1000

using namespace std;

// recursive way to find the nth fibonacci number
int rec_fib (int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return rec_fib(n - 1) + rec_fib(n - 2);
    }
}

// using dynamic programming to store the results

// memoization (top down)
int memoization_dynamic_fib (int n) {
    static vector<int> mem(MAX, NIL);
    if (mem[n] == NIL)
    {
        if (n <= 1) {
            mem[n] = n;
        } else {
            mem[n] = memoization_dynamic_fib(n - 1) + memoization_dynamic_fib(n - 2);
        }
    }
    return mem[n];
}

// tabulation (bottom up) 
int tabulation_dynamic_fib (int n) {
    vector<int> mem(MAX);

    mem[0] = 0;
    mem[1] = 1;

    for (int i = 2; i <= n; i++) {
        mem[i] = mem[i - 1] + mem[i - 2];
    }
    return mem[n];
}

int main() {
    int n = 40;

    cout << memoization_dynamic_fib(40) << endl;

    cout << tabulation_dynamic_fib(40) << endl;
}