#include <iostream>
#include <set>
using namespace std;
#define MAXN 2000

int dp[MAXN];

int main()
{
    for (int i = 2; i < MAXN; i++)
    {
        set<int> s;
        for (int j = 1; j < (i + 1) / 2; j++)
        {
            s.insert(dp[j] ^ dp[i - j]);
        }
        for (int j = 0; ; j++)
        {
            if (s.count(j) == 0)
            {
                dp[i] = j;
                break;
            }
        }
        //cout << i << " " << dp[i] << endl;
    }

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        if (n >= 2000)
            cout << "first\n";
        else
            cout << (dp[n] == 0 ? "second\n" : "first\n");
    }
}