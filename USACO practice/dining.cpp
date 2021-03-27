#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int> > adj[50005];
int dist[50005];
bool ans[50005];
bool visited[50005];

int main()
{
    freopen("dining.in", "r", stdin);
    freopen("dining.out", "w", stdout);

    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 0; i < m; i++)
    {
        int a, b, t;
        cin >> a >> b >> t;
        a--; b--;
        adj[a].push_back({b, t});
        adj[b].push_back({a, t});
    }

    for (int i = 0; i < n; i++)
        dist[i] = -1;

    //neg dist, index
    priority_queue<pair<int, int> > pq;
    pq.push({0, n - 1});

    while (!pq.empty())
    {
        int curDist = -pq.top().first;
        int curIndex = pq.top().second;
        pq.pop();

        if (dist[curIndex] != -1)
            continue;

        dist[curIndex] = curDist;

        for (pair<int, int> v : adj[curIndex])
        {
            if (dist[v.first] == -1)
                pq.push({-(curDist + v.second), v.first});
        }
    }

//    for (int i = 0; i < n; i++)
//        cout << dist[i] << endl;

    for (int i = 0; i < k; i++)
    {
        int pasture, yummy;
        cin >> pasture >> yummy;
        pasture--;

        pq.push({0, pasture});

        while (!pq.empty())
        {
            int curDist = -pq.top().first;
            int curIndex = pq.top().second;
            pq.pop();

            if (visited[curIndex])
                continue;

            visited[curIndex] = true;

            for (pair<int, int> v : adj[curIndex])
            {
                if (!visited[v.first] && curDist + v.second + dist[pasture] <= dist[v.first] + yummy)
                    pq.push({-(curDist + v.second), v.first});
            }
        }


        for (int j = 0; j < n; j++)
        {
            if (visited[j])
                ans[j] = true;
            visited[j] = false;
        }
    }

    for (int i = 0; i < n - 1; i++)
        cout << ans[i] << endl;
}
