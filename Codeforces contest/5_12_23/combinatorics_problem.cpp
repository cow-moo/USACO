#include <iostream>
using namespace std;
#define MOD 998244353
#define MAXN 10000005

long long arr[MAXN], res[6][MAXN];

int main()
{
    long long n, a1, x, y, m, k;
    cin >> n >> a1 >> x >> y >> m >> k;

    long long cur = a1;
    for (int i = 1; i <= n; i++)
    {
        arr[i] = cur;
        cur = (cur * x + y) % m;
        //cout << arr[i] << " ";
    }
    //cout << endl;

    res[0][1] = arr[1];
    for (int i = 2; i <= n; i++)
    {
        res[0][i] = res[0][i - 1] + arr[i];
    }

    for (int j = 1; j <= k; j++)
    {
        res[j][1] = j == 1 ? arr[1] : 0;
        for (int i = 2; i <= n; i++)
        {
            res[j][i] = (res[j][i - 1] + res[j - 1][i - 1] + (j == 1 ? arr[i] : 0)) % MOD;
        }
    }

    // for (int j = 0; j <= k; j++)
    // {
    //     for (int i = 1; i <= n; i++)
    //     {
    //         cout << res[j][i] << " ";
    //     }
    //     cout << endl;
    // }

    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans ^= res[k][i] * i;
    }
    cout << ans << endl;
}