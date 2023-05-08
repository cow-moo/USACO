#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define MAXN 100005

long long dist[MAXN][2];
vector<pair<int, long long>> adj[MAXN];

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a - 1].push_back({b - 1, c});
    }

    for (int i = 0; i < n; i++)
    {
        dist[i][0] = dist[i][1] = -1;
    }

    priority_queue<pair<long long, pair<int, int>>> pq;
    pq.push({0, {0, 0}});
    while (!pq.empty())
    {
        auto [d, cur] = pq.top();
        d = -d;
        pq.pop();

        if (dist[cur.first][cur.second] != -1 && dist[cur.first][cur.second] <= d)
            continue;
        dist[cur.first][cur.second] = d;
        if (cur.first == n - 1)
        {
            cout << d << endl;
            return 0;
        }

        for (auto p : adj[cur.first])
        {
            if (dist[p.first][cur.second] == -1)
            {
                pq.push({-(d + p.second), {p.first, cur.second}});
            }
            if (cur.second == 0 && dist[p.first][1] == -1)
            {
                pq.push({-(d + p.second / 2), {p.first, 1}});
            }
        }
    }
}