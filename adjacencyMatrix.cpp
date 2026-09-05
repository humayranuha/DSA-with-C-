// Adjacency Matrix Graph in C++

#include <iostream>
using namespace std;

class Graph {
private:
    bool** adjMatrix;  // 2D array to store edges
    int vertices;      // Number of vertices

public:
    // Constructor - creates empty graph
    Graph(int vertices) {
        this->vertices = vertices;
        
        // Allocate memory for matrix
        adjMatrix = new bool*[vertices];
        for (int i = 0; i < vertices; i++) {
            adjMatrix[i] = new bool[vertices];
            // Initialize all to false (no edges)
            for (int j = 0; j < vertices; j++)
                adjMatrix[i][j] = false;
        }
    }

    // Add edge between i and j (undirected)
    void addEdge(int i, int j) {
        if (i >= 0 && i < vertices && j >= 0 && j < vertices) {
            adjMatrix[i][j] = true;
            adjMatrix[j][i] = true;  // Symmetric for undirected
        }
    }

    // Remove edge between i and j
    void removeEdge(int i, int j) {
        if (i >= 0 && i < vertices && j >= 0 && j < vertices) {
            adjMatrix[i][j] = false;
            adjMatrix[j][i] = false;
        }
    }

    // Check if edge exists
    bool hasEdge(int i, int j) {
        if (i >= 0 && i < vertices && j >= 0 && j < vertices)
            return adjMatrix[i][j];
        return false;
    }

    // Print the adjacency matrix
    void print() {
        cout << "Adjacency Matrix:" << endl;
        cout << "   ";
        for (int i = 0; i < vertices; i++)
            cout << i << " ";
        cout << endl;
        
        for (int i = 0; i < vertices; i++) {
            cout << i << "  ";
            for (int j = 0; j < vertices; j++)
                cout << adjMatrix[i][j] << " ";
            cout << endl;
        }
    }

    // Get degree of a vertex
    int getDegree(int vertex) {
        if (vertex < 0 || vertex >= vertices) return -1;
        
        int degree = 0;
        for (int i = 0; i < vertices; i++) {
            if (adjMatrix[vertex][i])
                degree++;
        }
        return degree;
    }

    // Get number of vertices
    int getVertices() {
        return vertices;
    }

    // Destructor - free memory
    ~Graph() {
        for (int i = 0; i < vertices; i++)
            delete[] adjMatrix[i];
        delete[] adjMatrix;
    }
};

int main() {
    // Create graph with 4 vertices (0, 1, 2, 3)
    Graph g(4);

    // Add edges
    cout << "Adding edges:" << endl;
    cout << "0-1, 0-2, 1-2, 2-0, 2-3" << endl << endl;
    
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);

    // Print the graph
    g.print();

    // Check some edges
    cout << "\nChecking edges:" << endl;
    cout << "Edge 0-2: " << (g.hasEdge(0, 2) ? "Yes" : "No") << endl;
    cout << "Edge 0-3: " << (g.hasEdge(0, 3) ? "Yes" : "No") << endl;

    // Get degrees
    cout << "\nDegrees:" << endl;
    for (int i = 0; i < g.getVertices(); i++) {
        cout << "Vertex " << i << ": " << g.getDegree(i) << endl;
    }

    // Remove an edge
    cout << "\nRemoving edge 2-0" << endl;
    g.removeEdge(2, 0);
    g.print();

    return 0;
}