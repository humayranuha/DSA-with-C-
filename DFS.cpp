// DFS Algorithm for Undirected Graph

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Graph {
private:
    int vertices;
    vector<vector<int>> adjList;

public:
    Graph(int V) {
        vertices = V;
        adjList.resize(V);
    }

    void addEdge(int src, int dest) {
        adjList[src].push_back(dest);
        adjList[dest].push_back(src);
    }

    void DFSRecursive(int vertex, vector<bool>& visited) {
        visited[vertex] = true;
        cout << vertex << " ";

        for (int neighbor : adjList[vertex]) {
            if (!visited[neighbor]) {
                DFSRecursive(neighbor, visited);
            }
        }
    }

    void DFS(int start) {
        vector<bool> visited(vertices, false);
        cout << "DFS Traversal from " << start << ": ";
        DFSRecursive(start, visited);
        cout << endl;
    }

    void DFSIterative(int start) {
        vector<bool> visited(vertices, false);
        stack<int> st;
        st.push(start);

        cout << "Iterative DFS from " << start << ": ";
        while (!st.empty()) {
            int vertex = st.top();
            st.pop();

            if (!visited[vertex]) {
                visited[vertex] = true;
                cout << vertex << " ";

                for (int i = adjList[vertex].size() - 1; i >= 0; i--) {
                    int neighbor = adjList[vertex][i];
                    if (!visited[neighbor]) {
                        st.push(neighbor);
                    }
                }
            }
        }
        cout << endl;
    }

    bool hasPath(int start, int target) {
        vector<bool> visited(vertices, false);
        return hasPathHelper(start, target, visited);
    }

    bool hasPathHelper(int current, int target, vector<bool>& visited) {
        if (current == target) return true;
        
        visited[current] = true;
        
        for (int neighbor : adjList[current]) {
            if (!visited[neighbor]) {
                if (hasPathHelper(neighbor, target, visited)) {
                    return true;
                }
            }
        }
        return false;
    }

    vector<int> getReachable(int start) {
        vector<bool> visited(vertices, false);
        vector<int> reachable;
        getReachableHelper(start, visited, reachable);
        return reachable;
    }

    void getReachableHelper(int vertex, vector<bool>& visited, vector<int>& reachable) {
        visited[vertex] = true;
        reachable.push_back(vertex);

        for (int neighbor : adjList[vertex]) {
            if (!visited[neighbor]) {
                getReachableHelper(neighbor, visited, reachable);
            }
        }
    }

    vector<vector<int>> getConnectedComponents() {
        vector<bool> visited(vertices, false);
        vector<vector<int>> components;

        for (int i = 0; i < vertices; i++) {
            if (!visited[i]) {
                vector<int> component;
                getComponentHelper(i, visited, component);
                components.push_back(component);
            }
        }
        return components;
    }

    void getComponentHelper(int vertex, vector<bool>& visited, vector<int>& component) {
        visited[vertex] = true;
        component.push_back(vertex);

        for (int neighbor : adjList[vertex]) {
            if (!visited[neighbor]) {
                getComponentHelper(neighbor, visited, component);
            }
        }
    }

    void printGraph() {
        cout << "Undirected Graph:" << endl;
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
};

int main() {
    // Example 1: Connected Graph
    cout << "========== CONNECTED GRAPH ==========" << endl;
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);

    g.printGraph();

    cout << "\n";
    g.DFS(2);
    g.DFS(0);
    
    cout << "\n";
    g.DFSIterative(0);

    cout << "\nPath exists between 0 and 3: " 
        << (g.hasPath(0, 3) ? "Yes" : "No") << endl;
    cout << "Path exists between 3 and 0: " 
        << (g.hasPath(3, 0) ? "Yes" : "No") << endl;

    cout << "\nVertices reachable from 0: ";
    for (int v : g.getReachable(0)) {
        cout << v << " ";
    }
    cout << endl;

    cout << "Vertices reachable from 3: ";
    for (int v : g.getReachable(3)) {
        cout << v << " ";
    }
    cout << endl;

    // Example 2: Disconnected Graph
    cout << "\n\n========== DISCONNECTED GRAPH ==========" << endl;
    Graph g2(6);
    g2.addEdge(0, 1);
    g2.addEdge(0, 2);
    g2.addEdge(3, 4);
    g2.addEdge(4, 5);

    g2.printGraph();

    cout << "\nConnected Components:" << endl;
    vector<vector<int>> components = g2.getConnectedComponents();
    for (int i = 0; i < components.size(); i++) {
        cout << "Component " << i + 1 << ": ";
        for (int v : components[i]) {
            cout << v << " ";
        }
        cout << endl;
    }

    cout << "\n";
    g2.DFS(0);
    g2.DFS(3);

    return 0;
}