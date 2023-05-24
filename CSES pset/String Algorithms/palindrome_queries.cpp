#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define P 31
#define MAXN 200005

template<long long MOD>
struct FenwickTree
{
    vector<long long> bit;

    FenwickTree(int n) : bit(n + 1) {}

    long long sum(int i)
    {
        //i++;
        long long sum = 0;
        while (i > 0)
        {
            sum = sum + bit[i] >= MOD ? sum + bit[i] - MOD : sum + bit[i];
            i -= i & -i;
        }
        return sum;
    }

    void add(int i, long long delta)
    {
        if (delta < 0)
            delta += MOD;
        i++;
        while (i < bit.size())
        {
            bit[i] = bit[i] + delta >= MOD ? bit[i] + delta - MOD : bit[i] + delta;
            i += i & -i;
        }
    }
};

template<long long MOD>
struct Hash
{
    FenwickTree<MOD> ft;
    vector<long long> power;
    string str;
    
    Hash(string str) : ft(str.length() + 1), power(str.length()), str(str)
    {
        int n = str.length();
        power[0] = 1;
        for (int i = 1; i < n; i++)
        {
            power[i] = power[i - 1] * P % MOD;
        }

        for (int i = 0; i < n; i++)
        {
            ft.add(i, power[i] * (str[i] - 'a') % MOD);
            //pre[i + 1] = (pre[i] + power[i] * (str[i] - 'a')) % MOD;
        }
    }

    long long exp(long long base, long long exp)
    {
        long long res = 1;
        while (exp)
        {
            if (exp & 1)
                res = res * base % MOD;
            base = base * base % MOD;
            exp >>= 1;
        }
        return res;
    }

    //1 indexed, inclusive
    long long substr(int a, int b)
    {
        long long res = ft.sum(b) - ft.sum(a - 1);
        if (res < 0)
            res += MOD;
        return res * exp(power[a - 1], MOD - 2) % MOD;
        //return (pre[b] - pre[a - 1]) * exp(power[a - 1], MOD - 2) % MOD;
    }

    //1 indexed
    void modify(int i, char c)
    {
        i--;
        ft.add(i, power[i] * (c - str[i]) % MOD);
        str[i] = c;
    }
};

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    string str;
    cin >> n >> m >> str;

    Hash<1000000007> hash1(str);
    Hash<1000000009> hash2(str);
    reverse(str.begin(), str.end());
    Hash<1000000007> revHash1(str);
    Hash<1000000009> revHash2(str);

    //cout << str << endl;
    for (int i = 0; i < m; i++)
    {
        int q;
        cin >> q;

        if (q == 1)
        {
            int k;
            char x;
            cin >> k >> x;
            hash1.modify(k, x);
            hash2.modify(k, x);
            revHash1.modify(n + 1 - k, x);
            revHash2.modify(n + 1 - k, x);
        }
        else
        {
            int a, b;
            cin >> a >> b;
            cout << ((hash1.substr(a, b) == revHash1.substr(n + 1 - b, n + 1 - a) && hash2.substr(a, b) == revHash2.substr(n + 1 - b, n + 1 - a)) ? "YES" : "NO") << endl;
        }
    }
}