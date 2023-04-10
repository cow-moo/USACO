#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 200005

int nxt[MAXN][20];
int dist[MAXN];

int dfs(int cur)
{
    if (dist[nxt[cur][0]] == MAXN)
    {
        dist[cur] = -1;
        return nxt[cur][0];
    }
    else if (dist[nxt[cur][0]] == 0)
    {
        dist[cur] = MAXN;
        int res = dfs(nxt[cur][0]);
        if (res != 0)
        {
            dist[cur] = dist[nxt[cur][0]] - 1;
            return res == cur ? 0 : res;
        }
    }
    
    if (dist[nxt[cur][0]] > 0)
    {
        dist[cur] = dist[nxt[cur][0]] + 1;
    }
    else
    {
        dist[cur] = 1;
    }
    return 0;
}

int jump(int cur, int k)
{
    for (int i = 0; (1 << i) <= k; i++)
    {
        if (k & (1 << i))
            cur = nxt[cur][i];
    }
    return cur;
}

int main()
{
    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++)
    {
        cin >> nxt[i][0];
    }

    for (int i = 1; i <= 18; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            nxt[j][i] = nxt[nxt[j][i - 1]][i - 1];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (dist[i] == 0)
            dfs(i);
        //cout << i << ": " << dist[i] << endl;
    }

    for (int i = 0; i < q; i++)
    {
        int a, b, ans = 0;
        cin >> a >> b;

        if (max(dist[a], 0) < max(dist[b], 0))
        {
            cout << -1 << endl;
            continue;
        }

        if (dist[a] > 0)
        {
            ans += dist[a] - max(dist[b], 0);
            a = jump(a, dist[a] - max(dist[b], 0));

            if (dist[a] > 0 && a != b)
            {
                cout << -1 << endl;
                continue;
            }
        }

        if (dist[a] > dist[b])
        {
            ans -= dist[a];
            a = jump(a, -dist[a]);
        }

        ans += dist[b] - dist[a];
        a = jump(a, dist[b] - dist[a]);

        cout << (a == b ? ans : -1) << endl;
    }
}