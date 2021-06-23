#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
    bool visited[100005];
    bool recStack[100005];
    bool solve(int v,vector<int> adj[]){
        if(visited[v] == false)
        { 
            visited[v] = true;
            recStack[v] = true;  
            for(auto &i:adj[v])
            {
                if( !visited[i] && solve(i, adj) )
                    return true;
                else if (recStack[i])
                    return true;
            }
 
        }
        recStack[v] = false; 
        return false;
    }
    public:
	//Function to detect cycle in a directed graph.
	bool isCyclic(int V, vector<int> adj[]) 
	{ 
    for(int i = 0; i < V; i++)
    {
        visited[i] = false;
        recStack[i] = false;
    }
    for(int i = 0; i < V; i++)
        if (solve(i, adj))
            return true;
 
    return false;
	}
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends