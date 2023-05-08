#include <iostream>
#include <vector>
using namespace std;
#define MAXN 200005

vector<int> adj[MAXN];
int ans[MAXN], dist[MAXN];

int dfs(int cur, int prev)
{
    int res = cur;
    for (int next : adj[cur])
    {
        if (next == prev)
            continue;
        dist[next] = dist[cur] + 1;
        int temp = dfs(next, cur);
        if (dist[temp] > dist[res])
            res = temp;
    }
    return res;
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
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    fill(dist + 1, dist + n + 1, -1);
    dist[1] = 0;
    int res = dfs(1, 0);

    fill(dist + 1, dist + n + 1, -1);
    dist[res] = 0;
    res = dfs(res, 0);

    for (int i = 1; i <= n; i++)
    {
        ans[i] = max(ans[i], dist[i]);
        dist[i] = -1;
    }
    dist[res] = 0;
    res = dfs(res, 0);

    for (int i = 1; i <= n; i++)
    {
        cout << max(ans[i], dist[i]) << " ";
    }
    cout << endl;
}
