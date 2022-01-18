#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    //Function to return a list containing the DFS traversal of the graph.
    bool visited[10005];
    void dfs(vector<int> &ans, int curr, vector<int> adj[])
    {
        visited[curr] = true;
        ans.push_back(curr);

        for (auto &i : adj[curr])
            if (!visited[i])
                dfs(ans, i, adj);
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        for (int i = 0; i < V; i++)
            visited[i] = false;
        vector<int> ans;

        dfs(ans, 0, adj);

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
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
} // } Driver Code Ends