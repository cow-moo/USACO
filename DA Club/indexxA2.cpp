#include <iostream>
#include <algorithm>
using namespace std;
#define INF 500000000000ll

long long dp[2005];

int main()
{
    int n, m;
    cin >> n >> m;

    fill(dp + 1, dp + m + 1, -INF);

    for (int i = 0; i < n; i++)
    {
        long long a;
        cin >> a;
        for (long long j = min(i + 1, m); j >= 1; j--)
        {
            if (dp[j - 1] != -INF)
                dp[j] = max(dp[j - 1] + j * a, dp[j]);
        }
    }

    cout << dp[m] << endl;
}