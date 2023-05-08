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
long long cnt[MAXN], prefix[MAXN], init = 0;
long long childCnt[MAXN];
int maxDepth = 0;
 
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
 
void dfsUpdateAns(int cur, int prev, int depth, int sum)
{
    //k1 - depth to k2 - depth
    //cout << "a " << depth << ": " << prefix[clamp(k2 - depth, 0, maxDepth)] << " " << prefix[clamp(k1 - depth - 1, 0, maxDepth)] << endl;
    //cout << "b " << depth << ": " << clamp(k2 - depth, 0, maxDepth) << " " << k1 - depth - 1 << endl;
    //ans += prefix[min(k2 - depth, maxDepth)] - (k1 - depth - 1 < 0 ? 0 : prefix[min(k1 - depth - 1, maxDepth)]);
    ans += sum;
    sum += (k1 - depth - 1 < 0 ? 0 : cnt[k1 - depth - 1]) - cnt[k2 - depth];
    if (depth == k2)
        return;
    for (int next : adj[cur])
    {
        if (next == prev || done[next])
            continue;
        dfsUpdateAns(next, cur, depth + 1, sum);
    }
}
 
void dfsUpdateCnt(int cur, int prev, int depth)
{
    cnt[depth]++;
    if (depth >= k1 - 1 && depth <= k2 - 1)
        init++;
    if (depth == k2)
        return;
    for (int next : adj[cur])
    {
        if (next == prev || done[next])
            continue;
        dfsUpdateCnt(next, cur, depth + 1);
    }
}


int dfsDepth(int cur, int prev, int depth)
{
    //maxDepth = max(maxDepth, depth);
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
 
void dfs(int cur)
{
    cur = getCentroid(cur, 0, sz[cur]);
    maxDepth = 0;
    dfsDepth(cur, 0, 0);
    cnt[0] = 1;
    init = 0;
    for (int next : adj[cur])
    {
        if (done[next])
            continue;
        dfsUpdateAns(next, cur, 1, init);
        dfsUpdateCnt(next, cur, 1);
        // for (int i = 1; i <= maxDepth; i++)
        // {
        //     prefix[i] = prefix[i - 1] + cnt[i];
        // }
        //cout << "faeothapweio: " << next << " " << ans << " " << init << endl;
    }
    fill(cnt, cnt + maxDepth + 1, 0);
    //fill(prefix, prefix + maxDepth + 1, 1);

    // cout << cur << ": ";
    // for (int i = 0; i <= maxDepth; i++)
    // {
    //     cout << cnt[i] << " ";
    // }
    // cout << endl;
    // for (int i = 0; i <= maxDepth; i++)
    // {
    //     cout << prefix[i] << " ";
    // }
    // cout << endl;
    // cout << ans << endl;
 
    //fill(bit, bit + bitSz + 2, 0);
    //fill(cnt, cnt + maxDepth + 1, 0);
    //fill(prefix, prefix + maxDepth + 1, 0);
   // bitSz = 0;
 
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
    //freopen("test_input.txt", "r", stdin);
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
 
    cout << ans << endl;
}