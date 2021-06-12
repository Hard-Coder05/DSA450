#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends

/*You are required to complete this method*/

class Solution
{
public:
    int MAH(int arr[MAX][MAX], int m, int k)
    {

        stack<pair<int, int>> s;
        int i = 0;
        vector<int> lr;
        while (i < m)
        {
            if (s.empty())
                lr.push_back(-1);
            else if (s.top().first >= arr[k][i])
            {
                while (!s.empty() && s.top().first >= arr[k][i])
                    s.pop();
                if (!s.empty())
                    lr.push_back(s.top().second);
                else
                    lr.push_back(-1);
            }
            else
            {
                lr.push_back(s.top().second);
            }
            s.push(make_pair(arr[k][i], i));
            i++;
        }

        stack<pair<int, int>> p;
        i = m;
        vector<int> rl;
        while (i--)
        {
            if (p.empty())
                rl.push_back(m);
            else if (p.top().first >= arr[k][i])
            {
                while (!p.empty() && p.top().first >= arr[k][i])
                    p.pop();
                if (!p.empty())
                    rl.push_back(p.top().second);
                else
                    rl.push_back(m);
            }
            else
            {
                rl.push_back(p.top().second);
            }
            p.push(make_pair(arr[k][i], i));
        }
        reverse(rl.begin(), rl.end());

        int ans = INT_MIN;
        for (int i = 0; i < m; i++)
            ans = max(ans, arr[k][i] * (rl[i] - lr[i] - 1));

        return ans;
    }
    int maxArea(int arr[MAX][MAX], int n, int m)
    {
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (arr[i][j] != 0)
                    arr[i][j] = 1 + arr[i - 1][j];
            }
        }

        int ans = INT_MIN;
        for (int i = 0; i < n; i++)
            ans = max(ans, MAH(arr, m, i));

        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--)
    {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}
// } Driver Code Ends