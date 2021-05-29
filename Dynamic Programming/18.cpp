#include <bits/stdc++.h>
using namespace std;

int LCSof3(string A, string B, string C, int n1, int n2, int n3);
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n1, n2, n3;
        cin >> n1 >> n2 >> n3;
        string A, B, C;
        cin >> A >> B >> C;
        cout << LCSof3(A, B, C, n1, n2, n3) << endl;
    }
}
// Contributed By: Pranay Bansal
// } Driver Code Ends

int LCSof3(string s1, string s2, string s3, int x, int y, int z)
{
    int dp[x + 1][y + 1][z + 1];
    for (int i = 0; i <= x; i++)
    {
        for (int j = 0; j <= y; j++)
        {
            for (int k = 0; k <= z; k++)
            {
                if (i == 0 || j == 0 || k == 0)
                    dp[i][j][k] = 0;
                else if (s1[i - 1] == s2[j - 1] && s1[i - 1] == s3[k - 1])
                    dp[i][j][k] = 1 + dp[i - 1][j - 1][k - 1];
                else
                    dp[i][j][k] = max(dp[i][j][k - 1], max(dp[i - 1][j][k], dp[i][j - 1][k]));
            }
        }
    }

    return dp[x][y][z];
}