#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAXN 100005

vector<int> adj[MAXN], rev[MAXN], order, adjComponent[MAXN];
bool visited[MAXN];
int components[MAXN];
long long coins[MAXN], dp[MAXN];

void dfs1(int cur)
{
    visited[cur] = true;
    for (int next : adj[cur])
    {
        if (visited[next])
            continue;
        dfs1(next);
    }
    order.push_back(cur);
}

void dfs2(int cur, int num)
{
    components[cur] = num;
    for (int next : rev[cur])
    {
        if (components[next])
            continue;
        dfs2(next, num);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        cin >> coins[i];
    }

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        rev[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
            dfs1(i);
    }

    int cnt = 0;
    for (int i = order.size() - 1; i >= 0; i--)
    {   
        if (components[order[i]] == 0)
            dfs2(order[i], ++cnt);
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j : adj[i])
        {
            if (components[i] != components[j])
            {
                adjComponent[components[i]].push_back(components[j]);
            }
        }
        dp[components[i]] += coins[i];
    }

    for (int i = cnt; i >= 1; i--)
    {
        long long best = 0;
        for (int j : adjComponent[i])
        {
            best = max(best, dp[j]);
        }
        dp[i] += best;
    }

    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
}