#include <iostream>
#include <vector>
using namespace std;
#define MAXN 300005

int arr[MAXN];

template <class T>
struct SegTree
{
    const T def = -1; //change here (remove const to support assignment)
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
        if (a == -1)
            return b;
        if (b == -1)
            return a;
        return arr[a] > arr[b] ? a : b; //change here
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

long long ans;

long long recurse(ST &st, int l, int r)
{
    if (r - l <= 1)
    {
        cout << "!" << l << " " << endl;;
        return 0;
    }
    int m = st.query(l, r);
    //cout << m << " ";
    long long lres = recurse(st, l, m), rres = recurse(st, m + 1, r);
    ans += (m - l + 1) * (r - m - 1) * (r - m) / 2 + lres * (r - m);
    cout << l << " " << m << " " << r << ": " << (r - m - 1) * (m - l + 1) + lres + rres << " " << (m - l + 1) * (r - m - 1) * (r - m) / 2 + lres * (r - m) << endl;
    return (r - m - 1) * (m - l + 1) + lres + rres;
}

//prefix, suffix
// pair<long long, long long> recurse(ST &st, int l, int r)
// {
//     if (r - l <= 1)
//         return {0, 0};
//     int m = st.query(l, r);
//     auto lres = recurse(st, l, m), rres = recurse(st, m + 1, r);
//     long long sufRes = (r - m - 1) * (m - l + 1) + lres.second + rres.second;
//     long long preRes = (r - m) * (m - l) + lres.first + rres.first;
//     ans += 
//     return {preRes, sufRes};
// }

long long solve()
{
    int n;
    cin >> n;

    ST st(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        //cin >> st.tree[n + i];
        st.tree[n + i] = i;
    }
    st.init();

    ans = 0;
    recurse(st, 0, n);
    cout << endl;
    return ans;
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