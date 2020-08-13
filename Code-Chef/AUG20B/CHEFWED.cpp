// https://www.codechef.com/AUG20B/problems/CHEFWED

#include <bits/stdc++.h>

using namespace std;

int calculateFights(const vector<int> &fam) {
    int inefficiency = 0;

    for (int i = 0; i < fam.size(); i++) {
        if (fam[i] > 1) {
            inefficiency += fam[i];
        }
    }

    return inefficiency;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, k;
        cin >> n >> k;

        vector<int> family(n);

        for (int i = 0; i < n; i++) {
            int f;
            cin >> f;
            family[i] = f - 1;
        }

        vector<int> hash_families(100, 0);

        // starting with just one table
        int inefficiency = k;

        // find the number of people in each family
        for (int i = 0; i < n; i++) {
            hash_families[family[i]] += 1;

            int inefficieny_due_to_fight = calculateFights(hash_families);

            // add new table if inefficieny > cost of new table
            if (inefficieny_due_to_fight >= k) {
                hash_families[family[i]] -= 1;
                inefficiency = inefficiency + k +  calculateFights(hash_families);
                fill(hash_families.begin(), hash_families.end(), 0);
                hash_families[family[i]] += 1;
            }
        }

        inefficiency = inefficiency + calculateFights(hash_families);

        cout << inefficiency << endl;
    }

    return 0;
}
