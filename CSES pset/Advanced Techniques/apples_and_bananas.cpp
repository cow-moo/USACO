#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template<long long MOD>
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
};
NTTHelper<998244353ll> helper1; //2^23 * 7 * 17 + 1
NTTHelper<469762049ll> helper2; //2^26 * 7 + 1
//167772161 = 2^25 * 5 + 1
//7340033 = 2^20 * 7 + 1
//3 is primitive root for all

vector<long long> multiply(vector<long long> &a, vector<long long> &b)
{
    int sz = 1 << (sizeof(int) * 8 - __builtin_clz(a.size() + b.size() - 2));
    a.resize(sz), b.resize(sz);
    vector<long long> res1 = helper1.multiply(a, b);
    vector<long long> res2 = helper2.multiply(a, b);
    res1.resize(a.size() + b.size() - 1), res2.resize(a.size() + b.size() - 1);

    __int128_t p1 = 260520730147305702, p2 = 208416582520653596, mod = 468937312667959297;
    vector<long long> res(res1.size());
    for (int i = 0; i < res.size(); i++)
    {
        res[i] = (res1[i] * p1 + res2[i] * p2) % mod;
    }
    return res;
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    int k, n, m;
    cin >> k >> n >> m; 
    
    vector<long long> a(k + 1), b(k + 1);

    for (int i = 0; i < n; i++)
    {
        int ai;
        cin >> ai;
        a[ai]++;
    }
    for (int i = m - 1; i >= 0; i--)
    {
        int bi;
        cin >> bi;
        b[bi]++;
    }

    vector<long long> res = multiply(a, b);

    for (int i = 2; i <= 2 * k; i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
}