#include <iostream>
#include <vector>
using namespace std;
#define MAXN 200005

vector<pair<int, int>> adj[MAXN];
int ans[MAXN];

void dfs(int cur, int prev, int dist)
{
    cout << cur << " " << prev << " " << dist << endl;
    for (pair<int, int> &v : adj[cur])
    {
        cout << "a";
        if (v.first == prev)
            continue;
        if (dist + 1 > v.second)
        {
            v.second = dist + 1;
            ans[v.first] = max(ans[v.first], dist + 1);
            dfs(v.first, cur, dist + 1);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a - 1].push_back({b - 1, 0});
        adj[b - 1].push_back({a - 1, 0});
    }

    for (int i = 0; i < n; i++)
    {
        if (adj[i].size() == 1)
            dfs(i, -1, 0);
        cout << endl;
    }

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}
