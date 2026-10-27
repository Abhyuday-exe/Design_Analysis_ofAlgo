
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Edge {
    int u, v, wt;
};

void bellmanFord(int V, int E, vector<Edge>& edges, int src) {
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    // Relax all edges V-1 times
    for (int i = 1; i < V; i++) {
        for (auto e : edges) {
            if (dist[e.u] != INT_MAX &&
                dist[e.u] + e.wt < dist[e.v]) {
                dist[e.v] = dist[e.u] + e.wt;
            }
        }
    }

    // Check for negative-weight cycle
    for (auto e : edges) {
        if (dist[e.u] != INT_MAX &&
            dist[e.u] + e.wt < dist[e.v]) {
            cout << "Negative weight cycle detected!" << endl;
            return;
        }
    }

    cout << "Vertex\tShortest Distance\n";
    for (int i = 0; i < V; i++) {
        cout << i << "\t";
        if (dist[i] == INT_MAX)
            cout << "INF";
        else
            cout << dist[i];
        cout << endl;
    }
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<Edge> edges(E);

    cout << "Enter edges (source destination weight):\n";
    for (int i = 0; i < E; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].wt;
    }

    int src;
    cout << "Enter source vertex: ";
    cin >> src;

    bellmanFord(V, E, edges, src);

    return 0;
}
