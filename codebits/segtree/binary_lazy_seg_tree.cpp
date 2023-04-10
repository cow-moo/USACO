#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//[l, r) for range queries
template <class T, class L>
struct LazySegTree
{
    const T def = 0; //change here
    const L ldef = 0; //change here
    int n, h;
    vector<T> tree;
    vector<L> lazy;
    LazySegTree(int n) : n(n), tree(n * 2, def), lazy(n, ldef), h(sizeof(int) * 8 - __builtin_clz(n)) {}

    void init()
    {
        for (int i = n - 1; i > 0; i--)
            tree[i] = combine(tree[i << 1], tree[i << 1 | 1]);
    }

    T combine(T a, T b, L val = 0, int len = 0)
    {
        return a + b + val * len; //change here, calculate value given child intervals, lazy val, interval length
    }

    void apply(int p, L val, int len)
    {
        if (p < n)
            lazy[p] += val; //change here, propagate val to lazy[p]
        tree[p] = combine(tree[p], def, val, len);
    }

    void build(int p)
    {
        int len = 1;
        while (p > 1)
            p >>= 1, len <<= 1, tree[p] = combine(tree[p << 1], tree[p << 1 | 1], lazy[p], len);
    }

    void push(int p)
    {
        for (int s = h, len = 1 << (h - 1); s > 0; s--, len >>= 1)
        {
            int i = p >> s;
            if (lazy[i] != ldef)
            {
                apply(i << 1, lazy[i], len);
                apply(i << 1 | 1, lazy[i], len);
                lazy[i] = ldef;
            }
        }
    }

    void increment(int l, int r, L val)
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
        T resl = def, resr = def;
        for (; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1)
                resl = combine(resl, tree[l++]);
            if (r & 1)
                resr = combine(tree[--r], resr);
        }
        return combine(resl, resr);
    }
};
using LST = LazySegTree<long long, long long>;

pair<int, int> interval(LST lst, int i)
{
    if (i >= lst.n)
        return {i - lst.n, i - lst.n + 1};
    pair<int, int> l = interval(lst, i * 2);
    pair<int, int> r = interval(lst, i * 2 + 1);
    if (l.second != r.first)
        return {-1, -1};
    return {l.first, r.second};
}

void debug(LST lst)
{
    for (int i = 1; i < 2 * lst.n; i++)
    {
        auto res = interval(lst, i);
        cout << i << ": [" << res.first << ", " << res.second << ") " << lst.tree[i];
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
        lst.tree[i + n] = i;
    }
    lst.init();
    //printDebug(lst);
    
    debug(lst);
    cout << lst.query(3, 9) << endl;
    lst.increment(0, 5, 3);
    cout << lst.query(3, 9) << endl;
}

/* non-commutative version of query
T query(int l, int r)
{
    l += n, r += n;
    push(l), push(r - 1);
    T res = def;
    for (; l < r; l >>= 1, r >>= 1)
    {
        if (l & 1)
            res = combine(res, tree[l++]);
        if (r & 1)
            res = combine(res, tree[--r]);
    }
    return res;
}
*/