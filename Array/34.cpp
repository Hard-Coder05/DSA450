//Proper question not found in GFG practice section
//But a similar question has been solved at its place

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int countMin(string str1)
    {
        string str2 = str1;
        reverse(str2.begin(), str2.end());
        int x = str1.length();

        int dp[x + 1][x + 1];

        for (int i = 0; i <= x; i++)
        {
            for (int j = 0; j <= x; j++)
            {
                if (i == 0 || j == 0)
                    dp[i][j] = 0;
                else if (str1[i - 1] == str2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return x - dp[x][x];
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
    return 0;
}

// } Driver Code Ends