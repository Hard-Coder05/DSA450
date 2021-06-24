#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int isNegativeWeightCycle(int n, vector<vector<int>> edges)
    {
        vector<int> distance(n, INT_MAX);
        distance[0] = 0;
        int rep = n - 1;
        while (rep--)
        {
            bool change = false;
            for (auto &curr_edge : edges)
            {
                int u = curr_edge[0];
                int v = curr_edge[1];
                int w = curr_edge[2];
                if (distance[u] != INT_MAX && distance[v] > distance[u] + w)
                {
                    distance[v] = distance[u] + w;
                    change = true;
                }
            }
            if (!change)
                break;
        }
        for (auto &curr_edge : edges)
        {
            int u = curr_edge[0];
            int v = curr_edge[1];
            int w = curr_edge[2];
            if (distance[u] != INT_MAX && distance[v] > distance[u] + w)
            {
                distance[v] = distance[u] + w;
                return 1;
            }
        }
        return 0;
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
        vector<vector<int>> edges;
        for (int i = 0; i < m; i++)
        {
            int x, y, z;
            cin >> x >> y >> z;
            edges.push_back({x, y, z});
        }
        Solution obj;
        int ans = obj.isNegativeWeightCycle(n, edges);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends