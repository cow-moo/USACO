#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MOD 998244353ll

struct NTTHelper
{
    static const int sz = 1 << 20;
    long long omega[sz];

    NTTHelper()
    {
        omega[sz / 2] = 1;
        long long exp = 1, base = 3, pow = MOD / sz;
        while (pow)
        {
            if (pow & 1)
                exp = exp * base % MOD;
            base = base * base % MOD;
            pow >>= 1;
        }
        for (int i = sz / 2 + 1; i < sz; i++)
            omega[i] = omega[i - 1] * exp % MOD;
        for (int i = sz / 2 - 1; i > 0; i--)
            omega[i] = omega[i << 1];
    }
    
    void ntt(long long *arr, int m)
    {
        if (m == 1)
            return;
        ntt(arr, m / 2);
        ntt(arr + m / 2, m / 2);
        for (int i = 0; i < m / 2; i++)
        {
            long long e = arr[i], o = omega[i + m / 2] * arr[i + m / 2] % MOD;
            arr[i] = e + o < MOD ? e + o : e + o - MOD;
            arr[i + m / 2] = e - o >= 0 ? e - o : e - o + MOD;
        }
    }

    void ntt(vector<long long> &arr, bool inverse)
    {
        int m = arr.size();
        for (int i = 1, j = 0; i < m; i++)
        {
            int bit = m >> 1;
            for (; j & bit; bit >>= 1)
                j ^= bit;
            j ^= bit;

            if (i < j)
                swap(arr[i], arr[j]);
        }
        ntt(arr.data(), m);
        if (inverse)
        {
            reverse(arr.begin() + 1, arr.end());
            for (int i = 0; i < m; i++)
                arr[i] = arr[i] * (MOD - MOD / m) % MOD;
        }
    }

    vector<long long> multiply(vector<long long> a, vector<long long> b)
    {
        ntt(a, false);
        ntt(b, false);
        vector<long long> res(a.size());
        for (int i = 0; i < res.size(); i++)
        {
            res[i] = a[i] * b[i] % MOD;
        }
        ntt(res, true);
        return res;
    }
} helper; //2^23 * 7 * 17 + 1

vector<long long> multiply(vector<long long> &a, vector<long long> &b)
{
    int sz = 1 << (sizeof(int) * 8 - __builtin_clz(a.size() + b.size() - 2));
    a.resize(sz), b.resize(sz);
    vector<long long> res = helper.multiply(a, b);
    res.resize(a.size() + b.size() - 1);
    return res;
}

long long pow(long long b, long long e)
{
    long long res = 1;
    while (e > 0)
    {
        if (e & 1)
            res = res * b % MOD;
        b = b * b % MOD;
        e >>= 1;
    }
    return res;
}

int main()
{
    long long n, a1, x, y, m, k;
    cin >> n >> a1 >> x >> y >> m >> k;

    vector<long long> a, binom;

    for (int i = 0; i < n; i++)
    {
        a.push_back(a1);
        a1 = (a1 * x + y) % m;
    }

    long long cur = 1;
    for (int i = 1; i <= n; i++)
    {
        if (i < k)
            binom.push_back(0);
        else
        {
            binom.push_back(cur);
            cur = cur * (i + 1) % MOD;
            cur = cur * pow(i - k + 1, MOD - 2) % MOD;
        }
    }

    vector<long long> res = multiply(a, binom);
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans ^= (i + 1) * res[i];
    }
    cout << ans << endl;
}