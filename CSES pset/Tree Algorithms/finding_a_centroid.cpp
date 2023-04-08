#include <iostream>
#include <vector>
using namespace std;
#define MAXN 200005

int ans, n, sz[MAXN];
vector<int> adj[MAXN];

void dfsSize(int cur, int prev)
{
    sz[cur] = 1;
    for (int next : adj[cur])
    {
        if (next == prev)
            continue;
        dfsSize(next, cur);
        sz[cur] += sz[next];
    }
}

int getCentroid(int cur, int prev)
{
    for (int next : adj[cur])
    {
        if (next == prev)
            continue;
        if (sz[next] * 2 > n)
            return getCentroid(next, cur);
    }
    return cur;
}

int main()
{
    cin >> n;

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfsSize(1, 0);
    cout << getCentroid(1, 0) << endl;
}