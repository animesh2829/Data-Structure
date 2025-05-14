#include <iostream>
#include <vector>
#include <climits>  // For INT_MAX
#define N 100
using namespace std;

void addEdge(int graph[N][N], int u, int v, int w) {
    graph[u][v] = w;
    graph[v][u] = w;
}

void display(int graph[N][N], int V) {
    cout << "  ";
    for (int i = 0; i < V; i++) {
        cout << i << " ";
    }
    cout << endl;
    for (int i = 0; i < V; i++) {
        cout << i << " ";
        for (int j = 0; j < V; j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

void prims(int graph[N][N], int V) {
    vector<int> inMST(V, 0);
    inMST[0] = 1; 
    int count = 0;  
    int minw = 0;   
    
    while (count < V - 1) {
        int min = INT_MAX, u = -1, v = -1;
        
        for (int i = 0; i < V; i++) {
            if (inMST[i]) {
                for (int j = 0; j < V; j++) {
                    if (graph[i][j] != 0 && !inMST[j] && graph[i][j] < min) {
                        min = graph[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }
        
        if (u != -1 && v != -1) {
            cout << "Edge " << u << "-" << v << " weight: " << min << endl;
            inMST[v] = 1;
            minw += min;
            count++;
        }
    }
    cout << "Minimum Weight: " << minw << endl;
}

int main() {
    int V, E, u, v, w;
    int graph[N][N] = {0};
    
    cout << "Enter the number of Vertices: ";
    cin >> V;
    
    cout << "Enter the number of Edges: ";
    cin >> E;
    
    for (int i = 0; i < E; i++) {
        cout << "Enter the source, destination, weight (u, v, w): ";
        cin >> u >> v >> w;
        addEdge(graph, u, v, w);
    }
    
    display(graph, V);
    cout << endl;
    
    cout << "MST" << endl;
    prims(graph, V);
    
    return 0;
}
