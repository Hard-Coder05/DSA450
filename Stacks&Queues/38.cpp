// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    vector<int> leftSmaller(int n, int arr[])
    {
        stack<int> s;
        int j = 0;
        vector<int> ans;
        while (j < n)
        {
            if (s.empty())
                ans.push_back(-1);
            else if (s.top() >= arr[j])
            {
                while (!s.empty() && s.top() >= arr[j])
                    s.pop();
                if (!s.empty())
                    ans.push_back(s.top());
                else
                    ans.push_back(-1);
            }
            else
            {
                ans.push_back(s.top());
            }
            s.push(arr[j]);
            j++;
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
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        Solution ob;
        vector<int> ans = ob.leftSmaller(n, a);
        for (int i = 0; i < n; i++)
            cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
} // } Driver Code Ends