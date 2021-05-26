#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    long long dp[1002][1002];
    long long solve(int coin, int sum, int S[])
    {

        if (sum == 0)
            return dp[coin][sum] = 1;

        if (sum < 0)
            return 0;

        if (coin <= 0 && sum >= 1)
            return dp[coin][sum] = 0;

        if (dp[coin][sum] != -1)
            return dp[coin][sum];

        return dp[coin][sum] = solve(coin, sum - S[coin - 1], S) + solve(coin - 1, sum, S);
    }
    long long int count(int S[], int coin, int sum)
    {
        for (int i = 0; i < coin + 1; i++)
            for (int j = 0; j < sum + 1; j++)
                dp[i][j] = -1;
        solve(coin, sum, S);
        return dp[coin][sum];
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int arr[m];
        for (int i = 0; i < m; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.count(arr, m, n) << endl;
    }

    return 0;
} // } Driver Code Ends