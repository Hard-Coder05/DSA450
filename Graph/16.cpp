#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    //Function to find the number of islands.
    int numIslands(vector<vector<char>> &grid)
    {
        int island = 0;
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1')
                {
                    q.push(make_pair(i, j));
                    while (!q.empty())
                    {
                        pair<int, int> top = q.front();
                        q.pop();
                        int i1 = top.first, j1 = top.second;
                        grid[top.first][top.second] = '0';
                        if (i1 - 1 >= 0 && j1 - 1 >= 0 && grid[i1 - 1][j1 - 1] == '1')
                        {
                            grid[i1 - 1][j1 - 1] = '0';
                            q.push(make_pair(i1 - 1, j1 - 1));
                        }
                        if (i1 - 1 >= 0 && grid[i1 - 1][j1] == '1')
                        {
                            grid[i1 - 1][j1] = '0';
                            q.push(make_pair(i1 - 1, j1));
                        }
                        if (i1 - 1 >= 0 && j1 + 1 < n && grid[i1 - 1][j1 + 1] == '1')
                        {
                            grid[i1 - 1][j1 + 1] = '0';
                            q.push(make_pair(i1 - 1, j1 + 1));
                        }
                        if (j1 - 1 >= 0 && grid[i1][j1 - 1] == '1')
                        {
                            grid[i1][j1 - 1] = '0';
                            q.push(make_pair(i1, j1 - 1));
                        }
                        if (j1 + 1 < n && grid[i1][j1 + 1] == '1')
                        {
                            grid[i1][j1 + 1] = '0';
                            q.push(make_pair(i1, j1 + 1));
                        }
                        if (i1 + 1 < m && j1 - 1 >= 0 && grid[i1 + 1][j1 - 1] == '1')
                        {
                            grid[i1 + 1][j1 - 1] = '0';
                            q.push(make_pair(i1 + 1, j1 - 1));
                        }
                        if (i1 + 1 < m && grid[i1 + 1][j1] == '1')
                        {
                            grid[i1 + 1][j1] = '0';
                            q.push(make_pair(i1 + 1, j1));
                        }
                        if (i1 + 1 < m && j1 + 1 < n && grid[i1 + 1][j1 + 1] == '1')
                        {
                            grid[i1 + 1][j1 + 1] = '0';
                            q.push(make_pair(i1 + 1, j1 + 1));
                        }
                    }

                    island++;
                }
            }
        }
        return island;
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
} // } Driver Code Ends