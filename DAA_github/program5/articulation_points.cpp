#include <iostream>
#include <vector>
using namespace std;

void dfs(int u, int parent, vector<vector<int>>& adj,
         vector<int>& disc, vector<int>& low,
         vector<bool>& visited, vector<bool>& ap, int& timer)
{
    visited[u] = true;
    disc[u] = low[u] = timer++;

    int children = 0;

    for (int v : adj[u])
    {
        if (v == parent)
            continue;

        if (!visited[v])
        {
            children++;

            dfs(v, u, adj, disc, low, visited, ap, timer);

            low[u] = min(low[u], low[v]);

            if (parent != -1 && low[v] >= disc[u])
                ap[u] = true;
        }
        else
        {
            low[u] = min(low[u], disc[v]);
        }
    }

    if (parent == -1 && children > 1)
        ap[u] = true;
}

int main()
{
    int V = 5;

    vector<vector<int>> adj(V);

    adj[0].push_back(1);
    adj[1].push_back(0);

    adj[1].push_back(2);
    adj[2].push_back(1);

    adj[1].push_back(3);
    adj[3].push_back(1);

    adj[3].push_back(4);
    adj[4].push_back(3);

    vector<int> disc(V, -1);
    vector<int> low(V, -1);

    vector<bool> visited(V, false);
    vector<bool> ap(V, false);

    int timer = 0;

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
            dfs(i, -1, adj, disc, low, visited, ap, timer);
    }

    cout << "Articulation Points: ";

    for (int i = 0; i < V; i++)
    {
        if (ap[i])
            cout << i << " ";
    }

    return 0;
}