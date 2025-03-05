#include <iostream>
#include <vector>
using namespace std;

class Graph {
public:
    int V, E;
    int matrix[100][100];      // Adjacency Matrix
    vector<int> adjList[100];  // Adjacency List

    // Constructor
    Graph(int x, int y)
     {
        V = x;
        E = y;

        // Initialize adjacency matrix to 0
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++)
             {
                matrix[i][j] = 0;
            }
        }
    }

    // Add edge (for both matrix & list)
    void addEdge(int x, int y)
     {
        if (x >= V || y >= V) {
            cout << "Invalid edge: (" << x << ", " << y << ")" << endl;
            return;
        }

        // Adjacency Matrix representation
        matrix[x][y] = 1;
        matrix[y][x] = 1;

        // Adjacency List representation
        adjList[x].push_back(y);
        adjList[y].push_back(x);
    }

    // Display Adjacency Matrix
    void displayMatrix()
     {
        cout << "\nAdjacency Matrix:\n";
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++)
             {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Display Adjacency List
    void displayList()
     {
        cout << "\nAdjacency List:\n";
        for (int i = 0; i < V; i++)
         {
            cout << i << " -> ";
            for (int neighbor : adjList[i]) 
            {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }
};

int main() 
{
    int v, e;
    cout << "Enter number of vertices: ";
    cin >> v;
    cout << "Enter number of edges: ";
    cin >> e;

    Graph g(v, e);

    // Taking edge input from the user
    cout << "Enter " << e << " edges (u v format):\n";
    for (int i = 0; i < e; i++) 
    {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    g.displayMatrix();
    g.displayList();

    return 0;
}
