// Program to read a graph and print the adjacency List

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int v, e;
    cout << "Number of Vertices in  graph: ";
    cin >> v;
    cout << "Number of Edges in the graph: ";
    cin >> e;

    vector<int> adjList[v];
    for (int i = 1; i <= e; i++)
    {

        int x, y;
        cout << "Enter the end points of edge " << i << ":";
        cin >> x >> y;
        adjList[x].push_back(y);
        adjList[y].push_back(x);
    }

    cout << "Adjacency List: " << endl;
    for (int i = 0; i < v; i++)
    {
        cout << i << ": ";
        int j;
        for (j = 0; j < adjList[i].size() - 1; j++)
        {
            cout << adjList[i][j] << " , ";
        }
        cout << adjList[i][j] << endl;
    }
    return 0;
}
