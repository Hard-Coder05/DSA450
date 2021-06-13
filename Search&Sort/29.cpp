#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    int findTrail(int n)
    {
        int count = 0;
        int i = 5;
        while (n / i > 0)
        {
            count += n / i;
            i *= 5;
        }
        return count;
    }

public:
    int findNum(int n)
    {
        int l = 1, r = 5 * n, ans = -1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (findTrail(mid) >= n)
            {
                ans = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.findNum(n) << endl;
    }
    return 0;
} // } Driver Code Ends