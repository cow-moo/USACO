#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <complex>
#include <math.h>
using namespace std;
using cd = complex<long double>;
#define MOD 998244353
#define MAXN 100005

const double PI = acos(-1);

struct FFTHelper
{
    static const int sz = 1 << 21;
    cd omega[sz];

    FFTHelper()
    {
        omega[sz / 2] = 1;
        cd pow = exp(cd(0, 2 * PI / sz));
        for (int i = sz / 2 + 1; i < sz; i++)
            omega[i] = omega[i - 1] * pow;
        for (int i = sz / 2 - 1; i > 0; i--)
            omega[i] = omega[i << 1];
    }
    
    void fft(cd *arr, int m)
    {
        if (m == 1)
            return;
        fft(arr, m / 2);
        fft(arr + m / 2, m / 2);
        for (int i = 0; i < m / 2; i++)
        {
            cd e = arr[i], o = omega[i + m / 2] * arr[i + m / 2];
            arr[i] = e + o;
            arr[i + m / 2] = e - o;
        }
    }

    void fft(vector<cd> &arr, bool inverse)
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
        fft(arr.data(), m);
        if (inverse)
        {
            reverse(arr.begin() + 1, arr.end());
            cd inv((double)1 / m, 0);
            for (int i = 0; i < m; i++)
                arr[i] = arr[i] * inv;
        }
    }

    vector<cd> multiply(vector<cd> a, vector<cd> b)
    {
        fft(a, false);
        fft(b, false);
        vector<cd> res(a.size());
        for (int i = 0; i < res.size(); i++)
        {
            res[i] = a[i] * b[i];
        }
        fft(res, true);
        return res;
    }
} helper;

map<int, int> cnt;
long long inv[MAXN];

long long exp(long long base, long long pow)
{
    long long res = 1;
    while (pow)
    {
        if (pow & 1)
            res = res * base % MOD;
        base = base * base % MOD;
        pow >>= 1;
    }
    return res;
}

void add(vector<long long> &a, vector<long long> b)
{
    for (int i = 0; i < a.size(); i++)
    {
        a[i] += b[i];
        if (a[i] >= MOD)
            a[i] -= MOD;
    }
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin >> n >> m; 

    int maxim = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        cnt[a]++;
        maxim = max(maxim, cnt[a]);
    }

    for (int i = 0; i <= maxim; i++)
        inv[i] = exp(i, MOD - 2);
     
    vector<cd> dp;
    dp.push_back(cd(1, 0));
    int deg = 0;
 
    for (auto p : cnt)
    {
        int sz = 1 << (sizeof(int) * 8 - __builtin_clz(m + p.first * p.second));
        
        dp.resize(sz);
        for (int i = m + 1; i < sz; i++)
        {
            dp[i] = cd(0, 0);
        }
        vector<cd> bin = vector<cd>(sz);
        
        long long cur = 1;
        for (int i = 0; i <= p.second; i++)
        {
            //if (i * p.first > m)
            //    break;
            if (i % 2 == 0)
                bin[i * p.first].real(cur);
            else
                bin[i * p.first].imag(cur);
            cur = (cur * (p.second - i) % MOD) * inv[i + 1] % MOD;
            deg += p.first;
        }

        vector<cd> dpOdd(sz);
        for (int i = 0; i < sz; i++)
        {
            dpOdd[i] = cd(0, dp[i].imag());
        }
        helper.fft(dp, false), helper.fft(dpOdd, false), helper.fft(bin, false);

        for (int i = 0; i < sz; i++)
        {
            dp[i] = dp[i] * bin[i];
        }
        helper.fft(dp, true);

        for (int i = 0; i < sz; i++)
        {
            dpOdd[i] = dpOdd[i] * bin[i];
        }
        helper.fft(dpOdd, true);

        for (int i = 0; i < sz; i++)
        {
            dp[i] -= 2 * dpOdd[i].real();

            long long re = round(dp[i].real()), im = round(dp[i].imag());
            re %= MOD, im %= MOD;
            //cout << re << " " << im << " " << dp[i].real() << " " << dp[i].imag() << endl;
            dp[i] = cd(re >= 0 ? re : re + MOD, im >= 0 ? im : im + MOD);
        }
        //cout << "a" << endl;

        //helper.ntt(dp[0], false), helper.ntt(dp[1], false), helper.ntt(bin[0], false), helper.ntt(bin[1], false);
        //vector<long long> temp0 = helper.multiply(dp[0], bin[0]);
        //add(temp0, helper.multiply(dp[1], bin[1]));
        //vector<long long> temp1 = helper.multiply(dp[0], bin[1]);
        //add(temp1, helper.multiply(dp[1], bin[0]));

        //temp0.resize(m + 1), temp1.resize(m + 1);
        //dp[0] = move(temp0), dp[1] = move(temp1);
    }
    cout << (dp.size() >= m + 1 ? (long long)round(dp[m].imag()) : 0) << endl;
}