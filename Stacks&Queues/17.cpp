#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int m)
    {
        stack<pair<long long, int>> s;
        int i = 0;
        vector<int> lr;
        while (i < m)
        {
            if (s.empty())
                lr.push_back(-1);
            else if (s.top().first >= arr[i])
            {
                while (!s.empty() && s.top().first >= arr[i])
                    s.pop();
                if (!s.empty())
                    lr.push_back(s.top().second);
                else
                    lr.push_back(-1);
            }
            else
            {
                lr.push_back(s.top().second);
            }
            s.push(make_pair(arr[i], i));
            i++;
        }

        stack<pair<long long, int>> p;
        i = m;
        vector<int> rl;
        while (i--)
        {
            if (p.empty())
                rl.push_back(m);
            else if (p.top().first >= arr[i])
            {
                while (!p.empty() && p.top().first >= arr[i])
                    p.pop();
                if (!p.empty())
                    rl.push_back(p.top().second);
                else
                    rl.push_back(m);
            }
            else
            {
                rl.push_back(p.top().second);
            }
            p.push(make_pair(arr[i], i));
        }
        reverse(rl.begin(), rl.end());

        long long ans = INT_MIN;
        for (int i = 0; i < m; i++)
            ans = max(ans, arr[i] * (rl[i] - lr[i] - 1));

        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    long long t;

    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        long long arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.getMaxArea(arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends