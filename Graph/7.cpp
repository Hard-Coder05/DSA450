#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

struct cell
{
    int x, y;
    int dis;
    cell() {}
    cell(int x, int y, int dis)
        : x(x), y(y), dis(dis)
    {
    }
};
class Solution
{
    int dx[8] = {-2, -1, 1, 2, -2, -1, 1, 2};
    int dy[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
    bool isSafe(int i, int j, int n)
    {
        if (i >= 0 && j >= 0 && i < n && j < n)
            return true;
        return false;
    }

public:
    //Function to find out minimum steps Knight needs to reach target position.
    int minStepToReachTarget(vector<int> &KnightPos, vector<int> &TargetPos, int N)
    {
        bool mat[N][N];
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                mat[i][j] = false;

        mat[KnightPos[0] - 1][KnightPos[1] - 1] = true;
        queue<cell> q;
        q.push(cell(KnightPos[0] - 1, KnightPos[1] - 1, 0));

        while (!q.empty())
        {

            cell top = q.front();
            q.pop();
            if (top.x == TargetPos[0] - 1 && top.y == TargetPos[1] - 1)
                return top.dis;

            for (int a1 = 0; a1 < 8; a1++)
            {
                if (isSafe(top.x + dx[a1], top.y + dy[a1], N) && !mat[top.x + dx[a1]][top.y + dy[a1]])
                {
                    mat[top.x + dx[a1]][top.y + dy[a1]] = true;
                    q.push(cell(top.x + dx[a1], top.y + dy[a1], top.dis + 1));
                }
            }
        }
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        vector<int> KnightPos(2);
        vector<int> TargetPos(2);
        int N;
        cin >> N;
        cin >> KnightPos[0] >> KnightPos[1];
        cin >> TargetPos[0] >> TargetPos[1];
        Solution obj;
        int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends