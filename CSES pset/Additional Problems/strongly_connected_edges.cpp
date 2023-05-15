#include <iostream>
#include <vector>
#include <set>
using namespace std;
#define MAXN 100005

vector<int> adj[MAXN];
set<pair<int, int>> ans;
bool good[MAXN], visited[MAXN];

void dfs1(int cur, int prev)
{
    visited[cur] = true;
    for (int next : adj[cur])
    {
        if (next == prev || ans.count({cur, next}) || ans.count({next, cur}))
            continue;
        ans.insert({cur, next});
        if (!visited[next])
            dfs1(next, cur);
    }
}

void dfs2(int cur, int prev)
{
    good[cur] = true;
    for (int next : adj[cur])
    {
        //cout << cur << ", " << next << " " << ans.count({next, cur}) << endl;
        if (next == prev || ans.count({cur, next}))
            continue;
        if (!good[next])
            dfs2(next, cur);
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

    good[1] = true;
    dfs1(1, 0);
    dfs2(1, 0);

    for (int i = 1; i <= n; i++)
    {
        if (!good[i] || !visited[i])
        {
            //cout << i << endl;
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }

    for (auto p : ans)
    {
        cout << p.first << " " << p.second << endl;
    }
}