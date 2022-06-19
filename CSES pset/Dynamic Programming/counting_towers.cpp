#include <iostream>
using namespace std;
#define MOD 1000000007

long long dp[1000050][2];

int main()
{
    dp[1][0] = 1;
    dp[1][1] = 1;
    for (int i = 2; i <= 1000000; i++)
    {
        dp[i][0] = 4 * dp[i - 1][0] + dp[i - 1][1];
        dp[i][1] = dp[i - 1][0] + 2 * dp[i - 1][1];

        dp[i][0] %= MOD;
        dp[i][1] %= MOD;
    }

    int t;
    cin >> t;

    for (int z = 0; z < t; z++)
    {
        int n;
        cin >> n;

        cout << (dp[n][0] + dp[n][1]) % MOD << endl;
    }
}
