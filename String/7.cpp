#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    string lookandsay(long long n)
    {
        long long i = 1;
        string s = "1";
        while (i < n)
        {
            string now = "";
            long long curr = 1;
            char prev = s[0];
            for (long long a = 1; a < s.length(); a++)
            {
                if (s[a] == prev)
                    curr++;
                else
                {
                    now += to_string(curr);
                    now += prev;
                    curr = 1;
                    prev = s[a];
                }
            }
            now += to_string(curr);
            now += prev;
            s = now;
            i++;
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
        int n;
        cin >> n;
        Solution obj;
        cout << obj.lookandsay(n) << endl;
    }
    return 0;
} // } Driver Code Ends