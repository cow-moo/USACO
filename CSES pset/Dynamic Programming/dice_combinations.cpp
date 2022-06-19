#include <iostream>
using namespace std;
#define MOD 1000000007

long long dp[10];

int main()
{
    int n;
    cin >> n;

    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        dp[i % 7] = 0;
        for (int j = 0; j < 7; j++)
        {
            if (j != i % 7)
            {
                dp[i % 7] += dp[j];
                if (dp[i % 7] >= MOD)
                    dp[i % 7] -= MOD;
            }
        }
    }

    cout << dp[n % 7] << endl;
}
