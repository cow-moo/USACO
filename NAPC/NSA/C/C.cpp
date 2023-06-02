#include <iostream>
#include <immintrin.h>
typedef __m256i uint256_t;
#define T __m256i

using namespace std;

T pow(T b, T e, T p)
{
    T res = 1;
    while (e)
    {
        if (e & 1)
            res = res * b % p;
        b = b * b % p;
        e >>= 1;
    }
    return res;
}

T read() {
    __int128 x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}

int main()
{
    T p = read(), g = read(), y = read(), c = read(), q = read();
    //cout << (long long)p << (long long)g << (long long)y << (long long)c << (long long)q << endl;
    // p = read();
    //  >> g >> y >> c >> q;

    cout << (pow(g, q, p) * pow(y, pow(g, c, p), p) % p == c ? "VALID" : "INVALID") << endl;    
}