// https://www.codechef.com/AUG20B/problems/SKMP

#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        string haystack, needle;
        cin >> haystack;
        cin >> needle;

        // lexographically sort the haystack
        sort(haystack.begin(), haystack.end());

        // delete the characters in the needle from the haystack
        for (int i = 0; i < needle.length(); i++) {
            haystack.erase(find(haystack.begin(), haystack.end(), needle[i]));
        }

        vector<string> inserts(haystack.length() + 1);

        // insert at all locations in the haystack 
        for (int i = 0; i < haystack.length(); i++) {
            string temp = haystack;
            inserts[i] = temp.insert(i, needle);
        }

        string temp = haystack;
        inserts[haystack.length()] = temp.append(needle);

        // sort the inserts in lexographical order
        sort(inserts.begin(), inserts.end());

        // find the minimum
        cout << inserts.front() << endl;
    }

    return 0;
}
