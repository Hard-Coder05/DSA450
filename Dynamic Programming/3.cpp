// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    long long int dp[1005][1005];
    long long int mod = 1000000007;
    int fact(int n, int r)
    {

        if (dp[n][r] != -1)
            return dp[n][r];

        if (r > n)
            return 0;

        if (r == 0 || r == n)
            return dp[n][r] = 1;

        return dp[n][r] = (fact(n - 1, r - 1) + fact(n - 1, r)) % mod;
    }
    int nCr(int n, int r)
    {
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= r; j++)
                dp[i][j] = -1;

        return fact(n, r);
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, r;
        cin >> n >> r;

        Solution ob;
        cout << ob.nCr(n, r) << endl;
    }
    return 0;
} // } Driver Code Ends