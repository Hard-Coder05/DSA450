using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    set<string> allPossibleSubsequences(string s)
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
            if (curr != "" && curr.length() != 1)
                ans.push_back(curr);
        }
        sort(ans.begin(), ans.end());
        set<string> final;
        for (int i = 0; i < ans.size(); i++)
        {
            char first = ans[i][0];
            char last = ans[i][(ans[i].size()) - 1];
            if ((first == 'a' || first == 'e' || first == 'i' || first == 'o' || first == 'u') && (last != 'a' && last != 'e' && last != 'i' && last != 'o' && last != 'u'))
                final.insert(ans[i]);
        }
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
        set<string> ans = ob.allPossibleSubsequences(S);
        if (ans.size() == 0)
            cout << -1 << endl;
        else
        {
            for (auto i : ans)
                cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}
// } Driver Code Ends