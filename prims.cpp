#include <iostream>
#include <climits>

using namespace std;

int graph[100][100]; // Adjacency matrix
int parent[100];     // Stores the MST
int key[100];        // Stores the minimum edge weight
bool mst[100];       // Tracks included vertices

void calculatePrimsMST(int n)
{
    for (int i = 1; i <= n; i++) 
    {
        key[i] = INT_MAX;
        mst[i] = false;
        parent[i] = -1;
    }

    key[1] = 0; // Start from node 1

    for (int count = 1; count < n; count++) 
    {
        int mini = INT_MAX, u = -1;

        // Find the minimum key vertex not yet included in MST
        for (int v = 1; v <= n; v++) 
        {
            if (!mst[v] && key[v] < mini) 
            {
                mini = key[v];
                u = v;
            }
        }

        if (u == -1) break; // If no valid node found, break (should not happen for a connected graph)

        mst[u] = true;

        // Update adjacent vertices
        for (int v = 1; v <= n; v++) 
        {
            if (graph[u][v] && !mst[v] && graph[u][v] < key[v]) 
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the MST result
    cout << "Minimum Spanning Tree Edges:\n";
    for (int i = 2; i <= n; i++) 
    {
        if (parent[i] != -1) 
        {
            cout << parent[i] << " - " << i << " : " << key[i] << "\n";
        }
    }
}

// Driver code with user input
int main() 
{
    int n, m;
    cout << "Enter the number of nodes and edges: ";
    cin >> n >> m;

    // Initialize adjacency matrix with 0 (no edges)
    for (int i = 1; i <= n; i++) 
    {
        for (int j = 1; j <= n; j++) 
        {
            graph[i][j] = 0;
        }
    }

    cout << "Enter the edges in the format (u v w) where u and v are nodes and w is weight:\n";
    for (int i = 0; i < m; i++) 
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;
        graph[v][u] = w; // Since it's an undirected graph
    }

    calculatePrimsMST(n);

    return 0;
}
