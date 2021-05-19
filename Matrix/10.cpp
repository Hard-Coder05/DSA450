// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int distinct(vector<vector<int>> M, int N)
    {
        map<int, int> m;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (m[M[i][j]] == i)
                    m[M[i][j]]++;

        int count = 0;

        for (auto &i : m)
            if (i.second == N)
                count++;

        return count;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        vector<vector<int>> M(N, vector<int>(N, 0));
        for (int i = 0; i < N * N; i++)
            cin >> M[i / N][i % N];

        Solution ob;
        cout << ob.distinct(M, N) << "\n";
    }
    return 0;
} // } Driver Code Ends