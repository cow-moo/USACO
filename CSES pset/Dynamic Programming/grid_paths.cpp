#include <iostream>
using namespace std;
#define MOD 1000000007

long long dp[1005][1005];

int main()
{
    int n;
    cin >> n;

    dp[1][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        for (int j = 1; j <= n; j++)
        {
            if (s[j - 1] == '.')
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                if (dp[i][j] >= MOD)
                    dp[i][j] -= MOD;
            }
        }
    }

    cout << dp[n][n] << endl;
}
