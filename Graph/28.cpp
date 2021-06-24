//Using BFS
//
//
//
//
//
//
//
#include <bits/stdc++.h>
using namespace std;

bool isBipartite(int V, vector<int> adj[])
{
    vector<int> coloured(V, -1);
    queue<pair<int, int>> q;
    for (int i = 0; i < V; i++)
    {
        if (coloured[i] == -1)
        {
            q.push({i, 0});
            coloured[i] = 0;
            while (!q.empty())
            {
                pair<int, int> top = q.front();
                q.pop();
                for (int &a : adj[top.first])
                {
                    if (coloured[a] == -1)
                    {
                        q.push({a, top.second ^ 1});
                        coloured[a] = top.second ^ 1;
                    }
                    else
                    {
                        if (coloured[a] != top.second ^ 1)
                            return false;
                    }
                }
            }
        }
    }
    return true;
}

//Using DFS
//
//
//
//
//
