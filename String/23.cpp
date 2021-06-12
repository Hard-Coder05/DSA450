// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    int solve(int i, int j, int n, int m, vector<vector<char>> &mat, string target, int index)
    {
        int found = 0;
        if (i >= 0 && i <= n && j >= 0 &&
            j <= m && target[index] == mat[i][j])
        {

            char match = target[index];
            index += 1;
            mat[i][j] = 0;

            if (target[index] == 0)
            {
                found = 1;
            }
            else
            {
                found += solve(i + 1, j, n, m, mat, target, index);
                found += solve(i - 1, j, n, m, mat, target, index);
                found += solve(i, j + 1, n, m, mat, target, index);
                found += solve(i, j - 1, n, m, mat, target, index);
            }

            mat[i][j] = match;
        }
        return found;
    }
    int findOccurrence(vector<vector<char>> &mat, string target)
    {
        int ans = 0;
        int n = mat.size();
        int m = mat[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                ans += solve(i, j, n - 1, m - 1, mat, target, 0);
            }
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
        int R, C;
        cin >> R >> C;
        vector<vector<char>> mat(R);
        for (int i = 0; i < R; i++)
        {
            mat[i].resize(C);
            for (int j = 0; j < C; j++)
                cin >> mat[i][j];
        }
        string target;
        cin >> target;
        Solution obj;
        cout << obj.findOccurrence(mat, target) << endl;
    }
}
// } Driver Code Ends