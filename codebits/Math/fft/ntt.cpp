#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MOD 998244353

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
} helper;

vector<long long> multiply(vector<long long> &a, vector<long long> &b)
{
    int sz = 1 << (sizeof(int) * 8 - __builtin_clz(a.size() + b.size() - 2));
    a.resize(sz), b.resize(sz);
    vector<long long> res = helper.multiply(a, b);
    res.resize(a.size() + b.size() - 1);
    return res;
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin >> n >> m; 
    
    vector<long long> a(n), b(m);

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

/*
alternative iterative version
void ntt(long long *arr, int m)
{
    for (int l = 1; l < m; l *= 2)
    {
        for (int i = 0; i < m; i += l * 2)
        {
            for (int j = 0; j < l; j++)
            {
                long long x = arr[i + j], y = omega[j + l] * arr[i + j + l] % MOD;
                arr[i + j] = x + y < MOD ? x + y : x + y - MOD;
                arr[i + j + l] = x - y >= 0 ? x - y : x - y + MOD;
            }
        }
    }
}
*/