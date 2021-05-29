#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    //Function to find the maximum number of cuts.

    int maximizeTheCuts(int l, int x, int y, int z)
    {
        int dp[l + 2];
        for (int i = 1; i <= l; i++)
            dp[i] = -1;

        dp[0] = 0;

        for (int i = 0; i <= l; i++)
        {

            if (dp[i] == -1)
                continue;

            if (i + x <= l)
                dp[i + x] = max(dp[i + x], 1 + dp[i]);
            if (i + y <= l)
                dp[i + y] = max(dp[i + y], 1 + dp[i]);
            if (i + z <= l)
                dp[i + z] = max(dp[i + z], 1 + dp[i]);
        }

        if (dp[l] == -1)
            dp[l] = 0;

        return dp[l];
    }
};

// { Driver Code Starts.
int main()
{

    //taking testcases
    int t;
    cin >> t;
    while (t--)
    {
        //taking length of line segment
        int n;
        cin >> n;

        //taking types of segments
        int x, y, z;
        cin >> x >> y >> z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout << obj.maximizeTheCuts(n, x, y, z) << endl;
    }

    return 0;
} // } Driver Code Ends