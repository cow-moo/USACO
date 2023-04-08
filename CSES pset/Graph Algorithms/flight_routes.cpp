#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAXN 100005

vector<pair<int, long long>> adj[MAXN];
vector<long long> dist[MAXN];

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    priority_queue<pair<long long, int>> pq;
    pq.push({0, 1});
    while (!pq.empty())
    {
        auto [d, cur] = pq.top();
        pq.pop();
        d = -d;

        if (dist[cur].size() >= k)
            continue;
        dist[cur].push_back(d);

        for (auto next : adj[cur])
        {
            if (dist[next.first].size() < k)
            {
                pq.push({-(d + next.second), next.first});
            }
        }
    }

    for (long long d : dist[n])
    {
        cout << d << " ";
    }
    cout << endl;
}