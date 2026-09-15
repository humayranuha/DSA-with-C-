// Simple Prim's Algorithm in C++

#include <iostream>
#include <climits>
using namespace std;

#define INF INT_MAX
#define V 5

// Find the vertex with minimum key value
int findMinKey(int key[], bool inMST[]) {
    int minKey = INF;
    int minIndex = -1;
    
    for (int v = 0; v < V; v++) {
        if (!inMST[v] && key[v] < minKey) {
            minKey = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}

// Print the MST
void printMST(int parent[], int graph[V][V]) {
    cout << "Edge \tWeight" << endl;
    cout << "---- \t------" << endl;
    
    int totalWeight = 0;
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << endl;
        totalWeight += graph[i][parent[i]];
    }
    cout << "\nTotal Weight: " << totalWeight << endl;
}

// Prim's Algorithm
void primMST(int graph[V][V]) {
    int parent[V];   // Stores MST
    int key[V];      // Key values to pick minimum weight edge
    bool inMST[V];   // Track vertices included in MST
    
    // Initialize all keys as INFINITE and inMST as false
    for (int i = 0; i < V; i++) {
        key[i] = INF;
        inMST[i] = false;
    }
    
    // Start with first vertex
    key[0] = 0;
    parent[0] = -1;  // First node is always root of MST
    
    // Find MST for all vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum key vertex not yet in MST
        int u = findMinKey(key, inMST);
        
        // Add the picked vertex to MST
        inMST[u] = true;
        
        // Update key values and parent of adjacent vertices
        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !inMST[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
    
    // Print the MST
    printMST(parent, graph);
}

int main() {
    // Adjacency matrix representation of the graph
    int graph[V][V] = {
        {0, 9, 75, 0, 0},
        {9, 0, 95, 19, 42},
        {75, 95, 0, 51, 66},
        {0, 19, 51, 0, 31},
        {0, 42, 66, 31, 0}
    };
    
    primMST(graph);
    
    return 0;
}