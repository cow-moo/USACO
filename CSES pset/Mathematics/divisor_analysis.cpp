#include <iostream>
using namespace std;
#define MOD 1000000007

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

long long fastExp2(long long base, long long exp)
{
    long long res = 1;
    while (exp > 0)
    {
        if (exp & 1)
            res = res * base % (MOD - 1);
        base = base * base % (MOD - 1);
        exp >>= 1;
    }
    return res;
}

int main()
{
    int n;
    cin >> n;

    long long num = 1;
    long long cnt = 1;
    long long sum = 1;
    long long sqrt = 1;
    long long halfCntEven = 1;
    long long halfCnt = 0;
    for (int i = 0; i < n; i++)
    {
        int x, k;
        cin >> x >> k;

        if (sqrt != -1 && k % 2 == 0)
        {
            sqrt = sqrt * fastExp(x, k / 2) % MOD;
            halfCnt = (halfCnt * (k + 1) + k / 2) % (MOD - 1);
            halfCntEven = (halfCntEven) * (k + 1) % (MOD - 1);
        }
        else if (sqrt != -1)
        {
            sqrt = -1;
            halfCntEven = (halfCntEven) * ((k + 1) / 2) % (MOD - 1);
        }
        else
        {
            halfCntEven = (halfCntEven) * (k + 1) % (MOD - 1);
        }
        num = num * fastExp(x, k) % MOD;
        cnt = cnt * (k + 1) % MOD;

        sum = sum * ((fastExp(x, k + 1) - 1) * (fastExp(x - 1, MOD - 2)) % MOD) % MOD;
    }
    if (sqrt == -1)
        halfCnt = halfCntEven;

    cout << cnt << " " << sum << " " << fastExp(num, halfCnt) * (sqrt == -1 ? 1 : sqrt) % MOD << endl;
}

