#include <iostream>
using namespace std;
#define MOD 998244353
#define MAXN 2000000

long long fact[MAXN];

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

long long choose(int a, int b)
{
    if (b == 0)
        return 1;
    return (fact[a] * modInverse(fact[b]) % MOD) * modInverse(fact[a - b]) % MOD;
}

int main()
{
    fact[0] = 1;
    for (int i = 1; i <= MAXN; i++)
    {
        fact[i] = fact[i - 1] * i % MOD;
    }

    long long r, g, b, k;
    cin >> r >> g >> b >> k;

    cout << (choose(r + b, r) * choose(r, k) % MOD) * choose(b + g, g - k) % MOD << endl;
}