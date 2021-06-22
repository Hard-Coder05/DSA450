//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    int minValue(string s, int k)
    {
        map<char, int> mp;
        for (char c : s)
            mp[c]++;

        priority_queue<int> pq;
        for (auto &i : mp)
            pq.push(i.second);

        while (k > 0 && !pq.empty() && pq.top() > 0)
        {
            pq.push(pq.top() - 1);
            pq.pop();
            k--;
        }

        int ans = 0;
        while (!pq.empty())
        {
            ans += pow(pq.top(), 2);
            pq.pop();
        }
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
        string s;
        int k;
        cin >> s >> k;

        Solution ob;
        cout << ob.minValue(s, k) << "\n";
    }
    return 0;
} // } Driver Code Ends