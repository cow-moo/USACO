#include <iostream>
using namespace std;
#define MOD 1000000007
#define MAXN 1000

long long fastexp(long long base, long long exp)
{
    long long res = 1;
    while (exp > 0)
    {
        if (exp & 1)
        {
            res *= res * base;
            res %= MOD;
        }
        res = res * res;
        res %= MOD;
        exp >>= 1;
    }
    return res;
}

long long fact[MAXN], inv[MAXN], choose[MAXN][MAXN];
int n = 100;

void computeChoose()
{
//    fact[0] = 1;
//    inv[0] = 1;
//    for (int i = 0; i < n; i++)
//    {
//        fact[i] = (fact[i - 1] * i) % MOD;
//        inv[i] = fastexp(fact[i], MOD - 2);
//    }

    choose[0][0] = 1;
    for (int i = 1; i < n; i++)
    {
        choose[i][0] = 1;
        choose[i][i] = 1;
        for (int j = 1; j < i; j++)
        {
            choose[i][j] = choose[i - 1][j - 1] + choose[i - 1][j];
            if (choose[i][j] >= MOD)
                choose[i][j] -= MOD;
        }
    }
}

int main()
{
    //for MOD is prime
    //inv = fastexp(x, MOD - 2);
    //a / x == a * inv mod(MOD)

    //choose[i][j] = ((fact[i] * inv[j]) % MOD * inv[i - j]) % MOD;

    computeChoose();
    cout << choose[96][6] << endl;
}