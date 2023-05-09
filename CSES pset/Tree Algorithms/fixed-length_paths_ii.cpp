#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
#define MAXN 200005
 
vector<int> adj[MAXN];
long long ans = 0;
int k1, k2, sz[MAXN];
bool done[MAXN];
long long cnt[MAXN], childCnt[MAXN];
 
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

int dfsDepth(int cur, int prev, int depth)
{
    childCnt[depth]++;
    if (depth == k2)
        return depth;
    int maxDepth = depth;
    for (int next : adj[cur])
    {
        if (next == prev || done[next])
            continue;
        maxDepth = max(maxDepth, dfsDepth(next, cur, depth + 1));
    }
    return maxDepth;
}

long long calc(int depth, long long arr[])
{
    long long res = 0, cur = 0;
    for (int i = k1; i <= k2; i++)
    {
        if (i > depth)
            break;
        cur += arr[i];
    }
    for (int i = 0; i <= depth; i++)
    {
        res += arr[i] * cur;
        if (k1 - i - 1 >= 0)
            cur += arr[k1 - i - 1];
        cur -= arr[k2 - i];
    }
    return res;
}
 
void dfs(int cur)
{
    cur = getCentroid(cur, 0, sz[cur]);
    int maxDepth = 0;
    cnt[0] = 1;
    for (int next : adj[cur])
    {
        if (done[next])
            continue;
        int childDepth = dfsDepth(next, cur, 1);
        maxDepth = max(maxDepth, childDepth);
        ans -= calc(childDepth, childCnt);
        for (int i = 0; i <= childDepth; i++)
        {
            cnt[i] += childCnt[i];
            childCnt[i] = 0;
        }
    }
    ans += calc(maxDepth, cnt);
    fill(cnt, cnt + maxDepth + 1, 0);

    done[cur] = true;

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
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n >> k1 >> k2;
 
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
 
    dfsSize(1, 0);
    dfs(1);
 
    cout << ans / 2 << endl;
}