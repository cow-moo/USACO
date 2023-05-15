#include <iostream>
#include <complex>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
using cd = complex<double>;
const double PI = acos(-1);

void fft(vector<cd> & a, bool invert) {
    int n = a.size();

    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            cd w(1);
            for (int j = 0; j < len / 2; j++) {
                cd u = a[i+j], v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }

    if (invert) {
        for (cd & x : a)
            x /= n;
    }
}

vector<cd> multiply(vector<cd> &a, vector<cd> &b)
{
    fft(a, false), fft(b, false);
    vector<cd> res(a.size());
    for (int i = 0; i < a.size(); i++)
    {
        res[i] = a[i] * b[i];
    }
    fft(res, true);
    return res;
}

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

    vector<cd> res = multiply(a, b);

    for (int i = 0; i < n + m - 1; i++)
    {
        cout << (long long)round(res[i].real()) << " ";
    }
    cout << endl;
}