#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{

public:
    //Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[])
    {
        bool visited[V];
        for (int i = 0; i < V; i++)
            visited[i] = false;

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                queue<pair<int, int>> q;
                visited[i] = true;
                q.push({i, -1});
                while (!q.empty())
                {
                    int curr_node = q.front().first;
                    int parent = q.front().second;
                    q.pop();
                    for (int a : adj[curr_node])
                    {
                        if (!visited[a])
                        {
                            visited[a] = true;
                            q.push({a, curr_node});
                        }
                        else if (parent != a)
                            return true;
                    }
                }
            }
        }
        return false;
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
} // } Driver Code Ends