#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited)
{
    visited[node] = true;
    cout << node << " ";

    for (int neighbour : adj[node])
    {
        if (!visited[neighbour])
        {
            dfs(neighbour, adj, visited);
        }
    }
}

int main()
{
    int V, E;

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    vector<vector<int>> adj(V);
    vector<bool> visited(V, false);

    cout << "Enter the edges (u v):" << endl;

    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int components = 0;

    cout << "\nConnected Components:" << endl;

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            components++;

            cout << "Component " << components << ": ";
            dfs(i, adj, visited);
            cout << endl;
        }
    }

    cout << "\nTotal Connected Components = " << components << endl;

    return 0;
}



