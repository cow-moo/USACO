#include <iostream>
#include <vector>
using namespace std;
#define MAXN 70050

vector<int> adj[MAXN];

int cnt[MAXN];

void dfs(int node, int prev, int level)
{
    cnt[level]++;

    for (int v : adj[node])
    {
        if (v == prev)
            continue;

        dfs(v, node, level + 1);
    }
}

int main()
{
    int t;
    cin >> t;

    for (int z = 1; z <= t; z++)
    {
        int n, q;
        cin >> n >> q;

        for (int i = 0; i < n; i++)
        {
            cnt[i] = 0;
            adj[i].clear();
        }

        for (int i = 0; i < n - 1; i++)
        {
            int a, b;
            cin >> a >> b;
            adj[a - 1].push_back(b - 1);
            adj[b - 1].push_back(a - 1);
        }

        dfs(0, 0, 0);

        for (int i = 0; i < q; i++)
        {
            int c;
            cin >> c;
        }

//        for (int i = 0; i < n; i++)
//        {
//            cout << "c" << i << ": " << cnt[i] << endl;
//        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (q >= cnt[i])
            {
                ans += cnt[i];
                q -= cnt[i];
            }
            else
                break;
        }
        cout << "Case #" << z << ": " << ans << endl;
    }
}
