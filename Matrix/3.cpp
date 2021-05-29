
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
public:
    int median(vector<vector<int>> &matrix, int r, int c)
    {

        map<int, int> mp;
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                mp[matrix[i][j]]++;

        int count = 0;

        for (auto &i : mp)
        {
            count += i.second;
            if (count >= ((r * c) / 2 + (r * c) % 2))
                return i.first;
        }
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
        vector<vector<int>> matrix(r, vector<int>(c));
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
                cin >> matrix[i][j];
        Solution obj;
        cout << obj.median(matrix, r, c) << endl;
    }
    return 0;
} // } Driver Code Ends