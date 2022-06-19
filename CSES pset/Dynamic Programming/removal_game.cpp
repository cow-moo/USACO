#include <iostream>
using namespace std;

long long arr[5005];
pair<long long, long long> dp[5005][5005];
//length, start

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= n - i; j++)
        {
            //maximize i % 2
            if (i % 2 == 0)
            {
                dp[i][j].first = max(dp[i - 1][j].first + arr[i + j - 1], dp[i - 1][j + 1].first + arr[j]);
                if (dp[i - 1][j].first + arr[i + j - 1] > dp[i - 1][j + 1].first + arr[j])
                    dp[i][j].second = dp[i - 1][j].second;
                else
                    dp[i][j].second = dp[i - 1][j + 1].second;
            }
            else
            {
                dp[i][j].second = max(dp[i - 1][j].second + arr[i + j - 1], dp[i - 1][j + 1].second + arr[j]);
                if (dp[i - 1][j].second + arr[i + j - 1] > dp[i - 1][j + 1].second + arr[j])
                    dp[i][j].first = dp[i - 1][j].first;
                else
                    dp[i][j].first = dp[i - 1][j + 1].first;
            }
        }
    }

    pair<long long, long long> ans = dp[n][0];
    cout << (n % 2 == 0 ? ans.first : ans.second) << endl;
}
