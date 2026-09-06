// BFS (Breadth-First Search) Algorithm in C++

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph
{
private:
    int vertices;
    vector<vector<int>> adjList;

public:
    // Constructor
    Graph(int V)
    {
        vertices = V;
        adjList.resize(V);
    }

    // Add edge (undirected)
    void addEdge(int src, int dest)
    {
        adjList[src].push_back(dest);
        adjList[dest].push_back(src);
    }

    // Add edge (directed)
    void addDirectedEdge(int src, int dest)
    {
        adjList[src].push_back(dest);
    }

    // BFS traversal from a starting vertex
    void BFS(int start)
    {
        vector<bool> visited(vertices, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "BFS Traversal from " << start << ": ";

        while (!q.empty())
        {
            int vertex = q.front();
            q.pop();
            cout << vertex << " ";

            // Visit all neighbors
            for (int neighbor : adjList[vertex])
            {
                if (!visited[neighbor])
                {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }

    // BFS to find shortest path from start to target
    void shortestPath(int start, int target)
    {
        vector<bool> visited(vertices, false);
        vector<int> parent(vertices, -1);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        while (!q.empty())
        {
            int vertex = q.front();
            q.pop();

            if (vertex == target)
                break;

            for (int neighbor : adjList[vertex])
            {
                if (!visited[neighbor])
                {
                    visited[neighbor] = true;
                    parent[neighbor] = vertex;
                    q.push(neighbor);
                }
            }
        }

        // Print path
        if (!visited[target])
        {
            cout << "No path exists between " << start << " and " << target << endl;
            return;
        }

        // Reconstruct path
        vector<int> path;
        for (int v = target; v != -1; v = parent[v])
        {
            path.push_back(v);
        }

        cout << "Shortest path from " << start << " to " << target << ": ";
        for (int i = path.size() - 1; i >= 0; i--)
        {
            cout << path[i];
            if (i > 0)
                cout << " -> ";
        }
        cout << endl;
    }

    // BFS to find distance from start to all vertices
    vector<int> distances(int start)
    {
        vector<int> dist(vertices, -1);
        queue<int> q;

        dist[start] = 0;
        q.push(start);

        while (!q.empty())
        {
            int vertex = q.front();
            q.pop();

            for (int neighbor : adjList[vertex])
            {
                if (dist[neighbor] == -1)
                {
                    dist[neighbor] = dist[vertex] + 1;
                    q.push(neighbor);
                }
            }
        }

        return dist;
    }

    // Check if graph is connected using BFS
    bool isConnected()
    {
        if (vertices == 0)
            return true;

        vector<bool> visited(vertices, false);
        queue<int> q;

        visited[0] = true;
        q.push(0);

        int count = 0;
        while (!q.empty())
        {
            int vertex = q.front();
            q.pop();
            count++;

            for (int neighbor : adjList[vertex])
            {
                if (!visited[neighbor])
                {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        return (count == vertices);
    }

    // Print the graph
    void printGraph()
    {
        for (int i = 0; i < vertices; i++)
        {
            cout << "Vertex " << i << ":";
            if (adjList[i].empty())
            {
                cout << " (no neighbors)";
            }
            else
            {
                for (int neighbor : adjList[i])
                {
                    cout << " -> " << neighbor;
                }
            }
            cout << endl;
        }
    }
};

int main()
{
    // Create graph with 4 vertices
    Graph g(4);

    // Add edges
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);

    cout << "Graph Structure:" << endl;
    g.printGraph();

    cout << "\n";
    g.BFS(2);

    cout << "\n";
    g.BFS(0);

    // Shortest path
    cout << "\n";
    g.shortestPath(0, 3);
    g.shortestPath(3, 0);

    // Distances from vertex 0
    cout << "\nDistances from vertex 0:" << endl;
    vector<int> dist = g.distances(0);
    for (int i = 0; i < dist.size(); i++)
    {
        cout << "  Distance to " << i << ": " << dist[i] << endl;
    }

    // Check if connected
    cout << "\nGraph is connected: " << (g.isConnected() ? "Yes" : "No") << endl;

    // Example with disconnected graph
    cout << "\nDisconnected Graph Example:" << endl;
    Graph g2(5);
    g2.addEdge(0, 1);
    g2.addEdge(2, 3);
    g2.addEdge(3, 4);

    cout << "Graph Structure:" << endl;
    g2.printGraph();
    cout << "Graph is connected: " << (g2.isConnected() ? "Yes" : "No") << endl;
    g2.BFS(2);

    return 0;
}