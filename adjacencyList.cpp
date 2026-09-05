// Adjacency List Graph in C++

#include <iostream>
#include <vector>
using namespace std;

// Graph class using adjacency list
class Graph {
private:
    int vertices;
    vector<vector<int>> adjList;

public:
    // Constructor
    Graph(int V) {
        vertices = V;
        adjList.resize(V);
    }

    // Add edge (undirected)
    void addEdge(int source, int dest) {
        if (source < vertices && dest < vertices) {
            adjList[source].push_back(dest);
            adjList[dest].push_back(source);  // For undirected graph
        }
    }

    // Add directed edge
    void addDirectedEdge(int source, int dest) {
        if (source < vertices && dest < vertices) {
            adjList[source].push_back(dest);
        }
    }

    // Remove edge
    void removeEdge(int source, int dest) {
        if (source < vertices && dest < vertices) {
            // Remove from source list
            for (int i = 0; i < adjList[source].size(); i++) {
                if (adjList[source][i] == dest) {
                    adjList[source].erase(adjList[source].begin() + i);
                    break;
                }
            }
            // Remove from dest list (undirected)
            for (int i = 0; i < adjList[dest].size(); i++) {
                if (adjList[dest][i] == source) {
                    adjList[dest].erase(adjList[dest].begin() + i);
                    break;
                }
            }
        }
    }

    // Check if edge exists
    bool hasEdge(int source, int dest) {
        if (source >= vertices || dest >= vertices) return false;
        
        for (int neighbor : adjList[source]) {
            if (neighbor == dest) return true;
        }
        return false;
    }

    // Get degree of a vertex
    int getDegree(int vertex) {
        if (vertex >= vertices) return -1;
        return adjList[vertex].size();
    }

    // Get neighbors of a vertex
    vector<int> getNeighbors(int vertex) {
        if (vertex >= vertices) return {};
        return adjList[vertex];
    }

    // Print the graph
    void print() {
        for (int i = 0; i < vertices; i++) {
            cout << "Vertex " << i << ":";
            if (adjList[i].empty()) {
                cout << " (no neighbors)";
            } else {
                for (int neighbor : adjList[i]) {
                    cout << " -> " << neighbor;
                }
            }
            cout << endl;
        }
    }

    // Get number of vertices
    int getVertices() {
        return vertices;
    }
};

int main() {
    // Create graph with 5 vertices (0-4)
    Graph g(5);

    // Add edges
    cout << "Adding edges: 0-1, 0-2, 0-3, 1-2" << endl << endl;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(1, 2);

    // Print graph
    g.print();

    // Check edges
    cout << "\nChecking edges:" << endl;
    cout << "Edge 0-2: " << (g.hasEdge(0, 2) ? "Yes" : "No") << endl;
    cout << "Edge 2-3: " << (g.hasEdge(2, 3) ? "Yes" : "No") << endl;

    // Get degrees
    cout << "\nDegrees:" << endl;
    for (int i = 0; i < g.getVertices(); i++) {
        cout << "Vertex " << i << ": " << g.getDegree(i) << endl;
    }

    // Get neighbors of vertex 0
    cout << "\nNeighbors of vertex 0: ";
    vector<int> neighbors = g.getNeighbors(0);
    for (int n : neighbors) {
        cout << n << " ";
    }
    cout << endl;

    // Remove an edge
    cout << "\nRemoving edge 0-2" << endl;
    g.removeEdge(0, 2);
    g.print();

    return 0;
}