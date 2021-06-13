#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    bool solve(int i, int j, int row, int col, int direction, vector<vector<char>> grid, string word, int index)
    {
        bool ans = false;
        if (i >= 0 && j >= 0 && i < row && j < col && grid[i][j] == word[index])
        {
            if (index + 1 == word.length())
                return true;

            char match = word[index];
            grid[i][j] = 0;
            index++;
            if (direction == -1)
            {
                ans = ans || solve(i, j + 1, row, col, 1, grid, word, index);
                ans = ans || solve(i, j - 1, row, col, 2, grid, word, index);
                ans = ans || solve(i + 1, j, row, col, 3, grid, word, index);
                ans = ans || solve(i - 1, j, row, col, 4, grid, word, index);
                ans = ans || solve(i + 1, j + 1, row, col, 5, grid, word, index);
                ans = ans || solve(i + 1, j - 1, row, col, 6, grid, word, index);
                ans = ans || solve(i - 1, j + 1, row, col, 7, grid, word, index);
                ans = ans || solve(i - 1, j - 1, row, col, 8, grid, word, index);
            }
            else if (direction == 1)
                ans = ans || solve(i, j + 1, row, col, 1, grid, word, index);

            else if (direction == 2)
                ans = ans || solve(i, j - 1, row, col, 2, grid, word, index);

            else if (direction == 3)
                ans = ans || solve(i + 1, j, row, col, 3, grid, word, index);

            else if (direction == 4)
                ans = ans || solve(i - 1, j, row, col, 4, grid, word, index);

            else if (direction == 5)
                ans = ans || solve(i + 1, j + 1, row, col, 5, grid, word, index);

            else if (direction == 6)
                ans = ans || solve(i + 1, j - 1, row, col, 6, grid, word, index);

            else if (direction == 7)
                ans = ans || solve(i - 1, j + 1, row, col, 7, grid, word, index);

            else if (direction == 8)
                ans = ans || solve(i - 1, j - 1, row, col, 8, grid, word, index);

            grid[i][j] = match;
        }
        return ans;
    }
    vector<vector<int>> searchWord(vector<vector<char>> grid, string word)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (solve(i, j, n, m, -1, grid, word, 0))
                {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
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
        vector<vector<char>> grid(n, vector<char>(m, 'x'));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cin >> grid[i][j];
        }
        string word;
        cin >> word;
        Solution obj;
        vector<vector<int>> ans = obj.searchWord(grid, word);
        for (auto i : ans)
        {
            for (auto j : i)
                cout << j << " ";
            cout << "\n";
        }
        if (ans.size() == 0)
        {
            cout << "-1\n";
        }
    }
    return 0;
} // } Driver Code Ends