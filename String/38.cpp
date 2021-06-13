#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    string removeConsecutiveCharacter(string S)
    {
        stack<char> st;
        int i = 1, n = S.length();
        st.push(S[0]);
        while (i < n)
        {
            char curr = S[i];
            if (st.top() != curr)
                st.push(curr);
            i++;
        }
        string s = "";
        while (!st.empty())
        {
            s = st.top() + s;
            st.pop();
        }
        return s;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.removeConsecutiveCharacter(s) << endl;
    }
}

// } Driver Code Ends