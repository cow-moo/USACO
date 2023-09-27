#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 1550

long long adj[MAXN][MAXN], dp[MAXN][MAXN];

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> adj[i][j];
        }
    }

    for (int i = n - 1; i > 0; i--)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (dp[i - 1][j] == 0 || dp[i][j] + adj[i - 1][i] < dp[i - 1][j])
                dp[i - 1][j] = dp[i][j] + adj[i - 1][i];
            if (dp[i - 1][i] == 0 || dp[i][j] + adj[j][i - 1] < dp[i - 1][i])
                dp[i - 1][i] = dp[i][j] + adj[j][i - 1];
        }
    }

    long long ans = dp[0][1] + adj[0][1];
    for (int i = 1; i < n; i++)
    {
        ans = min(ans, dp[0][i] + adj[0][i]);
    }
    cout << ans << endl;
}