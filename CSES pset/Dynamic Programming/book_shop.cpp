#include <iostream>
using namespace std;

//price, pages
pair<int, int> books[1005];
long long dp[100050];

int main()
{
    int n, x;
    cin >> n >> x;

    for (int i = 0; i < n; i++)
    {
        cin >> books[i].first;
    }

    for (int i = 0; i < n; i++)
    {
        cin >> books[i].second;
    }

    for (int i = 1; i <= x; i++)
        dp[i] = -1;

    for (int i = 0; i < n; i++)
    {
        for (int j = x; j >= books[i].first; j--)
        {
            if (dp[j - books[i].first] != -1)
            {
                dp[j] = max(dp[j], dp[j - books[i].first] + books[i].second);
            }
        }
    }

    long long ans = 0;
    for (int i = 0; i <= x; i++)
    {
        ans = max(ans, dp[i]);
    }

    cout << ans << endl;
}
