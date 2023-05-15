#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//[l, r) for range queries
template <class T>
struct SegTree
{
    const T def = 0; //change here (remove const to support assignment)
    int n;
    vector<T> tree;
    SegTree() = default;
    SegTree(int n) : n(n), tree(n * 2, def) {}

    void init()
    {
        for (int i = n - 1; i > 0; i--)
            tree[i] = combine(tree[i << 1], tree[i << 1 | 1]);
    }

    T combine(T a, T b)
    {
        return a + b; //change here
    }

    void update(int k, T x)
    {
        k += n, tree[k] = x;
        for (k >>= 1; k; k >>= 1)
            tree[k] = combine(tree[k << 1], tree[k << 1 | 1]);
    }

    T query(int l, int r)
    {
        T resl = def, resr = def;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1)
                resl = combine(resl, tree[l++]);
            if (r & 1)
                resr = combine(tree[--r], resr);
        }
        return combine(resl, resr);
    }
};
using ST = SegTree<long long>;

pair<int, int> interval(ST st, int i)
{
    if (i >= st.n)
        return {i - st.n, i - st.n + 1};
    pair<int, int> l = interval(st, i * 2);
    pair<int, int> r = interval(st, i * 2 + 1);
    if (l.second != r.first)
        return {-1, -1};
    return {l.first, r.second};
}

void debug(ST st)
{
    for (int i = 1; i < 2 * st.n; i++)
    {
        auto res = interval(st, i);
        cout << i << ": [" << res.first << ", " << res.second << ") " << st.tree[i] << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    
    ST st(n);

    for (int i = 0; i < n; i++)
    {
        cin >> st.tree[n + i];
    }
    st.init();
    debug(st);

    while (true)
    {
        int inp;
        cin >> inp;
        
        if (inp == 1)
        {
            int k, x;
            cin >> k >> x;
            st.update(k, x);
        }
        else if (inp == 2)
        {
            int a, b;
            cin >> a >> b;
            cout << st.query(a, b) << endl;
        }
        else if (inp == 3)
        {

        }
        else
        {
            break;
        }
    }
}

/* non-commutative version of query
    T query(int l, int r)
    {
        T res = def;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1) 
                res = combine(res, tree[l++]);
            if (r & 1) 
                res = combine(res, tree[--r]);
        }
        return res;
    }
*/