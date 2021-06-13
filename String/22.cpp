// Counts Palindromic Subsequence in a given String
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    /*You are required to complete below method */
    long long int countPS(string str)
    {
        int n = str.length();
        long long int dp[n + 1][n + 1];

        memset(dp, (long long int)0, sizeof(dp));

        for (int i = 0; i < n; i++)
            dp[i][i] = (long long int)1;

        for (int l = 2; l <= n; l++)
        {
            for (int i = 0; i <= n - l; i++)
            {
                int k = l + i - 1;
                if (str[i] == str[k])
                    dp[i][k] = (dp[i][k - 1] + dp[i + 1][k] + 1) % 1000000007;
                else
                    dp[i][k] = (dp[i][k - 1] + dp[i + 1][k] - dp[i + 1][k - 1]) % 1000000007;
            }
        }

        if (dp[0][n - 1] < 0)
            return (1e9 + 7) + dp[0][n - 1];
        return dp[0][n - 1];
    }
};

// { Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout << ans << endl;
    }
} // } Driver Code Ends