#include <iostream>
using namespace std;
#define MOD 1000000007ull
#define MAX 1000005

long long fact[MAX];

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

long long modInverse(long long num)
{
    return fastExp(num, MOD - 2);
}

long long choose(long long a, long long b)
{
    //cout << fact[a] << " " << fastExp(fact[b], MOD - 2) << " " << fastExp(fact[a - b], MOD - 2) << endl;
    return fact[a] * fastExp(fact[b], MOD - 2) % MOD * fastExp(fact[a - b], MOD - 2) % MOD;
}

int main()
{
    fact[0] = 1;
    for (int i = 1; i < MAX; i++)
    {
        fact[i] = (fact[i - 1] * i) % MOD;
    }

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        long long a, b;
        cin >> a >> b;

        cout << choose(a, b) << endl;
    }
}
