#include <iostream>
using namespace std;
#define MOD 1000000007

long long dp[70000];

int main()
{
    int n;
    cin >> n;

    if (n % 4 != 0 && n % 4 != 3)
    {
        cout << 0 << endl;
        return 0;
    }

    int maxim = n * (n + 1) / 4;

    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = maxim; j >= i; j--)
        {
            dp[j] += dp[j - i];
            if (dp[j] >= MOD)
                dp[j] -= MOD;
        }
    }

    cout << dp[maxim] << endl;
}
