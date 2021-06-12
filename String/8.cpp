#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    bool ispalindrome(int i, int j, string s)
    {
        while (j > i)
        {
            if (s[j] != s[i])
                return false;
            j--;
            i++;
        }
        return true;
    }
    string longestPalin(string S)
    {
        int len = S.length();
        int n = len;
        for (int i = len; i > 0; i--)
        {
            for (int j = 0; j + i - 1 < n; j++)
            {
                if (ispalindrome(j, j + i - 1, S))
                    return S.substr(j, i);
            }
        }
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.longestPalin(S) << endl;
    }
}
// Contributed By: Pranay Bansal
// } Driver Code Ends