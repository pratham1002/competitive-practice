#include <bits/stdc++.h>

using namespace std;

// Complete the crosswordPuzzle function below.

vector<string> tryFit(vector<string> crossword, string word, int i2, int j2, int i1, int j1) 
{
    // cout << "tryFit" << endl;
    vector<string> error;
    error.push_back("0");

    // for horizontal
    if(i1==i2) 
    {
        // cout << "Horizontal Fit attempt" << endl;
        int i = i1;
        for (int j = j1; j < j2; j++)
        {
            cout << crossword[i][j] << " ";
            if (crossword[i][j] == '-')
                crossword[i][j] = word[j - j1];

            else if(crossword[i][j]==word[j-j1])
                crossword[i][j] = word[j - j1];
            
            else
            {
                // cout << "Can't fit" << endl;
                return error;
            }
        }
    }

    // for vertical
    if(j1==j2)
    {
        // cout << "Vertical Fit attempt" << endl;
        int j = j1;
        for(int i = i1; i <i2; i++)
        {
            if(crossword[i][j]=='-')
                crossword[i][j] = word[i - i1];
            else if(crossword[i][j]==word[i-i1])
                crossword[i][j] = word[i - i1];
            else
            {
                // cout << "Can't fit" << endl;
                return error;
            }
        }
    }

    // cout << "Fit success" << endl;
    return crossword;
}

vector<vector<string>> findFit(vector<string> crossword, string word, char delimiter) 
{   
    // cout << "findFit" << endl;

    // cout << word << endl;

    // cout << word.length() << endl;

    vector<vector<string>> fits;

    // finding fit in horizontal spaces
    for(int i = 0; i < 10; i++) 
    {
        string str=crossword[i];
        str.insert(str.begin(), delimiter);
        str.push_back(delimiter);

        // cout << "Horizontal Row: " << str << endl;

        int count = 0;

        for(int j=1; j<11; j++) 
        {
            if (str[j] != delimiter && str[j + 1] != delimiter)
                count++;    
            else if(str[j]!=delimiter && str[j+1]==delimiter) 
            {
                ++count;
                // cout << "Count = " << count << endl;
                if (word.length() == count)
                {
                    vector<string> fit = tryFit(crossword, word, i, j, i, j-count);
                    if(fit[0].compare("0") != 0)
                        fits.push_back(fit);
                }
                count = 0;
            }
        }
    }

    // find fit in vertical spaces
    for(int j=0; j<10; j++)
    {
        string str;
        str.push_back(delimiter);
        for (int i = 0; i < 10; i++)
            str.push_back(crossword[i][j]);
        str.push_back(delimiter);

        // cout << "Vertical column: " << str << endl;

        int count =0;

        for(int i=1; i<11; i++)
        {
            // cout << crossword[i][j] << " ";
            if (str[i] != delimiter && str[i + 1] != delimiter)
                count++;   
            else if(str[i]!=delimiter && str[i+1]==delimiter) 
            {
                ++count;
                cout << "Count = " << count << endl;
                if(word.length() == count) 
                {
                    vector<string> fit = tryFit(crossword, word, i, j, i-count, j);
                    if(fit[0].compare("0") != 0)
                        fits.push_back(fit);
                }
                count = 0;
            } 
        }
    }
    return fits;
}

vector<string> solve_crossword(vector<string> crossword, vector<string> words, char delimiter) 
{
    vector<string> error;
    error.push_back("0");

    if(words.size() == 0)
        return crossword;

    else
    {
        vector<vector<string>> fits=findFit(crossword, words[0], delimiter);

        if(fits.size() == 0)
            return error;
        else
        {        
            words.erase(words.begin());
            for(int i = 0; i < (int) fits.size(); i++)
            {                
                vector<string> trial = solve_crossword(fits[i], words, delimiter);   
                if(trial[0].compare("0") != 0)
                    return trial;
            }
            return error;
        }
    }
}

vector<string> crosswordPuzzle(vector<string> crossword, string str) {

    char delimiter='-';

    for(int i=0; i<crossword.size(); i++) 
    {
        for (int j = 0; j < crossword[i].size(); j++)
        {
            if(crossword[i][j] != '-')
            {
                delimiter = crossword[i][j];
                break;
            }
        }
        if(delimiter!='-')
            break;
    }

    vector<string> words;
    vector<int> word_lengths;

    // string spliting

    string s;

    str.push_back(';');
    for(int i=0; i<str.length(); i++) {
        if(str[i]==';') {
            words.push_back(s);
            word_lengths.push_back(s.length());
            s="";
        }
        else {
            s.push_back(str[i]);
        }
    }

    // // find all spaces
    // vector<vector<int>> spaces=findSpaces(crossword);

    crossword = solve_crossword(crossword, words, delimiter);

    return crossword;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<string> crossword(10);

    for (int i = 0; i < 10; i++) {
        string crossword_item;
        getline(cin, crossword_item);

        crossword[i] = crossword_item;
    }

    string words;
    getline(cin, words);

    vector<string> result = crosswordPuzzle(crossword, words);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
