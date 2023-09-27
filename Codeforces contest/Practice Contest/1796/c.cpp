#include <iostream>
using namespace std;
#define MOD 998244353

void solve(long long l, long long r, long long cnt)
{
    long long ans = 0;
    for (int i = l; ; i++)
    {
        if (i << cnt <= r)
        {
            ans++;
            if (ans >= MOD)
                ans -= MOD;
        }
        else
            break;
        if ((i << (cnt - 1)) * 3 <= r)
        {
            ans += cnt;
            if (ans >= MOD)
                ans -= MOD;
        }
    }
    cout << "bash: " << cnt + 1 << " " << ans << endl;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        long long l, r;
        cin >> l >> r;

        long long cnt = -1;
        for (int i = l; i <= r; i <<= 1)
        {
            cnt++;
        }

        long long a = r >> cnt, b = (r >> (cnt - 1)) / 3;
        long long ans = cnt * max(b - l + 1, 0ll) + a - l + 1 % MOD;
        //cout << "bounds: " << (r >> cnt) << " " << ((r >> (cnt - 1)) / 3) << endl;
        //solve(l, r, cnt);
        cout << cnt + 1 << " " << ans << endl;
    }
}

//1 6
//1 2 4
//1 2 6
//1 3 6

//2 * 3 < 2 * 2 * 2
//2 * 2 * 3 < 2 * 2 * 2 * 2

//1 2 4 8
//15 30 60 120
//18 36 72 144
//2^0, 2^1, ... 2^19

//5 75
//5 10 20 40
//9 18 36 72
//6 18 36 72
//5 6 +6
//7 8 9 +3