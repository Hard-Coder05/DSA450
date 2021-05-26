
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
public:
    int dp[105][10005];
    int solve(int n, int arr[], int sum)
    {

        if (sum == 0)
            return 1;

        if (sum < 0 || n <= 0)
            return 0;

        if (dp[n][sum] != -1)
            return dp[n][sum];

        if (arr[n - 1] > sum)
            return dp[n][sum] = solve(n - 1, arr, sum);
        else
            return dp[n][sum] = (solve(n - 1, arr, sum - arr[n - 1])) || (solve(n - 1, arr, sum));
    }
    bool isSubsetSum(int N, int arr[], int sum)
    {

        for (int i = 0; i <= N + 1; i++)
            for (int j = 0; j <= sum + 1; j++)
                dp[i][j] = -1;

        if (solve(N, arr, sum) == 1)
            return true;
        return false;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, sum;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }
        cin >> sum;

        Solution ob;
        cout << ob.isSubsetSum(N, arr, sum) << endl;
    }
    return 0;
}
// } Driver Code Ends