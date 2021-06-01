
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int sb(int arr[], int n, int x)
    {
        int j = 0, i = 0, curr = 0, ans = n;
        while (j < n)
        {
            curr += arr[j];
            if (curr <= x)
            {
                j++;
            }
            else
            {
                while (curr > x)
                {
                    ans = min(ans, j - i + 1);
                    curr -= arr[i];
                    i++;
                }
                j++;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution obj;
        cout << obj.sb(a, n, x) << endl;
    }
    return 0;
} // } Driver Code Ends