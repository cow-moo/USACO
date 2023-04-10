#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <class T>
struct SegTree
{
    const T def = 0;
    int n;
    vector<T> bits;
    SegTree(int n) : n(n), bits((n + 1) * 2, def) {}

    void init()
    {
        for (int i = n - 1; i > 0; i--)
            bits[i] = combine(bits[i << 1], bits[i << 1 | 1]);
    }

    T combine(T a, T b)
    {
        return a + b;
    }

    void update(int k, T x)
    {
        k += n, bits[k] = x;
        for (k >>= 1; k; k >>= 1)
            bits[k] = combine(bits[k << 1], bits[k << 1 | 1]);
    }

    T query(int l, int r)
    {
        T resl = def, resr = def;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1)
                resl = combine(resl, bits[l++]);
            if (r & 1)
                resr = combine(bits[--r], resr);
        }
        return combine(resl, resr);
    }
};
using ST = SegTree<long long>;

int main()
{
    int n, q;
    cin >> n >> q;

    ST st(n);

    for (int i = 0; i < n; i++)
    {
        cin >> st.bits[n + i];
    }
    st.init();

    for (int i = 0; i < q; i++)
    {
        int inp, a, b;
        cin >> inp >> a >> b;
        if (inp == 1)
        {
            st.update(a - 1, b);
        }
        else
        {
            cout << st.query(a - 1, b) << endl;
        }
    }
}
