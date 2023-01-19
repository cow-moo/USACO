#include <iostream>
using namespace std;
#define MOD 1000000007ull
#define MAXN 105

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

long long fact[MAXN], inv[MAXN], chooseArr[MAXN][MAXN];

void computeChoose()
{
    chooseArr[0][0] = 1;
    for (int i = 1; i < MAXN; i++)
    {
        chooseArr[i][0] = 1;
        chooseArr[i][i] = 1;
        for (int j = 1; j < i; j++)
        {
            chooseArr[i][j] = chooseArr[i - 1][j - 1] + chooseArr[i - 1][j];
            if (chooseArr[i][j] >= MOD)
                chooseArr[i][j] -= MOD;
        }
    }
}

long long choose(int n, int r)
{
    if (n < 0 || r < 0 || n < r)
        return 0;
    return chooseArr[n][r];
}

long long calc1(int n, int i, int j, int x, int y)
{
    if (x == n)
    {
        return choose(n - y - 1, j - i - 1) * choose(y - 1, n - j) % MOD;
    }
    if (y == n)
    {
        return choose(n - x - 1, j - i - 1) * choose(x - 1, i - 1) % MOD;
    }
}

long long calc2(int n, int i, int j, int x, int y)
{
    long long res = 1;
    int cntGreater = n - max(x, y);
    int cntMiddle = j - i - 1;
    int cntBetween = max(x, y) - min(x, y) - 1;
    //cout << "greater " << cntGreater << endl;
    //cout << "middle " << cntMiddle << endl;
    //cout << "between " << cntBetween << endl;
//    if (cntGreater > cntMiddle)
//    {
//        return 0;
//    }

    res *= fastExp(2, cntGreater - 1);
    res %= MOD;
    res *= choose(cntBetween, cntMiddle - cntGreater);
    res %= MOD;

    if (x < y)
    {
        res *= choose(x - 1, i - 1);
    }
    else
    {
        res *= choose(y - 1, n - j);
    }
    //cout << "res2 " << res << endl;
    return res % MOD;
}

long long calc3(int n, int i, int j, int x, int y)
{
    long long res = 1;
    if (x < y)
    {
        res *= choose(x - 1, i - 1);
    }
    else
    {
        res *= choose(y - 1, n - j);
    }
    res %= MOD;
    res *= choose(max(x, y) - min(x, y) - 1, j - i - 1);
    res %= MOD;
    res *= fastExp(2, n - max(x, y) - 1);
    //cout << "res3 " << res << endl;
    return res % MOD;
}

int main()
{
    computeChoose();

    int t;
    cin >> t;

    for (int z = 0; z < t; z++)
    {
        int n, i, j, x, y;
        cin >> n >> i >> j >> x >> y;
        if (x == n || y == n)
            cout << calc1(n, i, j, x, y) << endl;
        else
            cout << (calc2(n, i, j, x, y) + calc3(n, i, j, x, y)) % MOD << endl;
    }
}

