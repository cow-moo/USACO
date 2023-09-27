#include <iostream>
#include <map>
using namespace std;
#define MAXN 5005
#define MOD 998244353

map<int, int> nums;
long long dp[MAXN];

int main()
{
    int n, k;
    cin >> n >> k;
    
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        nums[a]++;
    }

    int cnt = 0;
    dp[0] = 1;
    for (auto p : nums)
    {
        for (int i = 0; i < p.second; i++)
        {
            for (int j = k; j > 0; j--)
            {
                dp[j] = ((dp[j] * (j + i + 1) % MOD) + (dp[j - 1] * (cnt + 1 - j - i) % MOD)) % MOD;
            }
            dp[0] = dp[0] * (i + 1) % MOD;
            cnt++;
        }
    }
    cout << dp[k] << endl;
}