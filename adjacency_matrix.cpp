#include <iostream>

using namespace std;

class Node {
public:
    int vertex;
    Node* next;
    
    Node(int v, Node* n = nullptr) {
        vertex = v;
        next = n;
    }
};

class Graph {
public:
    int vertices;
    Node** adjList;
    
    Graph(int v) {
        vertices = v;
        adjList = new Node*[vertices];
        for (int i = 0; i < vertices; i++) {
            adjList[i] = nullptr;
        }
    }
    
    void addEdge(int u, int v) {
        adjList[u] = new Node(v, adjList[u]);
        adjList[v] = new Node(u, adjList[v]); // Remove for a directed graph
    }
    
    void printGraph() {
        for (int i = 0; i < vertices; i++) {
            cout << "Adjacency list of vertex " << i << ": ";
            Node* temp = adjList[i];
            while (temp) {
                cout << temp->vertex << " -> ";
                temp = temp->next;
            }
            cout << "NULL" << endl;
        }
    }
    
    ~Graph() {
        for (int i = 0; i < vertices; i++) {
            Node* temp = adjList[i];
            while (temp) {
                Node* next = temp->next;
                delete temp;
                temp = next;
            }
        }
        delete[] adjList;
    }
};

int main() {
    int vertices, edges;
    cout << "Enter number of vertices: ";
    cin >> vertices;
    cout << "Enter number of edges: ";
    cin >> edges;
    
    Graph g(vertices);
    
    cout << "Enter initial vertex and terminal vertex of all edges:\n";
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }
    
    g.printGraph();
    
    return 0;
}