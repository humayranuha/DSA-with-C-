// Bellman-Ford Algorithm with Path Reconstruction

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

#define INF INT_MAX

struct Edge
{
    int u, v, w;
};

void bellmanFord(int V, int E, vector<Edge> &edges, int source)
{
    vector<int> dist(V, INF);
    vector<int> parent(V, -1);

    dist[source] = 0;

    // Step 1: Relax all edges V-1 times
    for (int i = 1; i <= V - 1; i++)
    {
        bool updated = false;

        for (int j = 0; j < E; j++)
        {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;

            if (dist[u] != INF && dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                parent[v] = u;
                updated = true;
            }
        }

        cout << "Iteration " << i << ": ";
        for (int d : dist)
        {
            if (d == INF)
                cout << "INF ";
            else
                cout << d << " ";
        }
        cout << endl;

        if (!updated)
        {
            cout << "No changes - early termination!" << endl;
            break;
        }
    }

    // Step 2: Check for negative cycles
    for (int j = 0; j < E; j++)
    {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;

        if (dist[u] != INF && dist[u] + w < dist[v])
        {
            cout << "\nGraph contains negative weight cycle!" << endl;
            return;
        }
    }

    // Step 3: Print results
    cout << "\nShortest distances from source " << source << ":" << endl;
    cout << "----------------------------------------" << endl;

    for (int i = 0; i < V; i++)
    {
        cout << "To vertex " << i << ": ";

        if (dist[i] == INF)
        {
            cout << "No path" << endl;
        }
        else
        {
            cout << "Distance = " << dist[i] << ", Path: ";

            // Reconstruct path
            vector<int> path;
            for (int v = i; v != -1; v = parent[v])
            {
                path.push_back(v);
            }

            for (int j = path.size() - 1; j >= 0; j--)
            {
                cout << path[j];
                if (j > 0)
                    cout << " -> ";
            }
            cout << endl;
        }
    }
}

int main()
{
    int V = 5;
    int E = 5;

    vector<Edge> edges = {
        {0, 1, 5}, // 0 → 1, weight 5
        {0, 2, 4}, // 0 → 2, weight 4
        {1, 3, 3}, // 1 → 3, weight 3
        {2, 1, 6}, // 2 → 1, weight 6
        {3, 2, 2}  // 3 → 2, weight 2
    };

    bellmanFord(V, E, edges, 0);

    return 0;
}