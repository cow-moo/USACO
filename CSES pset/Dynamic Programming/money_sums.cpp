#include <iostream>
using namespace std;

bool dp[100050];

int main()
{
    int n;
    cin >> n;

    int maxim = 0;
    dp[0] = true;
    for (int i = 0; i < n; i++)
    {
        int inp;
        cin >> inp;

        for (int j = maxim; j >= 0; j--)
        {
            dp[j + inp] = dp[j + inp] || dp[j];
        }
        maxim += inp;
    }

    int cnt = 0;
    for (int i = 1; i <= maxim; i++)
    {
        if (dp[i])
            cnt++;
    }

    cout << cnt << endl;

    for (int i = 1; i <= maxim; i++)
    {
        if (dp[i])
            cout << i << " ";
    }
    cout << endl;
}
