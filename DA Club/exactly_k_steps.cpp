#include <iostream>
#include <vector>
using namespace std;
#define MAXN 200005
 
vector<int> adj[MAXN];
int parent[MAXN][20];
int depth[MAXN];
int dist[MAXN][2];
int diameter[2] = {1, 1};
 
int getParent(int x, int k)
{
    if (k < 0)
        return -1;
    for (int j = 0; k > 0; j++)
    {
        if (k & (1 << j))
        {
            x = parent[x][j];
            k ^= 1 << j;
        }
    }
 
    return x;
}
 
void dfs(int cur)
{
    for (int v : adj[cur])
    {
        if (v == parent[cur][0])
            continue;
        parent[v][0] = cur;
        depth[v] = depth[cur] + 1;
        dfs(v);
    }
}

void dfsDist(int cur, int prev, int num)
{
    for (int next : adj[cur])
    {
        if (next == prev)
            continue;
        dist[next][num] = dist[cur][num] + 1;
        dfsDist(next, cur, num);
    }
}

int getLCA(int a, int b)
{
    if (depth[a] > depth[b])
        swap(a, b);

    int res = depth[b] - depth[a];
    b = getParent(b, res);

    if (a == b)
    {
        return a;
    }

    for (int j = 18; j >= 0; j--)
    {
        if (parent[a][j] != parent[b][j])
        {
            a = parent[a][j];
            b = parent[b][j];
        }
    }

    return parent[a][0];
}
 
int main()
{
    int n;
    cin >> n;
 
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
 
    dfs(1);
 
    for (int i = 1; i <= n; i++)
    {
        if (depth[i] > depth[diameter[0]])
            diameter[0] = i;
    }

    dfsDist(diameter[0], 0, 0);

    for (int i = 1; i <= n; i++)
    {
        if (dist[i][0] > dist[diameter[1]][0])
            diameter[1] = i;
    }

    dfsDist(diameter[1], 0, 1);

    for (int i = 1; i <= 18; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            parent[j][i] = parent[parent[j][i - 1]][i - 1];
        }
    }
 
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int u, k;
        cin >> u >> k;

        if (depth[u] >= k)
        {
            cout << getParent(u, k) << endl;
        }
        else
        {
            int end = dist[u][0] > dist[u][1] ? diameter[0] : diameter[1];
            //cout << "end " << end << endl;
            int lca = getLCA(u, end);
            cout << getParent(end, depth[u] + depth[end] - 2 * depth[lca] - k) << endl;
        }
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     cout << depth[i] << " ";
    // }
    // cout << endl;

    // cout << diameter[0] << ": ";
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << dist[i][0] << " ";
    // }
    // cout << endl;

    // cout << diameter[1] << ": ";
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << dist[i][1] << " ";
    // }
    // cout << endl;
}