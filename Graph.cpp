#include <iostream>
#include <queue>
#include <list>
#include <vector>
using namespace std;

class Graph
{
    int V;
    list<int> *l;

public:
    int component = 0;

    Graph(int v)
    {
        V = v;
        l = new list<int>[v];
    }

    void addEdge(int u, int v)
    {
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void bfs(int start)
    {
        vector<bool> vis(V, false);
        vector<int> distance(V, -1);
        queue<int> q;

        vis[start] = true;
        distance[start] = 0;
        q.push(start);

        while (!q.empty())
        {
            int val = q.front();
            q.pop();
            cout << val << " (Distance: " << distance[val] << ")" << endl;

            for (int neigh : l[val])
            {
                if (!vis[neigh])
                {
                    distance[neigh] = distance[val] + 1;
                    vis[neigh] = true;
                    q.push(neigh);
                }
            }
        }
    }

    void dfs(int start, vector<bool> &vis)
    {
        vis[start] = true;
        cout << start << " ";

        for (int neigh : l[start])
        {
            if (!vis[neigh])
            {
                dfs(neigh, vis);
            }
        }
    }

    int count_component()
    {
        vector<bool> vis(V, false);
        component = 0;

        for (int i = 1; i < V; i++)
        {
            if (!vis[i])
            {
                component++;
                dfs(i, vis);
                cout << endl;
            }
        }

        return component;
    }
};

int main()
{
    int vertices, edges;

    cout << "Enter number of vertices: ";
    cin >> vertices;

    cout << "Enter number of edges: ";
    cin >> edges;

    Graph g(vertices + 1);

    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cout << "Enter edge " << i + 1 << " From: ";
        cin >> u;
        cout << "To: ";
        cin >> v;
        g.addEdge(u, v);
    }

    int start;
    cout << "Enter starting node for BFS: ";
    cin >> start;

    cout << "BFS starting from " << start << ":" << endl;
    g.bfs(start);

    vector<bool> vis(vertices + 1, false);
    cout << "DFS starting from " << start << ": ";
    g.dfs(start, vis);
    cout << endl;

    cout << "No of connected components are : " << g.count_component() << endl;
}
