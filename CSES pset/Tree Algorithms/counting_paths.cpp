#include <iostream>
#include <vector>
using namespace std;
#define MAXN 200005

vector<int> adj[MAXN];
int parent[MAXN][20];
int depth[MAXN], vals[MAXN];
long long ans[MAXN];

int getDepth(int cur)
{
    if (depth[cur] == 0)
        return depth[cur] = getDepth(parent[cur][0]) + 1;
    else
        return depth[cur];
}

int getParent(int x, int k)
{
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
        dfs(v);
    }
}

void dfs2(int cur)
{
    ans[cur] = vals[cur];
    for (int v : adj[cur])
    {
        if (v == parent[cur][0])
            continue;
        dfs2(v);
        ans[cur] += ans[v];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    depth[1] = 1;
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1);

    for (int i = 1; i <= 18; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            parent[j][i] = parent[parent[j][i - 1]][i - 1];
        }
    }

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        vals[a]++, vals[b]++;

        if (getDepth(a) > getDepth(b))
            swap(a, b);

        b = getParent(b, getDepth(b) - getDepth(a));

        if (a == b)
        {
            vals[a]--;
            vals[parent[a][0]]--;
            continue;
        }

        for (int j = 18; j >= 0; j--)
        {
            if (parent[a][j] != parent[b][j])
            {
                a = parent[a][j];
                b = parent[b][j];
            }
        }

        vals[parent[a][0]]--;
        vals[parent[parent[a][0]][0]]--;
        //cout << parent[a][0] << endl;
    }

    dfs2(1);

    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}