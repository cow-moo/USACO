#include <iostream>
#include <set>
using namespace std;
#define MOD 998244353
#define ll long long

struct mint
{
    int v;
    mint() : v(0) {}
    int val() { return v; }
    mint(ll v) : v(v % MOD) { v += (v < 0) * MOD; }
};
mint& operator+=(mint& a, mint b) { if ((a.v += b.v) >= MOD) a.v -= MOD; return a; }
mint& operator-=(mint& a, mint b) { if ((a.v -= b.v) < 0) a.v += MOD; return a; }
mint operator*(mint a, mint b) { return mint((ll) a.v * b.v); }
mint operator+(mint a, mint b) { return a += b; }
mint operator-(mint a, mint b) { return a -= b; }
mint& operator*=(mint& a, mint b) { return a = a * b; }
mint pow(mint a, ll p) { return p == 0 ? 1 : pow(a * a, p / 2) * (p & 1 ? a : 1); }
mint inv(mint a) { return pow(a, MOD - 2); }
mint operator/(mint a, mint b) { return a * inv(b); }

long long test(long long n)
{
    set<long long> s;

    for (long long i = 0; i <= n / 2; i++)
    {
        s.insert(i ^ (n - i));
    }
    long long ans = 0;
    for (auto x : s)
    {
        ans += x;
        if (ans >= MOD)
            ans -= MOD;
    }
    return ans;
}

long long solve2(long long n)
{
    mint cnt1 = 0, cnt2 = 1, sum1 = 0, sum2 = 0;
    int zeros = 0;
    mint orig(n);
    for (int i = 0; n > 0; i++, n >>= 1)
    {
        if (n & 1)
        {
            mint newcnt2 = cnt1 + cnt2;
            mint newsum2 = sum1 + sum2;
            mint newcnt1 = cnt2 * zeros + cnt1 * (zeros + 1);
            mint newsum1 = cnt2 * mint((1ll << (i + 1)) - (1ll << (i + 1 - zeros))) + cnt1 * mint((1ll << (i + 1)) - (1ll << (i - zeros))) + sum2 * zeros + sum1 * (zeros + 1);
            cnt1 = newcnt1, cnt2 = newcnt2, sum1 = newsum1, sum2 = newsum2;
            zeros = 0;
            //cout << cnt1.v << " " << sum1.v << " " << cnt2.v << " " << sum2.v << endl;
        }
        else
        {
            zeros++;
        }
    }
    //cout << test(orig) << endl;
    orig = (orig * (cnt1 + cnt2)) - (sum1 + sum2);
    return orig.v;
}

long long solve()
{
    long long n;
    int m;
    cin >> n >> m;

    if (m == 1)
    {
        return n % MOD;
    }
    else if (m == 2)
    {
        return solve2(n);
    }
    else
    {
        return ((n + 1) / 2 % MOD) * ((n + 2) / 2 % MOD) % MOD;
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        cout << solve() << endl;
    }
}