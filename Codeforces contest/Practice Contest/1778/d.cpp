#include <iostream>
using namespace std;
#define MOD 998244353
#define MAXN 1000005

long long inverse(long long x)
{
    x = x % MOD;
    if (x < 0)
        x += MOD;
    long long exp = MOD - 2;
    long long res = 1;
    while (exp)
    {
        if (exp & 1)
            res = res * x % MOD;
        x = x * x % MOD;
        exp >>= 1;
    }
    return res;
}

long long a[MAXN], b[MAXN];

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        long long n;
        string s1, s2;
        cin >> n >> s1 >> s2;
        long long diff = 0;
        for (int i = 0; i < n; i++)
            diff += s1[i] != s2[i];

        long long inv = inverse(n);
        a[1] = 1, b[1] = (n - 1) * inv % MOD;
        //E[i] = a[i] + b[i]E[i+1]
        //E[i-1] = a[i-1]+b[i-1]E[i]
        //E[i] = 1 + i/n E[i-1] + (n-i)/n E[i+1]
        
        for (int i = 2; i < n; i++)
        {
            a[i] = (a[i - 1] * i + n) % MOD * inverse(n - b[i - 1] * i) % MOD;
            b[i] = (n - i) * inverse(n - b[i - 1] * i) % MOD;
        }

        long long e = (a[n - 1] + 1) * inverse(1 - b[n - 1]) % MOD;
        for (int i = n - 1; i >= diff; i--)
        {
            e = (a[i] + b[i] * e) % MOD;
        }
        cout << e << endl;
    }
}