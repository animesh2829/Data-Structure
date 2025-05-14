#include<iostream>
#include<string>
using namespace std;

class Graph {
public:
    int v;
    string names[10];
    int a[10][10] = {0}; 

    Graph(int v1) {
        v = v1;
    }

    int getIndex(string name) {
        for (int i = 0; i < v; i++) {
            if (names[i] == name)
                return i;
        }
        return -1;
    }

    void inputNames() {
        cout << "\nEnter names for each location:\n";
        for (int i = 0; i < v; i++) {
            cout << "Location " << i << ": ";
            cin >> names[i];
        }
    }

    void addEdge() {
        int edges;
        cout << "\nEnter number of roads (edges): ";
        cin >> edges;

        string src, dest;
        int dist;

        for (int i = 0; i < edges; i++) {
            cout << "\nEnter source, destination, distance: ";
            cin >> src >> dest >> dist;
            int p = getIndex(src);
            int q = getIndex(dest);
            if (p != -1 && q != -1) {
                a[p][q] = dist;
                a[q][p] = dist;  // undirected
            } else {
                cout << "Invalid location name entered!\n";
                i--;  // retry this edge
            }
        }
    }

    void printGraph() {
        cout << "\nDistance Matrix:\n\t";
        

        for (int i = 0; i < v; i++) {
           
            for (int j = 0; j < v; j++) {
                cout << a[i][j] << "\t";
            }
            cout << endl;
        }
    }

    void shortpath(string sourceName) {
        int src = getIndex(sourceName);
        if (src == -1) {
            cout << "\nInvalid source location!";
            return;
        }

        int d[10], visited[10] = {0};

        for (int i = 0; i < v; i++)
            d[i] = 9999;
        d[src] = 0;

        for (int cnt = 0; cnt < v - 1; cnt++) {
            int u = -1, min = 9999;
            for (int i = 0; i < v; i++) {
                if (!visited[i] && d[i] < min) {
                    min = d[i];
                    u = i;
                }
            }

            if (u == -1) break;

            visited[u] = 1;

            for (int i = 0; i < v; i++) {
                int temp = d[u] + a[u][i];
                if (!visited[i] && a[u][i] && temp < d[i]) {
                    d[i] = temp;
                }
            }
        }

        cout << "\nShortest distances from " << sourceName << ":\n";
        for (int i = 0; i < v; i++) {
            cout << "To " << names[i] << ": " << d[i] << " km\n";
        }
    }
};

int main() {
    int vx;
    cout << "\nEnter number of locations: ";
    cin >> vx;

    Graph g(vx);
    g.inputNames();
    g.addEdge();
    g.printGraph();

    string start;
    cout << "\nEnter your current location name: ";
    cin >> start;

    g.shortpath(start);

    return 0;
}