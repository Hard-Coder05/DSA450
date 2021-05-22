#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    void solve(int i, int n, string &S, set<string> &ans)
    {
        if (i >= n - 1)
            return;

        for (; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                swap(S[i], S[j]);
                ans.insert(S);
                solve(i + 1, n, S, ans);
                swap(S[i], S[j]);
            }
        }
    }
    vector<string> find_permutation(string S)
    {
        int n = S.length();
        set<string> ans;
        ans.insert(S);
        solve(0, n, S, ans);
        vector<string> final;
        for (auto &s : ans)
            final.push_back(s);
        return final;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S;
        cin >> S;
        Solution ob;
        vector<string> ans = ob.find_permutation(S);
        for (auto i : ans)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends