//magic iterative version found online
//ntt is same as bit reverse permutation + transform + bit reverse permutation
//intt is same as transform + flip tail
//together ntt + intt becomes (bit reverse + transform) + (bit reverse + transform) + flip tail which is the same as the other fft implementation

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template<long long MOD>
struct NTTHelper
{
    static const int sz = 1 << 20; //adjust so that sz <= max m
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

    void ntt(vector<long long> &arr)
    {
        int m = arr.size();
        for (int l = m / 2; l; l /= 2)
        {
            for (int i = 0; i < m; i += l * 2)
            {
                for (int j = 0; j < l; j++)
                {
                    long long x = arr[i + j], y = arr[i + j + l];
                    arr[i + j + l] = (x - y >= 0 ? x - y : x - y + MOD) * omega[j + l] % MOD;
                    arr[i + j] = x + y < MOD ? x + y : x + y - MOD;
                }
            }
        }
    }

    void intt(vector<long long> &arr)
    { 
        int m = arr.size();
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
        reverse(arr.begin() + 1, arr.end());
        for (int i = 0; i < m; i++)
           arr[i] = arr[i] * (MOD - MOD / m) % MOD;
    }

    vector<long long> multiply(vector<long long> a, vector<long long> b)
    {
        ntt(a);
        ntt(b);
        vector<long long> res(a.size());
        for (int i = 0; i < res.size(); i++)
        {
            res[i] = a[i] * b[i] % MOD;
        }
        intt(res);
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

    string s;
    cin >> s;
    int n = s.length();
    
    vector<long long> a(n), b(n);

    for (int i = 0; i < n; i++)
    {
        a[i] = s[i] == '1';
        b[i] = s[n - i] == '1';
    }

    vector<long long> res = multiply(a, b);

    for (int i = n - 1; i > 0; i--)
    {
        cout << res[i] << " ";
    }
    cout << endl;
}