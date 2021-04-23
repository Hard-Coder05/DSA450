// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    int getMinDiff(int arr[], int n, int k)
    {
        sort(arr, arr + n);
        int maxE = arr[n - 1];
        int minE = arr[0];
        int diff = maxE - minE;
        for (int i = 1; i < n; i++)
        {
            if (arr[i] >= k)
            {
                minE = min(arr[i] - k, arr[0] + k);
                maxE = max(arr[i - 1] + k, arr[n - 1] - k);
                diff = min(diff, maxE - minE);
            }
        }
        return diff;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends