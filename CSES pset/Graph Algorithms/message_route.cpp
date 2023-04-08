#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAXN 100005

vector<int> adj[MAXN];
int parent[MAXN];
int dist[MAXN];

void printPath(int cur)
{
    if (cur == 0)
    {
        return;
    }
    printPath(parent[cur]);
    cout << cur << " ";
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    queue<int> q;
    q.push(1);
    dist[1] = 1;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (int v : adj[cur])
        {
            if (dist[v] == 0)
            {
                parent[v] = cur;
                dist[v] = dist[cur] + 1;
                q.push(v);
                if (v == n)
                {
                    cout << dist[v] << endl;
                    printPath(v);
                    return 0;
                }
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
}