#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAXN 100005

int minDist[MAXN];
vector<int> adj[MAXN];
int ans = 0;

//min dist to leaf
void findMinDist(int node, int prev)
{
    if (adj[node].size() == 1)
        return;
    minDist[node] = 1000000;
    for (int v : adj[node])
    {
        if (v == prev)
            continue;
        findMinDist(v, node);
        minDist[node] = min(minDist[node], minDist[v] + 1);
    }
}

void dfs(int node, int prev, int dist)
{
    if (minDist[node] <= dist)
    {
        ans++;
        return;
    }

    for (int v : adj[node])
    {
        if (v == prev)
            continue;
        dfs(v, node, dist + 1);
    }
}

int main()
{
    freopen("atlarge.in", "r", stdin);
    freopen("atlarge.out", "w", stdout);

    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    findMinDist(k, 0);
    dfs(k, 0, 0);

    cout << ans << endl;
}