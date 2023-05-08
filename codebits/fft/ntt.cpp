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
NTTHelper<998244353ll> helper1;
NTTHelper<7340033ll> helper2;

vector<long long> multiply(vector<long long> &a, vector<long long> &b)
{
    vector<long long> res1 = helper1.multiply(a, b);
    vector<long long> res2 = helper2.multiply(a, b);

    __int128_t p1 = 705577077098755, p2 = 6621569415984895, mod = 7327146493083649;

    vector<long long> res(a.size());
    for (int i = 0; i < res.size(); i++)
    {
        res[i] = (res1[i] * p1 + res2[i] * p2) % mod;
    }
    return res;
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin >> n >> m; 
    
    int sz = 1 << (sizeof(int) * 8 - __builtin_clz(n + m - 1));

    vector<long long> a(sz), b(sz);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = m - 1; i >= 0; i--)
    {
        cin >> b[i];
    }

    vector<long long> res = multiply(a, b);

    for (int i = 0; i < n + m - 1; i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
}