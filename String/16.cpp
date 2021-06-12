#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        stack<char> s;
        int i = 0;
        int n = x.length();
        while (i < n)
        {
            char curr = x[i];
            if (curr == '{' || curr == '[' || curr == '(')
            {
                s.push(curr);
            }
            else
            {
                if (s.empty())
                    return false;
                if (curr == ')' && s.top() != '(')
                    return false;
                if (curr == ']' && s.top() != '[')
                    return false;
                if (curr == '}' && s.top() != '{')
                    return false;
                s.pop();
            }
            i++;
        }
        if (s.empty())
            return true;
        return false;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    string a;
    cin >> t;
    while (t--)
    {
        cin >> a;
        Solution obj;
        if (obj.ispar(a))
            cout << "balanced" << endl;
        else
            cout << "not balanced" << endl;
    }
} // } Driver Code Ends