#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//[l, r) for range queries
template <class T, class L>
struct LazySegTree
{
    const T def = 0;
    const L ldef = {0, 0};
    int n, h;
    vector<T> tree;
    vector<L> lazy;
    LazySegTree(int n) : n(n), tree(n * 2, def), lazy(n, ldef), h(sizeof(int) * 8 - __builtin_clz(n)) {}

    void init()
    {
        for (int i = n - 1; i > 0; i--)
            tree[i] = combine(tree[i << 1], tree[i << 1 | 1]);
    }

    //get value of current interval given values of child intervals, lazy value, and length of interval
    T combine(T a, T b, L val = {0, 0}, int len = 0)
    {
        return a + b + val.first * len + val.second * len * (len - 1) / 2;
    }

    //apply increment, update tree and lazy
    void apply(int p, L val, int len)
    {
        if (p < n)
        {
            lazy[p].first += val.first;
            lazy[p].second += val.second;
        }
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
                lazy[i].first += lazy[i].second * len;
                apply(i << 1 | 1, lazy[i], len);
                lazy[i] = ldef;
            }
        }
    }

    void increment(int l, int r)
    {
        l += n, r += n;
        push(l), push(r - 1);
        int l0 = l, r0 = r, len = 1;
        L lval = {1, 1}, rval = {r - l + 1, 1};
        for (; l < r; l >>= 1, r >>= 1, len <<= 1)
        {
            if (l & 1)
                apply(l++, lval, len), lval.first += len;
            if (r & 1)
                rval.first -= len, apply(--r, rval, len);
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
using LST = LazySegTree<long long, pair<long long, long long>>;

int main()
{
    int n, q;
    cin >> n >> q;

    LST st(n);

    for (int i = 0; i < n; i++)
        cin >> st.tree[n + i];
    st.init();

    for (int i = 0; i < q; i++)
    {
        int inp;
        cin >> inp;

        if (inp == 1)
        {
            int a, b;
            cin >> a >> b;
            a--; b--;

            st.increment(a, b + 1);
        }
        else if (inp == 2)
        {
            int a, b;
            cin >> a >> b;
            a--; b--;

            cout << st.query(a, b + 1) << endl;
        }
    }
}