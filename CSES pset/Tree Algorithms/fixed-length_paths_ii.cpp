#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
#define MAXN 200005

long long bit[MAXN];

long long sum(int i)
{
    i++;
    long long sum = 0;
    while (i > 0)
    {
        sum += bit[i];
        i -= (i) & -(i);
    }
    return sum;
}

void add(int i, long long delta)
{
    i++;
    while (i <= MAXN)
    {
        bit[i] += delta;
        i += (i) & -(i);
    }
}

vector<int> adj[MAXN];
long long ans = 0;
int k1, k2, sz[MAXN];
bool done[MAXN];

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
    //k1 - depth to k2 - depth
    ans += sum(k2 - depth) - sum(k1 - depth - 1);
    if (depth == k2)
        return;
    for (int next : adj[cur])
    {
        if (next == prev || done[next])
            continue;
        dfsUpdateAns(next, cur, depth + 1);
    }
}

int maxDepth;
void dfsUpdateCnt(int cur, int prev, int depth)
{
    maxDepth = max(maxDepth, depth);
    add(depth, 1);
    if (depth == k2)
        return;
    for (int next : adj[cur])
    {
        if (next == prev || done[next])
            continue;
        dfsUpdateCnt(next, cur, depth + 1);
    }
}

void dfsResetCnt(int cur, int prev, int depth)
{
    add(depth, -1);
    if (depth == k2)
        return;
    for (int next : adj[cur])
    {
        if (next == prev || done[next])
            continue;
        dfsResetCnt(next, cur, depth + 1);
    }
}

void dfs(int cur)
{
    dfsSize(cur, 0);
    cur = getCentroid(cur, 0, sz[cur]);
    //cout << cur << endl;

    for (int next : adj[cur])
    {
        if (done[next])
            continue;
        dfsUpdateAns(next, cur, 1);
        dfsUpdateCnt(next, cur, 1);
    }

    dfsResetCnt(cur, 0, 0);
    add(0, 1);

    done[cur] = true;

    for (int next : adj[cur])
    {
        if (done[next])
            continue;
        dfs(next);
    }
}

int main()
{
    int n;
    cin >> n >> k1 >> k2;

    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    add(0, 1);
    dfs(1);

    cout << ans << endl;
}