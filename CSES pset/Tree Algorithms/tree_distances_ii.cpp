#include <iostream>
#include <vector>
using namespace std;
#define MAXN 200005

vector<int> adj[MAXN];
int parent[MAXN], n;
long long dist[MAXN], cnt[MAXN];

void dfs1(int cur)
{
    cnt[cur] = 1;
    dist[cur] = 0;
    for (int next : adj[cur])
    {
        if (next == parent[cur])
            continue;
        parent[next] = cur;
        dfs1(next);
        cnt[cur] += cnt[next];
        dist[cur] += cnt[next] + dist[next];
    }
}

void dfs2(int cur)
{
    if (parent[cur] != 0)
    {
        dist[cur] = n - cnt[cur] * 2 + dist[parent[cur]];
    }
    for (int next : adj[cur])
    {
        if (next == parent[cur])
            continue;
        dfs2(next);
    }
}
//1 2
//  3 4
//    5

int main()
{
    cin >> n;

    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs1(1);
    dfs2(1);

    for (int i = 1; i <= n; i++)
    {
        cout << dist[i] << " ";
    }
    cout << endl;
}