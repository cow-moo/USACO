#include <iostream>
#include <vector>
using namespace std;
#define MAXN 100005

vector<int> adj[MAXN];
vector<int> leaders;
bool visited[MAXN];

void dfs(int node)
{
    visited[node] = true;
    for (int v : adj[node])
    {
        if (!visited[v])
            dfs(v);
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
        if (!visited[i])
        {
            leaders.push_back(i);
            dfs(i);
        }
    }

    cout << leaders.size() - 1 << endl;
    for (int i = 1; i < leaders.size(); i++)
    {
        cout << leaders[i - 1] << " " << leaders[i] << endl;
    }
}