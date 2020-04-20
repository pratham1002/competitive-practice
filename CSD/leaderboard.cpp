#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);
// Complete the climbingLeaderboard function below.

// void remove(std::vector<int> &v)
// {
// 	auto end = v.end();
// 	for (auto it = v.begin(); it != end; ++it) {
// 		end = std::remove(it + 1, end, *it);
// 	}

// 	v.erase(end, v.end());
// }

vector<int> climbingLeaderboard(vector<int> scores, vector<int> alice) {

    vector<int> ranks;
    
    // remove duplicates scores

    scores.erase( unique( scores.begin(), scores.end() ), scores.end() );

    // for(int i =1; i<(int)scores.size(); i++) {
    //     if(scores[i]==scores[i-1])
    //         scores.erase(scores.begin()+i);
    // }

    reverse(scores.begin(), scores.end());

    for(int i=0; i<(int)alice.size(); i++) {

        ranks.push_back(scores.end()-upper_bound(scores.begin(), scores.end(), alice[i])+1);

        // // corner cases

        // if(alice[i]>=(scores.front())) {
        //     ranks.push_back(1);
        //     continue;
        // }

        // if(alice[i]<=(scores.back())){
        //     if(alice[i]==scores.back())
        //         ranks.push_back((int)scores.size());
        //     else
        //         ranks.push_back((int)scores.size()+1);
        //     continue;
        // }
        
        // int front=0;
        // int back=(int)scores.size() - 1;

        // // binary search

        // int key = alice[i];
        
        // while(back>front) {
        //     int mid=(front+back)/2;

        //     if((alice[i]<scores[mid] && alice[i]>=scores[mid+1])) {
        //         ranks.push_back(mid+2);    
        //         break;   
        //     }
        //     else if(alice[i]>=scores[mid] && alice[i]<scores[mid-1]) {
        //         ranks.push_back(mid+1);    
        //         break;
        //     }
        //     else if(key < scores[mid]) {
        //         front=mid+1;
        //     }
        //     else if(key > scores[mid]) {
        //         back=mid-1;
        //     }
        // }
    }

    return ranks;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int scores_count;
    cin >> scores_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string scores_temp_temp;
    getline(cin, scores_temp_temp);

    vector<string> scores_temp = split_string(scores_temp_temp);

    vector<int> scores(scores_count);

    for (int i = 0; i < scores_count; i++) {
        int scores_item = stoi(scores_temp[i]);

        scores[i] = scores_item;
    }

    int alice_count;
    cin >> alice_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string alice_temp_temp;
    getline(cin, alice_temp_temp);

    vector<string> alice_temp = split_string(alice_temp_temp);

    vector<int> alice(alice_count);

    for (int i = 0; i < alice_count; i++) {
        int alice_item = stoi(alice_temp[i]);

        alice[i] = alice_item;
    }

    vector<int> result = climbingLeaderboard(scores, alice);

    for (int i = 0; i < (int)result.size(); i++) {
        fout << result[i];

        if (i != (int)result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
