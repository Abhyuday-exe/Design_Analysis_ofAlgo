
#include <iostream>
using namespace std;

#define INF 99999

int main()
{
    int n, source;
    int cost[20][20], dist[20];
    int visited[20] = {0};

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter the cost adjacency matrix:\n";
    cout << "Enter 99999 if there is no edge.\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> cost[i][j];
        }
    }

    cout << "Enter source vertex (0 to " << n - 1 << "): ";
    cin >> source;

    for (int i = 0; i < n; i++)
    {
        dist[i] = cost[source][i];
    }

    dist[source] = 0;

    for (int count = 0; count < n; count++)
    {
        int minDist = INF;
        int u = -1;

        for (int i = 0; i < n; i++)
        {
            if (!visited[i] && dist[i] < minDist)
            {
                minDist = dist[i];
                u = i;
            }
        }

        if (u == -1)
            break;

        visited[u] = 1;

        for (int v = 0; v < n; v++)
        {
            if (!visited[v] &&
                cost[u][v] != INF &&
                dist[u] + cost[u][v] < dist[v])
            {
                dist[v] = dist[u] + cost[u][v];
            }
        }
    }

    cout << "\nShortest distances from vertex "
         << source << ":\n";

    for (int i = 0; i < n; i++)
    {
        if (dist[i] == INF)
            cout << "Vertex " << i << ": Unreachable\n";
        else
            cout << "Vertex " << i << ": " << dist[i] << endl;
    }

    return 0;
}

