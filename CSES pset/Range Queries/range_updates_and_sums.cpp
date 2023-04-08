#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//[l, r) for range queries
const long long def = 0;
struct LazySegTree {
    int n, h;
    vector<long long> bits;
    vector<long long> lazy;
    LazySegTree(int n) : n(n), bits((n + 1) * 2, def), lazy(n, 0), h(sizeof(int) * 8 - __builtin_clz(n)) {}

    void init()
    {
        for (int i = n - 1; i > 0; i--)
            bits[i] = combine(bits[i << 1], bits[i << 1 | 1]);
    }

    //get value of current interval given values of child intervals, lazy value, and length of interval
    long long combine(long long a, long long b, long long val = 0, int len = 0)
    {
        if (val < 0)
            return -val * len;
        else
            return a + b + val * len;
    }

    //apply increment, update bits and lazy
    void apply(int p, long long val, int len)
    {
        if (p < n)
        {
            if (val < 0)
                lazy[p] = val;
            else
                lazy[p] += lazy[p] < 0 ? -val : val;
            bits[p] = combine(bits[p << 1], bits[p << 1 | 1], lazy[p], len);
        }
        else
            bits[p] = combine(bits[p], def, val, len);
    }

    void build(int p)
    {
        int len = 1;
        while (p > 1)
            p >>= 1, len <<= 1, bits[p] = combine(bits[p << 1], bits[p << 1 | 1], lazy[p], len);
    }

    void push(int p)
    {
        for (int s = h, len = 1 << (h - 1); s > 0; s--, len >>= 1)
        {
            int i = p >> s;
            if (lazy[i] != 0)
            {
                apply(i << 1, lazy[i], len);
                apply(i << 1 | 1, lazy[i], len);
                lazy[i] = 0;
            }
        }
    }

    void increment(int l, int r, long long val)
    {
        l += n, r += n;
        push(l), push(r - 1);
        int l0 = l, r0 = r, len = 1;
        for (; l < r; l >>= 1, r >>= 1, len <<= 1)
        {
            if (l & 1)
                apply(l++, val, len);
            if (r & 1)
                apply(--r, val, len);
        }
        build(l0), build(r0 - 1);
    }

    void set(int l, int r, long long val)
    {
        l += n, r += n;
        push(l), push(r - 1);
        int l0 = l, r0 = r, len = 1;
        for (; l < r; l >>= 1, r >>= 1, len <<= 1)
        {
            if (l & 1)
                apply(l++, -val, len);
            if (r & 1)
                apply(--r, -val, len);
        }
        build(l0), build(r0 - 1);
    }

    long long query(int l, int r)
    {
        l += n, r += n;
        push(l), push(r - 1);
        
        long long res = def;
        for (; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1)
                res = combine(res, bits[l++]);
            if (r & 1)
                res = combine(res, bits[--r]);
        }
        return res;
    }
};

pair<int, int> debug(LazySegTree lst, int i)
{
    if (i >= lst.n)
        return {i - lst.n, i - lst.n + 1};
    pair<int, int> l = debug(lst, i * 2);
    pair<int, int> r = debug(lst, i * 2 + 1);
    if (l.second != r.first)
        return {-1, -1};
    return {l.first, r.second};
}

void printDebug(LazySegTree lst)
{
    for (int i = 1; i < 2 * lst.n; i++)
    {
        auto res = debug(lst, i);
        cout << i << ": [" << res.first << ", " << res.second << ") " << lst.bits[i];
        if (i < lst.n)
            cout << " " << lst.lazy[i];
        cout << endl;
    }
}

int main()
{
    int n, q;
    cin >> n >> q;

    LazySegTree lst(n);

    for (int i = 0; i < n; i++)
    {
        cin >> lst.bits[n + i];
    }
    lst.init();

    for (int i = 0; i < q; i++)
    {
        int inp, a, b;
        cin >> inp >> a >> b;
        a--, b--;

        if (inp == 4)
        {
            printDebug(lst);
            continue;
        }

        if (inp == 3)
        {
            cout << lst.query(a, b + 1) << endl;
        }
        else
        {
            long long x;
            cin >> x;

            if (inp == 1)
                lst.increment(a, b + 1, x);
            else
                lst.set(a, b + 1, x);
        }
    }
}