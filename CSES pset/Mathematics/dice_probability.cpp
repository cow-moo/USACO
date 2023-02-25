#include <iostream>
#include <iomanip>
using namespace std;
#define MAXN 105
#define LIM 1000000000000000ll

long long dp[2][MAXN * 6];

int main()
{
    int n, a, b;
    cin >> n >> a >> b;

    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        bool over = false;
        for (int j = 6 * i; j >= 0; j--)
        {
            dp[1][j] = 0;
            for (int k = max(0, j - 6); k < j; k++)
            {
                dp[1][j] += dp[0][k];
            }
            if (dp[1][j] >= LIM)
            {
                over = true;
            }
        }
        if (over)
        {
            for (int k = 0; k <= 6 * i; k++)
            {
                dp[1][k] /= 10;
            }
        }
        swap(dp[1], dp[0]);
    }

    long long sum = 0;
    long long cnt = 0;
    for (int i = 0; i <= n * 6; i++)
    {
        sum += dp[0][i];
        if (a <= i && i <= b)
            cnt += dp[0][i];
        //cout << dp[0][i] << " ";
    }
    //cout << endl << sum << " " << cnt << endl;
    cout << fixed << setprecision(6);
    cout << (double)cnt / sum << endl;
}