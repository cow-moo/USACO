#include <iostream>
#include <vector>
using namespace std;
#define MAXN 100005

vector<int> adj[MAXN];
int coloring[MAXN];
bool possible = true;

void dfs(int cur)
{
    if (!possible)
        return;

    for (int v : adj[cur])
    {
        if (coloring[v] == coloring[cur])
        {
            possible = false;
        }
        else if (coloring[v] == 0)
        {
            coloring[v] = 3 - coloring[cur];
            dfs(v);
        }

        if (!possible)
            return;
    }
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

    for (int i = 1; i <= n; i++)
    {
        if (coloring[i] == 0)
        {
            coloring[i] = 1;
            dfs(i);
        }
    }

    if (possible)
    {
        for (int i = 1; i <= n; i++)
        {
            cout << coloring[i] << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "IMPOSSIBLE" << endl;
    }
}
