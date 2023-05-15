#include <iostream>
#include <vector>
#include <algorithm>
#include <complex>
#include <math.h>
using namespace std;
using cd = complex<double>;

const double PI = atan(1) * 4;

struct FFTHelper
{
    static const int sz = 1 << 20;
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

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin >> n >> m; 
    
    int sz = 1 << (sizeof(int) * 8 - __builtin_clz(n + m - 1));

    vector<cd> a(sz), b(sz);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = m - 1; i >= 0; i--)
    {
        cin >> b[i];
    }

    vector<cd> res = helper.multiply(a, b);

    for (int i = 0; i < n + m - 1; i++)
    {
        cout << (long long)(res[i].real() + 0.5) << " ";
    }
    cout << endl;
}