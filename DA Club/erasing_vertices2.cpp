#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define MAXN 200005

long long vals[MAXN], costs[MAXN];
vector<int> adj[MAXN];
bool removed[MAXN];

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        cin >> vals[i];
    }

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
        costs[u] += vals[v];
        costs[v] += vals[u];
    }

    priority_queue<pair<long long, int>> pq;
    for (int i = 1; i <= n; i++)
    {
        pq.push({-costs[i], i});
    }

    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        while (pq.top().first != -costs[pq.top().second] || removed[pq.top().second])
        {
            pq.pop();
        }
        int cur = pq.top().second;
        pq.pop();

        removed[cur] = true;
        ans = max(ans, costs[cur]);

        for (int next : adj[cur])
        {
            costs[next] -= vals[cur];
            pq.push({-costs[next], next});
        }
    }
    cout << ans << endl;
}