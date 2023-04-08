#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define MAXN 100005

vector<pair<int, long long>> adj[MAXN];
bool visited[MAXN];

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        a--; b--;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    long long ans = 0;
    int cnt = 0;
    priority_queue<pair<long long, int>> pq;
    pq.push({0, 0});
    while (!pq.empty())
    {
        auto [cost, cur] = pq.top();
        pq.pop();

        if (visited[cur])
            continue;
        visited[cur] = true;
        ans -= cost;
        cnt++;

        for (auto p : adj[cur])
        {
            if (!visited[p.first])
            {
                pq.push({-p.second, p.first});
            }
        }
    }
    if (cnt == n)
        cout << ans << endl;
    else
        cout << "IMPOSSIBLE" << endl;
}