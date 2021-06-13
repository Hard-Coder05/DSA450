
// Program to convert Roman Numerals to Numbers
#include <bits/stdc++.h>
using namespace std;

// Returns decimal value of roman numaral
int romanToDecimal(string &);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        cout << romanToDecimal(s) << endl;
    }
} // } Driver Code Ends

// User fuunction teemplate for C++

// str given roman number string
// Returns decimal value of roman numaral
int romanToDecimal(string &str)
{
    map<char, int> mp;
    mp['I'] = 1;
    mp['V'] = 5;
    mp['X'] = 10;
    mp['L'] = 50;
    mp['C'] = 100;
    mp['D'] = 500;
    mp['M'] = 1000;

    int i = str.length();
    int ans = 0;
    int prev = mp[str[i - 1]];
    bool sign = true;
    while (i--)
    {
        int curr = mp[str[i]];
        if (curr < prev)
        {
            sign = false;
        }
        if (curr > prev)
        {
            sign = true;
        }
        if (sign)
            ans += curr;
        else
            ans -= curr;
        prev = mp[str[i]];
    }
    return ans;
}