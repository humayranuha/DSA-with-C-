// Simple Kruskal's Algorithm in C++

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge
{
    int u, v, w;
};

// Sort edges by weight
bool compare(Edge a, Edge b)
{
    return a.w < b.w;
}

// Find parent of vertex (with path compression)
int findParent(int parent[], int v)
{
    if (parent[v] == v)
        return v;
    return parent[v] = findParent(parent, parent[v]);
}

// Union two sets
void unionSets(int parent[], int u, int v)
{
    int pu = findParent(parent, u);
    int pv = findParent(parent, v);
    parent[pu] = pv;
}

void kruskal(int V, vector<Edge> &edges)
{
    // Sort edges by weight
    sort(edges.begin(), edges.end(), compare);

    // Initialize parent array
    int parent[V];
    for (int i = 0; i < V; i++)
        parent[i] = i;

    vector<Edge> mst;
    int totalWeight = 0;

    // Process each edge
    for (Edge e : edges)
    {
        int pu = findParent(parent, e.u);
        int pv = findParent(parent, e.v);

        // If different sets, add to MST
        if (pu != pv)
        {
            mst.push_back(e);
            totalWeight += e.w;
            unionSets(parent, e.u, e.v);
        }
    }

    // Print MST
    cout << "Edge \tWeight" << endl;
    cout << "---- \t------" << endl;
    for (Edge e : mst)
    {
        cout << e.u << " - " << e.v << " \t" << e.w << endl;
    }
    cout << "\nTotal Weight: " << totalWeight << endl;
}

int main()
{
    int V = 6;

    vector<Edge> edges = {
        {0, 1, 4},
        {0, 2, 4},
        {1, 2, 2},
        {2, 3, 3},
        {2, 5, 2},
        {2, 4, 4},
        {3, 4, 3},
        {5, 4, 3}};

    kruskal(V, edges);

    return 0;
}