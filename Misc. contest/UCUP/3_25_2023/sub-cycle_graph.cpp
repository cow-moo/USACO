#include <iostream>
using namespace std;
#define MOD 1000000007
#define MAXN 100005

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

long long modInverse(long long num)
{
    return fastExp(num, MOD - 2);
}

long long fact[MAXN], inv[MAXN];

long long choose(int a, int b)
{
    if (b == 0)
        return 1;
    return (fact[a] * inv[b] % MOD) * inv[a - b] % MOD;
}

long long solve()
{
    long long n, m;
    cin >> n >> m;
    if (m > n)
        return 0;
    if (m == n)
        return fact[n - 1] * modInverse(2) % MOD;
    if (m == 0)
        return 1;

    long long ans = 0;
    for (int i = 1; i <= min(m, n - m); i++)
    {
        long long cur = fact[n] * inv[n - m - i] % MOD;
        //cout << "a" << cur << endl;
        cur = cur * modInverse(fastExp(2, i)) % MOD;
        cur = cur * inv[i] % MOD;
        //cout << "b" << cur << endl;
        cur = cur * choose(m - 1, i - 1) % MOD;
        //cout << "c" << m - 1 << " " << i - 1 << endl;
        ans += cur;
        if (ans >= MOD)
            ans -= MOD;
        //cout << "cur: " << cur << endl;
    }
    return ans;
}

int main()
{
    fact[0] = 1;
    inv[0] = 1;
    for (int i = 1; i < MAXN; i++)
    {
        fact[i] = i * fact[i - 1] % MOD;
        inv[i] = modInverse(fact[i]);
    }

    int t;
    cin >> t;
    while (t--)
    {
        cout << solve() << endl;
    }
}
