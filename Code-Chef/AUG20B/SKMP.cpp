// https://www.codechef.com/AUG20B/problems/SKMP

#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        string haystack, needle;
        cin >> haystack; // size = m
        cin >> needle; // size = n

        // lexographically sort the haystack
        sort(haystack.begin(), haystack.end()); // O(m log m)

        // create a hash map for the haystack
        vector<int> hash_haystack(26, 0); 
        for (int i = 0; i < haystack.length(); i++) { // O(m)
            hash_haystack[haystack[i] - 'a'] += 1;
        }

        // create a hash map for the needle
        vector<int> hash_needle(26, 0);
        for (int i = 0; i < needle.length(); i++) { // O(n)
            hash_needle[needle[i] - 'a'] += 1;
        }

        // sort the haystack as a counting sort after removing the letters of the needle
        haystack = "";
        for (int i = 0; i < 26; i++) { 
            haystack.append(hash_haystack[i] - hash_needle[i], 'a' + i); // O(m)
        }

        // initialise vector to store all inserts
        vector<string> inserts(2);

        // insert at the upperbound
        int upper = upper_bound(haystack.begin(), haystack.end(), needle.front()) - haystack.begin();
        string temp = haystack;
        inserts[0] = temp.insert(upper, needle);

        int lower = lower_bound(haystack.begin(), haystack.end(), needle.front()) - haystack.begin();
        temp = haystack;
        inserts[1] = temp.insert(lower, needle);

        // print the minimum 
        cout << *(min_element(inserts.begin(), inserts.end())) << endl;
    }

    return 0;
}
