#include <iostream>
using namespace std;
#define MOD 1000000007

long long fastExp(long long base, long long exp, long long mod)
{
    long long res = 1;
    while (exp > 0)
    {
        if (exp & 1)
            res = res * base % mod;
        base = base * base % mod;
        exp >>= 1;
    }
    return res;
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        long long a, b, c;
        cin >> a >> b >> c;
        cout << fastExp(a, fastExp(b, c, MOD - 1), MOD) << endl;
    }
}

