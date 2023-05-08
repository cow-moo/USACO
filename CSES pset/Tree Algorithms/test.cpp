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

long long calc(int depth, long long arr[])
{
    //arr[i] * (arr[k1 - i] + ... + arr[k2 - i])
    //arr[i+1] * (arr[k1-i-1] + ... + arr[k2-i-1])
    long long cur = 0, sum = 0;
    for (int i = k1; i <= min(k2, depth); i++)
    {
        cur += arr[i];
    }

    for (int i = 0; i <= depth; i++)
    {
        sum += arr[i] * cur;
        cur += k1 - i - 1 < 0 ? 0 : arr[k1 - i - 1];
        cur -= arr[k2 - i];
    }
    return sum;
}

void dfs(int cur)
{
    cur = getCentroid(cur, 0, sz[cur]);
    int maxDepth = 0;
    cnt[0] = 1;
    childCnt[0] = 1;
    for (int next : adj[cur])
    {
        if (done[next])
            continue;
        int childDepth = dfsDepth(next, cur, 1);
        cout << cur << " " << next << ": " << childDepth << endl;
        for (int i = 0; i <= childDepth; i++)
        {
            cout << childCnt[i] << " ";
        }
        cout << endl;
        maxDepth = max(maxDepth, childDepth);
        ans -= calc(childDepth, childCnt);
        cout << "ans: " << ans << endl;
        for (int i = 1; i <= childDepth; i++)
        {
            cnt[i] += childCnt[i];
            childCnt[i] = 0;
        }
    }
    //cout << "ans before: " << ans << endl;
    ans += calc(maxDepth, cnt);
    cout << "final: ";
    for (int i = 0; i <= maxDepth; i++)
    {
        cout << cnt[i] << " ";
    }
    cout << endl;
    cout << "final ans: " << ans << endl;
    fill(cnt, cnt + maxDepth + 1, 0);
    //cout << cur << " " << ans << endl;
 
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