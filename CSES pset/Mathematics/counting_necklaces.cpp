#include <iostream>
#include <vector>
using namespace std;
#define MOD 1000000007ll

long long fastExp(long long base, long long exp)
{
    long long res = 1;
    while (exp > 0)
    {
        if (exp & 1)
            res = res * base % MOD;
        base = base * base % MOD;
        exp >>= 1;
    }
    return res;
}

int main()
{
    int n, m;
    cin >> n >> m;

    //min cycle, num
    vector<pair<int, long long>> cnt;
    cnt.push_back({1, m});
    long long ans = m;
    for (int i = 2; i <= n && n != 1; i++)
    {
        int l = 0, r = cnt.size();
        while (n % i == 0)
        {
            n /= i;
            for (int j = l; j < r; j++)
            {
                pair<int, long long> cur = {i * cnt[j].first, 0};
                cur.second = fastExp(m, cur.first);
                for (auto &p : cnt)
                {
                    if (cur.first % p.first == 0)
                    {
                        cur.second -= p.second;
                        if (cur.second < 0)
                            cur.second += MOD;
                    }
                }
                cnt.push_back(cur);
                ans += cur.second * fastExp(cur.first, MOD - 2) % MOD;
                if (ans >= MOD)
                    ans -= MOD;
            }
            l = r; r = cnt.size();
        }
        if (i * i > n)
        {
            i = n - 1;
        }
    }
    cout << ans << endl;
}
