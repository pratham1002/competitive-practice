#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono; 

// Complete the counterGame function below.
vector<long> powers; int size1=0;
#include <chrono> 


void findPowers()
{
    long i = 2;
    for (int j = 1; j <= 62; j++)
    {
        powers.push_back(i);
        i = i * 2;
    }
    size1=powers.size();
    cout << size1 << endl;
}

string counterGame(long n) 
{   
    cout << n << endl;
    int res = 1;

    while(n > 1)
    {
        long flag = 0;
        int max=size1-1;
        for (int i = max; i >= 0; i--)
        {   
            if(n == powers[i])
            {
                flag = 1;
                max=i-1;
                break;
            }
            if(powers[i]<n)
            {   
                flag = powers[i];
                max=i-1;
                break;
            }
        }
        if(flag==1)
            n/=2;
        else
            n -= flag;
        res++;
    }

    if (res % 2 == 1)
        return "Richard";
    else
        return "Louise";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));
    
    findPowers();

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        long n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        auto start = high_resolution_clock::now();
        string result = counterGame(n);
        auto stop = high_resolution_clock::now();
    
        auto duration = duration_cast<microseconds>(stop - start); 
  
        cout << "Time taken by function: "
            << duration.count() << " microseconds" << endl; 

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
