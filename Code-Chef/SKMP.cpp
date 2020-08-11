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

        // default case: insert at upper bound
        bool insert_at_upper = true;

        // find the first character not equal to haystack.front()
        for (int i = 0; i < needle.length(); i++) { 
            if (needle[i] == needle[0]) { 
                continue;
            } else if (needle[i] > needle[0]) { 
                insert_at_upper = true;
            } else { 
                insert_at_upper = false;
            }
        }

        if (insert_at_upper) { 
            // insert the needle at the last occurance of the starting character 
            // if the first character not equal haystack.front() is greater than haystack.front()

            int upper = upper_bound(haystack.begin(), haystack.end(), needle.front()) - haystack.begin();

            haystack.insert(upper, needle);
        } else { 
            // insert the needle at the first occurance of the starting character 
            // if the first character not equal haystack.front() is smaller than haystack.front()

            int lower = lower_bound(haystack.begin(), haystack.end(), needle.front()) - haystack.begin();

            haystack.insert(lower, needle);
        }

        cout << haystack << endl;
    }

    return 0;
}
