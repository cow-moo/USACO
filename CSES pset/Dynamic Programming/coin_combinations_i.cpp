#include <iostream>
using namespace std;
#define MOD 1000000007

int coins[105];
long long dp[1000050];

int main()
{
    int n, x;
    cin >> n >> x;

    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    dp[0] = 1;
    for (int i = 1; i <= x; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i - coins[j] >= 0)
            {
                dp[i] += dp[i - coins[j]];
                if (dp[i] >= MOD)
                    dp[i] -= MOD;
            }
        }
    }

    cout << dp[x] << endl;
}
