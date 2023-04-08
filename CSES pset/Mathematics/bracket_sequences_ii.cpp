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
    string str;
    cin >> n >> str;

    if (n % 2 == 1)
    {
        cout << 0 << endl;
        return 0;
    }

    long long k = 0;
    for (int i = 0; i < str.length(); i++)
    {
        k += str[i] == '(' ? 1 : -1;
        if (k < 0)
        {
            cout << 0 << endl;
            return 0;
        }
    }

    n -= str.length();
    n = (n + k) / 2;
    k = n - k;

    if (k < 0)
    {
        cout << 0 << endl;
        return 0;
    }
    //cout << n << " " << k << endl;
    
    long long ans = (n - k + 1) * inverse(n + 1) % MOD;
    for (int i = 1; i <= k; i++)
    {
        ans = ans * (n + i) % MOD;
        ans = ans * inverse(i) % MOD;
    }
    cout << ans << endl;
}