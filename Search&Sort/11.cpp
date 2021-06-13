#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int>> fourSum(vector<int> &arr, int x)
    {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        vector<vector<int>> ans;
        for (int i = 0; i < n - 3; i++)
        {
            if (i > 0 && arr[i - 1] == arr[i])
                continue;
            int a = arr[i];
            for (int j = i + 1; j < n - 2; j++)
            {
                if (j > i + 1 && arr[j] == arr[j - 1])
                    continue;
                int b = arr[j];
                int l = j + 1, r = n - 1;
                while (l < r)
                {
                    if (l > j + 1 && arr[l] == arr[l - 1])
                    {
                        l++;
                        continue;
                    }
                    else if (r < n - 1 && arr[r] == arr[r + 1])
                    {
                        r--;
                        continue;
                    }
                    int curr = a + b + arr[l] + arr[r];
                    if (curr == x)
                    {
                        ans.push_back({a, b, arr[l], arr[r]});
                        l++;
                        r--;
                    }
                    else if (curr < x)
                        l++;
                    else
                        r--;
                }
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
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int>> ans = ob.fourSum(a, k);
        for (auto &v : ans)
        {
            for (int &u : v)
            {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty())
        {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
} // } Driver Code Ends