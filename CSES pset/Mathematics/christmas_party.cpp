#include <iostream>
using namespace std;
#define MOD 1000000007ll
#define MAXN 1000005

long long dp[MAXN];

int main()
{
    int n;
    cin >> n;

    dp[2] = 1;
    for (long long i = 3; i <= n; i++)
    {
        dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2]) % MOD;
    }
    cout << dp[n] << endl;
}
