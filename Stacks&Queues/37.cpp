#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    string FirstNonRepeating(string A)
    {
        queue<char> q;
        int mp[26] = {0};
        string ans = "";
        int i = 0, n = A.length();
        while (i < n)
        {
            mp[A[i] - 'a']++;
            q.push(A[i]);

            while (!q.empty() && mp[q.front() - 'a'] > 1)
                q.pop();

            if (q.empty())
                ans += '#';
            else
                ans += q.front();
            i++;
        }
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        string A;
        cin >> A;
        Solution obj;
        string ans = obj.FirstNonRepeating(A);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends