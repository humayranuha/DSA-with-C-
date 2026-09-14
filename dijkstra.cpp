// Simple Dijkstra's Algorithm in C++

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

#define INF INT_MAX

// Find the vertex with minimum distance
int findMinVertex(vector<int>& distance, vector<bool>& visited, int V) {
    int minVertex = -1;
    
    for (int i = 0; i < V; i++) {
        if (!visited[i] && (minVertex == -1 || distance[i] < distance[minVertex])) {
            minVertex = i;
        }
    }
    
    return minVertex;
}

// Print the shortest path
void printPath(vector<int>& parent, int vertex) {
    if (parent[vertex] == -1) {
        cout << vertex;
        return;
    }
    printPath(parent, parent[vertex]);
    cout << " -> " << vertex;
}

// Dijkstra's Algorithm
void dijkstra(vector<vector<int>>& graph, int source, int V) {
    vector<int> distance(V, INF);   // Distance from source
    vector<bool> visited(V, false); // Visited vertices
    vector<int> parent(V, -1);      // For path reconstruction
    
    distance[source] = 0;
    
    for (int i = 0; i < V - 1; i++) {
        // Find the unvisited vertex with minimum distance
        int u = findMinVertex(distance, visited, V);
        
        if (u == -1) break;
        
        visited[u] = true;
        
        // Update distances of adjacent vertices
        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] != 0 && 
                distance[u] != INF && 
                distance[u] + graph[u][v] < distance[v]) {
                
                distance[v] = distance[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }
    
    // Print results
    cout << "Shortest distances from vertex " << source << ":" << endl;
    cout << "----------------------------------------" << endl;
    
    for (int i = 0; i < V; i++) {
        cout << "To vertex " << i << ": ";
        
        if (distance[i] == INF) {
            cout << "No path" << endl;
        } else {
            cout << "Distance = " << distance[i] << ", Path: ";
            printPath(parent, i);
            cout << endl;
        }
    }
}

int main() {
    int V = 6;  // Number of vertices
    
    // Adjacency matrix (0 means no edge)
    vector<vector<int>> graph = {
        {0, 4, 0, 0, 0, 0},   // 0
        {4, 0, 8, 0, 0, 0},   // 1
        {0, 8, 0, 7, 0, 4},   // 2
        {0, 0, 7, 0, 9, 14},  // 3
        {0, 0, 0, 9, 0, 10},  // 4
        {0, 0, 4, 14, 10, 0}  // 5
    };
    
    int source = 0;
    
    dijkstra(graph, source, V);
    
    return 0;
}