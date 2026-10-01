#include <iostream>
#include <climits>
using namespace std;

int main() {
    //Prims Algorithm
    int n;

    cout << "Enter number of vertices: ";
    cin >> n;

    int graph[20][20];

    cout << "Enter the weighted adjacency matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    int parent[20];
    int key[20];
    bool visited[20];

    for (int i = 0; i < n; i++) {
        key[i] = INT_MAX;
        visited[i] = false;
        parent[i] = -1;
    }

    key[0] = 0;

    int totalCost = 0;

    cout << "\nEdges in Minimum Spanning Tree:\n";

    for (int count = 0; count < n; count++) {

        int minValue = INT_MAX;
        int u = -1;

        for (int i = 0; i < n; i++) {
            if (!visited[i] && key[i] < minValue) {
                minValue = key[i];
                u = i;
            }
        }

        visited[u] = true;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] != 0 &&
                !visited[v] &&
                graph[u][v] < key[v]) {

                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    for (int i = 1; i < n; i++) {
        cout << parent[i] << " - " << i
             << " : " << graph[i][parent[i]] << endl;

        totalCost += graph[i][parent[i]];
    }

    cout << "Total weight of MST = " << totalCost << endl;

    return 0;
}