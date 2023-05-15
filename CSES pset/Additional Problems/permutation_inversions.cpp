#include <iostream>
using namespace std;
#define MAXK 130000
#define MOD 1000000007ll

long long dp[MAXK];

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n, k;
    cin >> n >> k;

    dp[0] = 1;
    int r = 0;
    for (int i = 1; i < n; i++)
    {
        int sum = 0;
        for (int j = i + r; j >= 0; j--)
        {
            if (j - i >= 0)
            {
                sum += dp[j - i] - dp[j];
                if (sum < 0)
                    sum += MOD;
                else if (sum >= MOD)
                    sum -= MOD;
            }
            else
            {
                sum -= dp[j];
                if (sum < 0)
                    sum += MOD;
            }
            dp[j] += sum;
            if (dp[j] >= MOD)
                dp[j] -= MOD;
        }
        r += i;
    }
    cout << dp[k] << endl;
}