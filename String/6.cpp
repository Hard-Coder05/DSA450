#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    bool isInterleave(string A, string B, string C)
    {
        if (!A.length() && !B.length() && !C.length())
            return true;
        if (!C.length())
            return false;

        bool x = (A.length() && A[0] == C[0] && isInterleave(A.substr(1), B, C.substr(1)));
        bool y = (B.length() && B[0] == C[0] && isInterleave(A, B.substr(1), C.substr(1)));

        return x || y;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string a, b, c;
        cin >> a;
        cin >> b;
        cin >> c;
        Solution obj;
        cout << obj.isInterleave(a, b, c) << endl;
    }
    // your code goes here
    return 0;
} // } Driver Code Ends