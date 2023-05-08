#include <iostream>
#include <vector>
using namespace std;
#define MAXN 100005
#define MOD 1000000007

vector<int> adj[MAXN];
vector<int> ans;
bool visited[MAXN];
long long dp[MAXN];

void dfs(int cur)
{
    if (visited[cur] != 0)
        return;
    visited[cur] = true;
    for (int v : adj[cur])
        dfs(v);
    ans.push_back(cur);
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a - 1].push_back(b - 1);
    }
    
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            dfs(i);
    }

    dp[0] = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int v : adj[ans[i]])
        {
            dp[v] += dp[ans[i]];
            if (dp[v] >= MOD)
                dp[v] -= MOD;
        }
    }

    cout << dp[n - 1] << endl;
}