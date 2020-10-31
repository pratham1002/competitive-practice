#include <bits/stdc++.h>

using namespace std;

int main() {
    string str;
    std::cin >> str;

    int current = 1, max = 1;

    int i = 1;

    while (i < str.length()) {
        if (str[i] == str[i-1])
        {
            current++;
            if (current > max) {
                max = current;
            }
        }
        else
        {
            current = 1;
        }
        i++;
    }

    cout << max <<endl;
    return 0;
}