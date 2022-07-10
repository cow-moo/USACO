#include <iostream>
using namespace std;
#define MAXN 2505
#define INF 1000000000000

int word[MAXN], keyboard[MAXN];
long long dp[MAXN][MAXN];

int main()
{
    int t;
    cin >> t;

    for (int z = 1; z <= t; z++)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> word[i];
        }

        int m;
        cin >> m;
        for (int i = 0; i < m; i++)
        {
            cin >> keyboard[i];
        }

        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                dp[i][j] = -1;
            }
        }

        for (int i = 0; i < m; i++)
        {
            if (keyboard[i] == word[0])
                dp[0][i] = 0;
        }

        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 1; j < m; j++)
            {
                if (dp[i][j - 1] != -1)
                {
                    if (dp[i][j] == -1)
                        dp[i][j] = dp[i][j - 1] + 1;
                    else
                        dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
                }
            }

            for (int j = m - 2; j >= 0; j--)
            {
                if (dp[i][j + 1] != -1)
                {
                    if (dp[i][j] == -1)
                        dp[i][j] = dp[i][j + 1] + 1;
                    else
                        dp[i][j] = min(dp[i][j], dp[i][j + 1] + 1);
                }
            }

            for (int j = 0; j < m; j++)
            {
                if (keyboard[j] == word[i + 1])
                    dp[i + 1][j] = dp[i][j];
            }
        }

        long long ans = INF;
        for (int j = 0; j < m; j++)
        {
            if (dp[n - 1][j] != -1)
                ans = min(ans, dp[n - 1][j]);
        }
        cout << "Case #" << z << ": " << ans << endl;
    }
}
