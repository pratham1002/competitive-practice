#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string str = "";
    string longestSubstring = "";
    getline(cin, str);

    for (int i = 1; i < str.length(); i+=2)
    {
        str.insert(i, ".");
        // cout << str;
    }

    cout << str << endl;
    longestSubstring = str[0];

    for (int i = 0; i < str.length(); i++)
    {
        char mid = str[i];
        string substr = "";
        substr += mid;

        for (int j = 1; j <= i; j++)
        {
            string s1 = "", s2 = "";
            s1 += str[i - j];
            s2 += str[i + j];

            if (str[i + j] == str[i - j])
                substr = s1 + substr + s2;
            else
                break;     
            // cout << substr << "00" << endl;       
        }
        // cout << substr << "-1" << endl;
        for (int j = 0; j < substr.length(); j++)
        {
            if (substr[j] == '.')
                substr.erase(substr.begin() + j);
        }
        // cout << substr << endl;

        if(substr.length()>longestSubstring.length())
            longestSubstring = substr;
    }
    cout << longestSubstring;
    return 0;
}