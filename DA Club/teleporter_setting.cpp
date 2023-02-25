#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAXN 300050

vector<int> undet;
vector<int> adj[MAXN];
int distStart[MAXN];
int distEnd[MAXN];

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        if (u == 0)
        {
            undet.push_back(v - 1);
        }
        else
        {
            adj[u - 1].push_back(v - 1);
            adj[v - 1].push_back(u - 1);
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        distStart[i] = distEnd[i] = -1;
    }

    queue<pair<int, int>> q;
    q.push({0, 0});
    while (!q.empty())
    {
        int dist = q.front().first;
        int cur = q.front().second;
        q.pop();

        if (distStart[cur] != -1)
            continue;
        distStart[cur] = dist;

        for (auto v : adj[cur])
        {
            if (distStart[v] != -1)
                continue;

            q.push({dist + 1, v});
        }
    }
    q.push({0, n - 1});
    while (!q.empty())
    {
        int dist = q.front().first;
        int cur = q.front().second;
        q.pop();

        if (distEnd[cur] != -1)
            continue;
        distEnd[cur] = dist;

        for (auto v : adj[cur])
        {
            if (distEnd[v] != -1)
                continue;

            q.push({dist + 1, v});
        }
    }

    int closestUndetStart = -1, closestUndetEnd = -1;
    for (auto v : undet)
    {
        if (distStart[v] != -1 && (closestUndetStart == -1 || distStart[v] < closestUndetStart))
        {
            closestUndetStart = distStart[v];
        }
        if (distEnd[v] != -1 && (closestUndetEnd == -1 || distEnd[v] < closestUndetEnd))
        {
            closestUndetEnd = distEnd[v];
        }
    }

    for (int i = 0; i < n; i++)
    {
        int res = distStart[n - 1];
        if (distStart[i] != -1 && closestUndetEnd != -1)
        {
            int dist = distStart[i] + closestUndetEnd + 1;
            if (res == -1 || dist < res)
                res = dist;
        }
        if (distEnd[i] != -1 && closestUndetStart != -1)
        {
            int dist = distEnd[i] + closestUndetStart + 1;
            if (res == -1 || dist < res)
                res = dist;
        }
        if (closestUndetEnd != -1 && closestUndetStart != -1)
        {
            int dist = closestUndetEnd + closestUndetStart + 2;
            if (res == -1 || dist < res)
                res = dist;
        }
        cout << res << " ";
    }
    cout << endl;
}