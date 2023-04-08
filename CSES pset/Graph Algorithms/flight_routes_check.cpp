#include <iostream>
#include <vector>
using namespace std;
#define MAXN 100005

vector<int> adj[MAXN][2];
bool visited[MAXN];

void dfs(int cur, int i)
{
    visited[cur] = true;
    for (auto v : adj[cur][i])
    {
        if (!visited[v])
            dfs(v, i);
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
        a--; b--;
        adj[a][0].push_back(b);
        adj[b][1].push_back(a);
    }

    dfs(0, 0);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            cout << "NO\n1 " << i + 1 << endl;
            return 0;
        }
        visited[i] = false;
    }
    dfs(0, 1);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            cout << "NO\n" << i + 1 << " 1" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}