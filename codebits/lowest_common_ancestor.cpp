#include <iostream>
#include <vector>
using namespace std;
#define MAXN 200005

vector<int> adj[MAXN];
int parent[MAXN][20];
int depth[MAXN];

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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    depth[1] = 1;
    int n, q;
    cin >> n >> q;

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

    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;

        if (getDepth(a) > getDepth(b))
            swap(a, b);

        int res = getDepth(b) - getDepth(a);
        b = getParent(b, res);

        if (a == b)
        {
            cout << res << endl;
            continue;
        }

        for (int j = 18; j >= 0; j--)
        {
            if (parent[a][j] != parent[b][j])
            {
                res += (2 << j);
                a = parent[a][j];
                b = parent[b][j];
            }
        }

        //res is distance between a and b 
        cout << res + 2 << endl;
        //parent[a][0] is LCA
        cout << parent[a][0] << endl;
    }
}