#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using LST = LazySegTree<long long>;

//[l, r) for range queries
template <class T>
struct LazySegTree
{
    static const T def = 0;

    int n, h;
    vector<T> bits;
    vector<T> lazy;
    LazySegTree(int n) : n(n), bits((n + 1) * 2, def), lazy(n, 0), h(sizeof(int) * 8 - __builtin_clz(n)) {}

    void init()
    {
        for (int i = n - 1; i > 0; i--)
            bits[i] = combine(bits[i << 1], bits[i << 1 | 1]);
    }

    //get value of current interval given values of child intervals, lazy value, and length of interval
    T combine(T a, T b, T val = 0, int len = 0)
    {
        if (val < 0)
            return -val * len;
        else
            return a + b + val * len;
    }

    //apply increment, update bits and lazy
    void apply(int p, T val, int len)
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

    void increment(int l, int r, T val)
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

    T query(int l, int r)
    {
        l += n, r += n;
        push(l), push(r - 1);
        T res = def;
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


pair<int, int> debug(LST lst, int i)
{
    if (i >= lst.n)
        return {i - lst.n, i - lst.n + 1};
    pair<int, int> l = debug(lst, i * 2);
    pair<int, int> r = debug(lst, i * 2 + 1);
    if (l.second != r.first)
        return {-1, -1};
    return {l.first, r.second};
}

void printDebug(LST lst)
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
    int n = 10;
    LST lst(n);
    for (int i = 0; i < n; i++)
    {
        lst.bits[i + n] = i;
    }
    lst.init();
    //printDebug(lst);
    
    printDebug(lst);
    cout << lst.query(3, 9) << endl;
    lst.increment(0, 5, 3);
    cout << lst.query(3, 9) << endl;
}