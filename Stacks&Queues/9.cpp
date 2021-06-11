#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n)
    {
        stack<long long> s;
        int j = n;
        vector<long long> ans;
        while (j--)
        {
            if (s.empty())
                ans.push_back(-1);
            else if (s.top() <= arr[j])
            {
                while (!s.empty() && s.top() <= arr[j])
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
        }
        reverse(ans.begin(), ans.end());
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
        vector<long long> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        Solution obj;
        vector<long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res)
            cout << i << " ";
        cout << endl;
    }
    return 0;
} // } Driver Code Ends