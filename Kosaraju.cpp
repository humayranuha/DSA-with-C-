// Kosaraju's Algorithm for Strongly Connected Components

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Graph {
private:
    int V;
    vector<vector<int>> adj;

    // First DFS: Fill order (post-order)
    void fillOrder(int v, vector<bool>& visited, stack<int>& st) {
        visited[v] = true;

        for (int neighbor : adj[v]) {
            if (!visited[neighbor]) {
                fillOrder(neighbor, visited, st);
            }
        }
        st.push(v);
    }

    // Second DFS: Traverse on transposed graph
    void DFS(int v, vector<bool>& visited, vector<int>& component) {
        visited[v] = true;
        component.push_back(v);

        for (int neighbor : adj[v]) {
            if (!visited[neighbor]) {
                DFS(neighbor, visited, component);
            }
        }
    }

    // Get transposed graph (reverse all edges)
    Graph getTranspose() {
        Graph g(V);
        for (int i = 0; i < V; i++) {
            for (int neighbor : adj[i]) {
                g.addEdge(neighbor, i);  // Reverse edge
            }
        }
        return g;
    }

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int src, int dest) {
        adj[src].push_back(dest);
    }

    // Find all strongly connected components
    vector<vector<int>> findSCC() {
        stack<int> st;
        vector<bool> visited(V, false);

        // Step 1: Fill order based on finish times
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                fillOrder(i, visited, st);
            }
        }

        // Step 2: Get transposed graph
        Graph transposed = getTranspose();

        // Step 3: Process vertices in order of decreasing finish time
        vector<bool> visited2(V, false);
        vector<vector<int>> components;

        while (!st.empty()) {
            int v = st.top();
            st.pop();

            if (!visited2[v]) {
                vector<int> component;
                transposed.DFS(v, visited2, component);
                components.push_back(component);
            }
        }

        return components;
    }

    void printSCC() {
        vector<vector<int>> components = findSCC();

        cout << "Strongly Connected Components:\n";
        for (int i = 0; i < components.size(); i++) {
            cout << "Component " << i + 1 << ": ";
            for (int v : components[i]) {
                cout << v << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph g(8);
    
    // Add edges
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 0);
    g.addEdge(4, 5);
    g.addEdge(5, 6);
    g.addEdge(6, 4);
    g.addEdge(6, 7);

    g.printSCC();

    return 0;
}