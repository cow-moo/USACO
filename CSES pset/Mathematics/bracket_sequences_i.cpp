#include <iostream>
using namespace std;
#define MOD 1000000007ll

long long fastExp(long long base, long long e)
{
    long long res = 1;
    while (e > 0)
    {
        if (e & 1)
            res = res * base % MOD;
        base = base * base % MOD;
        e >>= 1;
    }
    return res;
}

long long inverse(long long x)
{
    return fastExp(x, MOD - 2);
}

int main()
{
    long long n;
    cin >> n;

    if (n % 2 == 1)
    {
        cout << 0 << endl;
        return 0;
    }

    n /= 2;

    long long ans = 1;
    for (int i = 2; i <= n; i++)
    {
        ans = ans * (n + i) % MOD;
        ans = ans * inverse(i) % MOD;
    }
    cout << ans << endl;
}