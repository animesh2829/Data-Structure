#include <iostream>
using namespace std;

#define MAX 100
#define INF 99999

class Graph {
public:
    int V;
    int adj[MAX][MAX];

    // Constructor
    Graph(int vertices) {
        V = vertices;

        // Initialize all edges to INF (no edge), and 0 for same node
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (i == j)
                    adj[i][j] = 0;
                else
                    adj[i][j] = INF;
            }
        }
    }

    void addEdge(int u, int v, int w) {
        adj[u][v] = w;
        adj[v][u] = w;  // For undirected graph
    }

    void dijkstra(int src) {
        int dist[MAX];
        bool visited[MAX];

        // Initialize all distances to INF and visited to false
        for (int i = 0; i < V; i++) {
            dist[i] = INF;
            visited[i] = false;
        }

        dist[src] = 0; // Distance to itself is 0

        for (int i = 0; i < V - 1; i++) {
            // Find the unvisited node with the smallest distance
            int minDist = INF;
            int u;

            for (int j = 0; j < V; j++) {
                if (!visited[j] && dist[j] < minDist) {
                    minDist = dist[j];
                    u = j;
                }
            }

            visited[u] = true;

            // Update distances of adjacent vertices
            for (int v = 0; v < V; v++) {
                if (!visited[v] && adj[u][v] != INF && dist[u] + adj[u][v] < dist[v]) {
                    dist[v] = dist[u] + adj[u][v];
                }
            }
        }

        // Print shortest distances
        cout << "\nShortest distances from node " << src << ":\n";
        for (int i = 0; i < V; i++) {
            cout << "To node " << i << ": " << dist[i] << endl;
        }
    }
};

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    Graph g(V);

    cout << "Enter edges (u v w):\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }

    int src;
    cout << "Enter source node: ";
    cin >> src;

    g.dijkstra(src);

    return 0;
}