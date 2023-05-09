#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
#define MAXN 200005

vector<int> adj[MAXN];
long long ans = 0;
int k, sz[MAXN];
bool done[MAXN];

//cnt of each depth
int cnt[MAXN];

void dfsSize(int cur, int prev)
{
    sz[cur] = 1;
    for (int next : adj[cur])
    {
        if (next == prev || done[next])
            continue;
        dfsSize(next, cur);
        sz[cur] += sz[next];
    }
}

int getCentroid(int cur, int prev, int treeSz)
{
    for (int next : adj[cur])
    {
        if (next == prev || done[next])
            continue;
        if (sz[next] * 2 > treeSz)
            return getCentroid(next, cur, treeSz);
    }
    return cur;
}

void dfsUpdateAns(int cur, int prev, int depth)
{
    ans += cnt[k - depth];
    if (depth == k)
        return;
    for (int next : adj[cur])
    {
        if (next == prev || done[next])
            continue;
        dfsUpdateAns(next, cur, depth + 1);
    }
}

void dfsUpdateCnt(int cur, int prev, int depth)
{
    cnt[depth]++;
    if (depth == k)
        return;
    for (int next : adj[cur])
    {
        if (next == prev || done[next])
            continue;
        dfsUpdateCnt(next, cur, depth + 1);
    }
}

void dfs(int cur)
{
    cur = getCentroid(cur, 0, sz[cur]);

    for (int next : adj[cur])
    {
        if (done[next])
            continue;
        dfsUpdateAns(next, cur, 1);
        dfsUpdateCnt(next, cur, 1);
    }

    done[cur] = true;

    fill(cnt + 1, cnt + min(sz[cur], k + 1), 0);
    for (int next : adj[cur])
    {
        if (done[next])
            continue;
        if (sz[next] > sz[cur])
            dfsSize(next, 0);
        dfs(next);
    }
}

int main()
{
    int n;
    cin >> n >> k;

    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    cnt[0] = 1;
    dfsSize(1, 0);
    dfs(1);

    cout << ans << endl;
}