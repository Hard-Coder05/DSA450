#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
#include <bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.

class Solution
{

public:
    int minimumCost(int arr[], int N, int W)
    {
        int dp[W + 1];

        for (int i = 0; i <= W; i++)
            dp[i] = -1;
        dp[0] = 0;

        for (int i = 0; i <= W; i++)
        {
            if (dp[i] == -1)
                continue;

            for (int j = 0; j < N; j++)
            {
                if (arr[j] == -1)
                    continue;
                if (i + j + 1 <= W)
                {
                    if (dp[i + j + 1] == -1)
                        dp[i + j + 1] = arr[j] + dp[i];
                    else
                        dp[i + j + 1] = min(dp[i + j + 1], arr[j] + dp[i]);
                }
                else
                    N--;
            }
        }

        return dp[W];
    }
};

// { Driver Code Starts.
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, w;
        cin >> n >> w;

        int a[n];

        for (int i = 0; i < n; i++)
            cin >> a[i];

        Solution ob;
        cout << ob.minimumCost(a, n, w) << "\n";
    }
    return 0;
} // } Driver Code Ends