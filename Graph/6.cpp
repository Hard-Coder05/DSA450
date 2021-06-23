// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    vector<string> ans;
    bool isSafe(int x, int y, int n, vector<vector<int>> m, bool visited[][5])
    {
        if (x == -1 || x == n || y == -1 || y == n || visited[x][y] || m[x][y] == 0)
            return false;
        return true;
    }
    void findPathUtil(int x, int y, int n, vector<vector<int>> m, string &path, bool visited[][5])
    {

        if (x == -1 || x == n || y == -1 || y == n || visited[x][y] || m[x][y] == 0)
            return;

        if (x == n - 1 && y == n - 1)
        {
            ans.push_back(path);
            return;
        }

        visited[x][y] = true;

        if (isSafe(x + 1, y, n, m, visited))
        {
            path.push_back('D');
            findPathUtil(x + 1, y, n, m, path, visited);
            path.pop_back();
        }

        if (isSafe(x, y - 1, n, m, visited))
        {
            path.push_back('L');
            findPathUtil(x, y - 1, n, m, path, visited);
            path.pop_back();
        }

        if (isSafe(x, y + 1, n, m, visited))
        {
            path.push_back('R');
            findPathUtil(x, y + 1, n, m, path, visited);
            path.pop_back();
        }

        if (isSafe(x - 1, y, n, m, visited))
        {
            path.push_back('U');
            findPathUtil(x - 1, y, n, m, path, visited);
            path.pop_back();
        }

        visited[x][y] = false;
    }
    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        bool visited[n][5];
        string path;
        memset(visited, false, sizeof(visited));
        findPathUtil(0, 0, n, m, path, visited);
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
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
} // } Driver Code Ends