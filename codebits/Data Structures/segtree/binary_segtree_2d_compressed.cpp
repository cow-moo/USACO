#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
#define MAXN 100005

//[l, r) for range queries, already coordinate compressed on x
template <class T>
struct SegTree2D
{
    const T def = 0;
    int n;
    vector<vector<T>> tree; //segment tree for each segment
    vector<vector<pair<long long, T>>> vals; //the vals in each segment (y coord, val)
    SegTree2D() = default;
    SegTree2D(int n) : n(n), tree(n * 2), vals(n * 2) {}

    void init()
    {
        for (int i = n * 2 - 1; i > 0; i--)
        {
            if (i < n)
            {
                vals[i].resize(vals[i << 1].size() + vals[i << 1 | 1].size());
                merge(vals[i << 1].begin(), vals[i << 1].end(), vals[i << 1 | 1].begin(), vals[i << 1 | 1].end(), vals[i].begin());
            }
            int m = vals[i].size();
            tree[i].resize(m * 2, def);
            for (int j = m * 2 - 1; j > 0; j--)
                tree[i][j] = j >= m ? vals[i][j - m].second : combine(tree[i][j << 1], tree[i][j << 1 | 1]);
        }
    }

    T combine(const T& a, const T& b)
    {
        return a + b;
    }

    T query(int l, int r, long long y1, long long y2)
    {
        T resl = def, resr = def;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1)
                resl = combine(resl, query(l++, y1, y2));
            if (r & 1)
                resr = combine(query(--r, y1, y2), resr);
        }
        return combine(resl, resr);
    }

    T query(int index, long long y1, long long y2)
    {
        int l = lower_bound(vals[index].begin(), vals[index].end(), y1, [](auto v, int y) { return v.first < y; }) - vals[index].begin();
        int r = upper_bound(vals[index].begin(), vals[index].end(), y2, [](int y, auto v) { return y < v.first; }) - vals[index].begin();
        int m = vals[index].size();
        T resl = def, resr = def;
        for (l += m, r += m; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1)
                resl = combine(resl, tree[index][l++]);
            if (r & 1)
                resr = combine(tree[index][--r], resr);
        }
        return combine(resl, resr);
    }
};
using ST = SegTree2D<long long>;

struct Tree
{
    int x, y, h;
} trees[MAXN];

int main()
{
    int n, q;
    cin >> n >> q;

    for (int i = 0; i < n; i++)
    {
        cin >> trees[i].x >> trees[i].y >> trees[i].h;
    }

    sort(trees, trees + n, [&](Tree &a, Tree &b) { return a.x < b.x; });

    ST st(n);
    for (int i = 0; i < n; i++)
    {
        st.vals[n + i].push_back({trees[i].y, trees[i].h});
    }
    st.init();

    for (int i = 0; i < q; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        
        int l = lower_bound(trees, trees + n, x1, [](Tree &t, int x) { return t.x < x; }) - trees;
        int r = upper_bound(trees, trees + n, x2, [](int x, Tree &t) { return x < t.x; }) - trees;
        cout << st.query(l, r, y1, y2) << endl;
    }
}

//3 1 4
//1 5 9
//2 6 5