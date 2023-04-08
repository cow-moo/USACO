#include <iostream>
using namespace std;
#define MOD 1000000007ull

long long fastExp(long long base, long long exp)
{
    long long res = 1;
    while (exp > 0)
    {
        if (exp & 1)
        {
            res *= base;
            res %= MOD;
        }
        base = base * base;
        base %= MOD;
        exp >>= 1;
    }
    return res;
}

long long fact(long long n)
{
    long long res = 1;
    for (long long i = 2; i <= n; i++)
    {
        res = res * i % MOD;
    }
    return res;
}

long long choose(long long a, long long b)
{
    return fact(a) * fastExp(fact(b), MOD - 2) % MOD * fastExp(fact(a - b), MOD - 2) % MOD;
}

int main()
{
    int n, m;
    cin >> n >> m;
    cout << choose(n + m - 1, n - 1) << endl;
}

