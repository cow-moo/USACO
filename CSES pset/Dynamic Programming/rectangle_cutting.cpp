#include <iostream>
using namespace std;
#define INF 1000000

double dp[505][505];

int main()
{
    int a, b;
    cin >> a >> b;

    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            if (i == j)
            {
                dp[i][j] = 1;
            }
            else
            {
                dp[i][j] = INF;
                for (int k = 1; k < i; k++)
                {
                    dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j]);
                }
                for (int k = 1; k < j; k++)
                {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k]);
                }
            }

            //cout << dp[i][j] << " ";
        }
        //cout << endl;
    }

    cout << dp[a][b] - 1 << endl;
}
