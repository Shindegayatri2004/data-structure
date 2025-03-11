#include <iostream>
using namespace std;

class Node
{
public:
    string name;
    int time;
    Node* next;
    Node(string n, int t) : name(n), time(t), next(nullptr) {}
};

class Graph 
{
public:
    int n, m;
    string names[100];
    int matrix[100][100];
    Node* list[100];

    Graph(int nodes, int edges) 
    {
        n = nodes;
        m = edges;
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < n; j++)
            {
                matrix[i][j] = 0;
            }
            list[i] = nullptr;
        }
    }

    int getIndex(string city)
    {
        for (int i = 0; i < n; i++)
        {
            if (names[i] == city)
            {
                return i;
            }
        }
        return -1;
    }

    void addEdge(string a, string b, int t) 
    {
        int u = getIndex(a);
        int v = getIndex(b);
        
        if (u == -1 || v == -1)
        {
            cout << "Invalid edge: (" << a << ", " << b << ")" << endl;
            return;
        }
        
        matrix[u][v] = t;
        matrix[v][u] = t;

        Node* nodeA = new Node(b, t);
        nodeA->next = list[u];
        list[u] = nodeA;

        Node* nodeB = new Node(a, t);
        nodeB->next = list[v];
        list[v] = nodeB;
    }

    void displayMatrix() 
    {
        cout << "\nAdjacency Matrix (Time Representation):" << endl;
        cout << "    ";
        for (int i = 0; i < n; i++)
        {
            cout << names[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < n; i++)
        {
            cout << names[i] << " ";
            for (int j = 0; j < n; j++) 
            {
                cout << matrix[i][j] << "   ";
            }
            cout << endl;
        }
    }

    void displayList() 
    {
        cout << "\nAdjacency List (Linked List with Time):" << endl;
        for (int i = 0; i < n; i++)
        {
            cout << names[i] << " -> ";
            Node* temp = list[i];
            while (temp)
            {
                cout << "(" << temp->name << ", " << temp->time << " min)" << "-> ";
                temp = temp->next;
            }
            cout << "NULL" << endl;
        }
    }
};

int main()
{
    int n, m;
    cout << "Enter number of cities: ";
    cin >> n;
    cout << "Enter number of roads(edges): ";
    cin >> m;

    Graph g(n, m);
    
    cout << "Enter city names: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> g.names[i];
    }

    cout << "Enter " << m << " roads (city1 city2 travel_time_in_minutes):" << endl;
    for (int i = 0; i < m; i++) {
        string a, b;
        int t;
        cin >> a >> b >> t;
        g.addEdge(a, b, t);
    }

    g.displayMatrix();
    g.displayList();

    return 0;
}
