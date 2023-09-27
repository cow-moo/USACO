#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MOD 1000000007

vector<int> adj[25];
long long dp[25][1100000];

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a - 1].push_back(b - 1);
    }

    queue<pair<int, int>> q;
    q.push({0, 1});
    dp[0][1] = 1;
    while (!q.empty())
    {
        auto [cur, mask] = q.front();
        q.pop();
        //cout << cur << " " << mask << endl;

        for (auto next : adj[cur])
        {
            if (mask & (1 << next))
                continue;
            if (dp[next][mask | (1 << next)] == 0)
                q.push({next, mask | (1 << next)});
            dp[next][mask | (1 << next)] += dp[cur][mask];
            if (dp[next][mask | (1 << next)] >= MOD)
                dp[next][mask | (1 << next)] -= MOD;
        }
    }
    cout << dp[n - 1][(1 << n) - 1] << endl;
}