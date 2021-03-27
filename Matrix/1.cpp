#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int>> mat, int r, int c)
    {
        int row = 0;
        int col = 0;
        int i;
        vector<int> v;
        while (row < r && col < c)
        {
            for (i = row; i < c; i++)
                v.push_back(mat[row][i]);
            row++;
            for (i = row; i < r; i++)
                v.push_back(mat[i][c - 1]);
            c--;
            if (row < r)
            {
                for (i = c - 1; i >= col; i--)
                    v.push_back(mat[r - 1][i]);
                r--;
            }
            if (col < c)
            {
                for (i = r - 1; i >= row; i--)
                    v.push_back(mat[i][col]);
                col++;
            }
        }
        return v;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r);

        for (int i = 0; i < r; i++)
        {
            matrix[i].assign(c, 0);
            for (int j = 0; j < c; j++)
            {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;
    }
    return 0;
} // } Driver Code Ends