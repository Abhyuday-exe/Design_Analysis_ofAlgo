#include <iostream>
#include <algorithm>
using namespace std;

struct Edge {
    int u;
    int v;
    int weight;
};

// Find the parent of a vertex
int findParent(int parent[], int x) {
    if (parent[x] == x)
        return x;

    return findParent(parent, parent[x]);
}

// Join two sets
void unionSet(int parent[], int rank[], int u, int v) {

    u = findParent(parent, u);
    v = findParent(parent, v);

    if (u == v)
        return;

    if (rank[u] < rank[v]) {
        parent[u] = v;
    }
    else if (rank[u] > rank[v]) {
        parent[v] = u;
    }
    else {
        parent[v] = u;
        rank[u]++;
    }
}

bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

int main() {

    int n, e;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> e;

    Edge edges[100];

    cout << "Enter edges (u v weight):\n";

    for (int i = 0; i < e; i++) {
        cin >> edges[i].u
            >> edges[i].v
            >> edges[i].weight;
    }

    // Sort edges according to weight
    sort(edges, edges + e, compare);

    int parent[20];
    int rank[20];

    // Initially every vertex is its own set
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    int totalCost = 0;
    int edgeCount = 0;

    cout << "\nEdges in Minimum Spanning Tree:\n";

    for (int i = 0; i < e && edgeCount < n - 1; i++) {

        int u = edges[i].u;
        int v = edges[i].v;

        int parentU = findParent(parent, u);
        int parentV = findParent(parent, v);

        // If parents are different, no cycle is formed
        if (parentU != parentV) {

            cout << u << " - " << v
                 << " : " << edges[i].weight << endl;

            totalCost += edges[i].weight;
            edgeCount++;

            unionSet(parent, rank, u, v);
        }
    }

    cout << "Total weight of MST = "
         << totalCost << endl;

    return 0;
}