#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <class T>
struct SegTree
{
    const T def = 0; //change here
    int n;
    vector<T> tree;
    SegTree(int n) : n(n), tree(n * 2, def) {}

    void init()
    {
        for (int i = n - 1; i > 0; i--)
            tree[i] = combine(tree[i << 1], tree[i << 1 | 1]);
    }

    T combine(T a, T b)
    {
        return a ^ b; //change here
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

int main() {
    int n, q;
    cin >> n >> q;

    ST st(n);

    for (int i = 0; i < n; i++)
    {
        cin >> st.tree[n + i];
    }
    st.init();

    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << st.query(a - 1, b) << endl;
    }
}