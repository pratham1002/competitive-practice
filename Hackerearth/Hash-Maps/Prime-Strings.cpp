#include <bits/stdc++.h>

using namespace std;

vector<int> primes;

void getPrimes(int n)
{

    primes.erase(primes.begin(), primes.end());
    primes.push_back(2);

    for (int i = 3; i <= sqrt(n); i++)
    {
        int i1 = (int)sqrt(i);

        for (int j = 0; j < primes.size(); j++)
        {
            if (primes[j] > i1)
            {
                primes.push_back(i);
                break;
            }
            if(i%primes[j]==0)
                break;
        }
    }
}

bool isPrimeNumber(int n)
{
    // cout << "Checking Prime" << n << endl;
    if (n == 2)
        return true;

    if(n==1)
        return false;

    getPrimes(n);

    for(int i=0; i<primes.size(); i++)
    {
        // cout << primes[i] << " ";
        if (n % primes[i] == 0)
            return false;
    }

    return true;
}

string isPrimeString(string str) 
{
    int hashMap[26]={0};

    for(int i=0; i<str.length(); i++) 
    {
        hashMap[(int) str[i] % 97] += 1;
    }

    // cout << "Hash Map" << endl;

    // for(int i=0; i<26; i++) 
    // {
    //     cout << hashMap[i] << " ";
    // }
    // cout << endl;

    int no_of_char=0;

    for(int i=0; i<26; i++) 
    {
        if(hashMap[i]!=0) 
        {
            // cout << hashMap[i] << " ";
            no_of_char++;

            if(!isPrimeNumber(hashMap[i]))
            {
                cout << endl;
                return "NO";
            }
        }
    }

    // cout << "no_of_char = " << no_of_char << " ";

    if(!isPrimeNumber(no_of_char))
    {
        return "NO";
    }
    else
    {
        return "YES";
    }
}

int main() 
{
    int T;

    cin >> T;

    for(int i=0; i<T; i++) 
    {
        string str;
        cin >> str;
        cout << isPrimeString(str) << endl;
    }
}