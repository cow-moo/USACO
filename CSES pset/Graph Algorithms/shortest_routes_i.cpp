#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define MAXN 100005

vector<pair<int, long long>> adj[MAXN];
long long dist[MAXN];

int main()
{
    int n, m;
    cin >> n >> m;
    fill(dist, dist + n, -1);

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a - 1].push_back({b - 1, c});
    }

    priority_queue<pair<long long, int>> pq;
    pq.push({0, 0});
    while (!pq.empty())
    {
        auto [d, cur] = pq.top();
        pq.pop();
        d = -d;
        if (dist[cur] != -1)
            continue;
        dist[cur] = d;

        for (auto p : adj[cur])
        {
            if (dist[p.first] == -1)
            {
                pq.push({-(d + p.second), p.first});
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << dist[i] << " ";
    }
    cout << endl;
    //priority_queue<
}