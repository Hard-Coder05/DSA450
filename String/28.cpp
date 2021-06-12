#include <bits/stdc++.h>
using namespace std;

int minFlips(string s);
int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        cout << minFlips(s) << endl;
    }
}
// Contributed By: Pranay Bansal
// } Driver Code Ends

int minFlips(string S)
{
    int val[2] = {0};
    int n = S.length();
    for (int i = 0; i < n; i++)
    {
        //cout<<"val: "<<((i&1)^S[i])<<endl;
        if (((i & 1) ^ S[i]) - 48)
            val[1]++;
        else
            val[0]++;
    }
    return min(val[1], val[0]);
}