#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    //Function to return max value that can be put in knapsack of capacity W.
    int dp[1002][1002];
    int solve(int n, int W, int wt[], int val[])
    {
        if (n == 0 || W == 0)
            return dp[n][W] = 0;

        if (dp[n][W] != -1)
            return dp[n][W];

        if (W >= wt[n - 1])
        {
            return dp[n][W] = max(val[n - 1] + solve(n - 1, W - wt[n - 1], wt, val), solve(n - 1, W, wt, val));
        }
        else
        {
            return dp[n][W] = solve(n - 1, W, wt, val);
        }
    }
    int knapSack(int W, int wt[], int val[], int n)
    {
        for (int i = 0; i < n + 1; i++)
            for (int j = 0; j < W + 1; j++)
                dp[i][j] = -1;
        solve(n, W, wt, val);
        return dp[n][W];
    }
};

// { Driver Code Starts.

int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while (t--)
    {
        //reading number of elements and weight
        int n, w;
        cin >> n >> w;

        int val[n];
        int wt[n];

        //inserting the values
        for (int i = 0; i < n; i++)
            cin >> val[i];

        //inserting the weights
        for (int i = 0; i < n; i++)
            cin >> wt[i];
        Solution ob;
        //calling method knapSack()
        cout << ob.knapSack(w, wt, val, n) << endl;
    }
    return 0;
} // } Driver Code Ends