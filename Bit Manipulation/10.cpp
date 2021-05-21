#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<string> AllPossibleStrings(string s)
    {
        vector<string> ans;
        int n = s.length();
        for (int i = 0; i < (1 << n); i++)
        {
            string curr = "";
            int curri = i;
            int k = 0;
            while (curri > 0)
            {
                if (curri & 1)
                    curr += s[k];
                k++;
                curri = curri >> 1;
            }
            if (curr != "")
                ans.push_back(curr);
        }
        sort(ans.begin(), ans.end());
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
        string s;
        cin >> s;
        Solution ob;
        vector<string> res = ob.AllPossibleStrings(s);
        for (auto i : res)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
} // } Driver Code Ends