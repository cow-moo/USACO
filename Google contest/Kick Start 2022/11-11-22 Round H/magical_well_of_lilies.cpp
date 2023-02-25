#include <iostream>
using namespace std;
#define MAXN 100050

int dp[MAXN];

int main()
{
    for (int i = 1; i <= 100000; i++)
    {
        dp[i] = dp[i - 1] + 1;

        for (int j = 2; j < i; j++)
        {
            if (i % j == 0)
            {
                dp[i] = min(dp[i], dp[i / j] + 2 * j + 2);
            }
            if (2 * j + 2 > dp[i])
            {
                break;
            }
        }
    }

    int t;
    cin >> t;

    for (int z = 1; z <= t; z++)
    {
        int l;
        cin >> l;

        cout << "Case #" << z << ": " << dp[l] << endl;
    }
}
