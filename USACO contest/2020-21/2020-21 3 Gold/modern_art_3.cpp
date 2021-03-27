#include <iostream>
using namespace std;
#define INF 10000

int painting[305];
int dp[305][305];

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> painting[i];
        if (i != 0 && painting[i] == painting[i - 1])
        {
            i--; n--;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            if (j == i)
            {
                dp[i][j] = 0;
            }
            else if (j == i + 1)
            {
                dp[i][j] = 1;
            }
            else
            {
                dp[i][j] = INF;
            }
        }
    }

    for (int l = 2; l <= n; l++)
    {
        for (int i = 0; i <= n - l; i++)
        {
            //i to j, j to i + l
            for (int j = i + 1; j < i + l; j++)
            {
                dp[i][i + l] = min(dp[i][i + l], dp[i][j] + dp[j][i + l]);
            }

            if (painting[i] == painting[i + l - 1])
            {
                for (int j = i + 1; j < i + l - 1; j++)
                {
                    if (painting[j] == painting[i])
                    {
                        dp[i][i + l] = min(dp[i][i + l], dp[i][j] + dp[j][i + l] - 1);
                    }
                }
                dp[i][i + l] = min(dp[i][i + l], 1 + dp[i + 1][i + l - 1]);
            }

            //cout << i << " " << i + l << " " << dp[i][i + l] << endl;
        }
    }

    cout << dp[0][n] << endl;
}
