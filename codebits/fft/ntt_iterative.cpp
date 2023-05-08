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