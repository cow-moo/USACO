#include <iostream>
#include <vector>
using namespace std;
#define MAXN 100005

vector<pair<int, int>> adj[MAXN];
vector<pair<int, int>> ans;
bool parity[MAXN], visited[MAXN];

void dfs(int cur, int edge)
{
    visited[cur] = true;
    for (auto p : adj[cur])
    {
        if (p.second == edge || visited[p.first])
            continue;
        dfs(p.first, p.second);
        if (parity[p.first])
        {
            swap(ans[p.second].first, ans[p.second].second);
            parity[p.first] = false;
            parity[cur] = !parity[cur];
        }
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
        adj[a].push_back({b, i});
        adj[b].push_back({a, i});

        parity[a] = ! parity[a];
        ans.push_back({a, b});
    }

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
            dfs(i, -1);
    }

    for (int i = 1; i <= n; i++)
    {
        if (parity[i])
        {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }

    for (auto p : ans)
    {
        cout << p.first << " " << p.second << endl;
    }
}