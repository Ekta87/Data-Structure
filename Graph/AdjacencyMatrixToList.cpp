// Program to read the adjacency matrix and convert that to Adjacency List

#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main()
{
    int v, e;
    cout << "Number of Vertices in  graph: ";
    cin >> v;
    cout << "Number of Edges in the graph: ";
    cin >> e;

    vector<vector<int>> adjMatrix(v, vector<int>(v, 0));
    for (int i = 1; i <= e; i++)
    {

        int x, y;
        cout << "Enter the end points of edge " << i << ":";
        cin >> x >> y;
        adjMatrix[x][y] = 1;
        adjMatrix[y][x] = 1;
    }

    cout << "Adjacency Matrix: " << endl;
    for (int i = 0; i < v; i++)
    {

        int j;
        for (j = 0; j < v; j++)
        {
            cout << adjMatrix[i][j] << "  ";
        }
        cout << endl;
    }
    vector<int> adjList[v];
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            if (adjMatrix[i][j] == 1)
            {
                adjList[i].push_back(j);
            }
        }
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