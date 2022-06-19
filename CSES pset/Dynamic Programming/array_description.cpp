#include <iostream>
using namespace std;
#define MOD 1000000007

long long dp[100005][105];

int main()
{
    int n, m;
    cin >> n >> m;

    long long ans = 1;
    bool prevZero = false;
    int prev = -1;
    for (int i = 0; i < n; i++)
    {
        int inp;
        cin >> inp;

        if (inp == 0)
        {
            if (i == 0)
            {
                for (int j = 1; j <= m; j++)
                    dp[i][j] = 1;
            }
            else
            {
                for (int j = 1; j <= m; j++)
                {
                    if (j > 1)
                        dp[i][j] += dp[i - 1][j - 1];
                    dp[i][j] += dp[i - 1][j];
                    if (j < m)
                        dp[i][j] += dp[i - 1][j + 1];
                    dp[i][j] %= MOD;
                }
            }
            prevZero = true;
        }
        else
        {
            if (i != 0 && prev != 0 && prev != inp - 1 && prev != inp && prev != inp + 1)
            {
                cout << 0 << endl;
                return 0;
            }

            dp[i][inp] = 1;
            if (prevZero)
            {
                long long temp = 0;
                if (inp > 1)
                    temp += dp[i - 1][inp - 1];
                temp += dp[i - 1][inp];
                if (inp < m)
                    temp += dp[i - 1][inp + 1];
                temp %= MOD;

                ans *= temp;
                ans %= MOD;
            }
            prevZero = false;
        }

        prev = inp;
    }

    if (prevZero)
    {
        long long temp = 0;
        for (int i = 1; i <= m; i++)
        {
            temp += dp[n - 1][i];
            if (temp >= MOD)
                temp -= MOD;
        }
        ans *= temp;
        ans %= MOD;
    }

    cout << ans << endl;
}
