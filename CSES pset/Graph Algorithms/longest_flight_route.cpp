#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAXN 100005

vector<int> adj[MAXN];
int dist[MAXN], n, nxt[MAXN];

void dfs(int cur)
{
    if (cur == n)
        return;
    for (int next : adj[cur])
    {
        if (dist[next] == -1)
            dfs(next);
        if (dist[next] > 0 && dist[next] > dist[cur])
        {
            dist[cur] = dist[next];
            nxt[cur] = next;
        }
    }
    if (dist[cur] > 0)
        dist[cur]++;
    else
        dist[cur] = 0;
}

int main()
{
    int m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    fill(dist + 1, dist + n, -1);
    dist[n] = 1;

    for (int i = 1; i <= n; i++)
    {
        if (dist[i] == -1)
            dfs(i);
    }
    
    if (dist[1] == 0)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        cout << dist[1] << endl;
        int cur = 1;
        while (cur != n)
        {
            cout << cur << " ";
            cur = nxt[cur];
        }
        cout << n << endl;
    }
}