#include <iostream>
using namespace std;

int dp[5005][5005];

int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    for (int i = 1; i <= s1.length(); i++)
        dp[i][0] = i;

    for (int j = 1; j <= s2.length(); j++)
        dp[0][j] = j;

    for (int i = 1; i <= s1.length(); i++)
    {
        for (int j = 1; j <= s2.length(); j++)
        {
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
            else
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1);
        }
    }

    cout << dp[s1.length()][s2.length()] << endl;
}
