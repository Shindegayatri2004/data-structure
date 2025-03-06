#include <iostream>
using namespace std;

class Node {
public:
    int vertex;
    Node* next;
    Node(int v) : vertex(v), next(nullptr) {}
};

class Graph {
public:
    int V, E;
    int matrix[100][100];   // Adjacency Matrix
    Node* adjList[100];     // Adjacency List using linked list

    // Constructor
    Graph(int v, int e) {
        V = v;
        E = e;

        // Initialize adjacency matrix to 0
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                matrix[i][j] = 0;
            }
            adjList[i] = nullptr; // Initialize linked list
        }
    }

    // Add edge for both matrix & linked list
    void addEdge(int x, int y) {
        if (x >= V || y >= V) {
            cout << "Invalid edge: (" << x << ", " << y << ")" << endl;
            return;
        }

        // Adjacency Matrix
        matrix[x][y] = 1;
        matrix[y][x] = 1;

        // Adjacency List (Linked List Representation)
        Node* newNodeX = new Node(y);
        newNodeX->next = adjList[x];
        adjList[x] = newNodeX;

        Node* newNodeY = new Node(x);
        newNodeY->next = adjList[y];
        adjList[y] = newNodeY;
    }

    // Display Adjacency Matrix
    void displayMatrix() {
        cout << "\nAdjacency Matrix:\n";
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Display Adjacency List
    void displayList() {
        cout << "\nAdjacency List (Linked List):\n";
        for (int i = 0; i < V; i++) {
            cout << i << " -> ";
            Node* temp = adjList[i];
            while (temp) {
                cout << temp->vertex << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main() {
    int v, e;
    cout << "Enter number of vertices: ";
    cin >> v;
    cout << "Enter number of edges: ";
    cin >> e;

    Graph g(v, e);

    // Taking edge input from the user
    cout << "Enter " << e << " edges (u v format):\n";
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    g.displayMatrix();
    g.displayList();

    return 0;
}
