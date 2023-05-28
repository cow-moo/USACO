#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAXN 100005

struct Tree
{
    int x, y, h;
} trees[MAXN];

//[l, r) for range queries, already coordinate compressed on x
template <class T>
struct SegTree2D
{
    const T def = {0};
    int n;
    vector<vector<T>> tree; //segment tree for each segment
    vector<vector<pair<int, int>>> vals; //the vals in each segment (y coord, val)
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
            //for (int j = 0; j < m; j++)
            //    tree[i][j + m] = {vals[i][j].second};
            //for (int j = m - 1; j > 0; j--)
            //    tree[i][j] = combine(tree[i][j << 1], tree[i][j << 1 | 1]);

            for (int j = m * 2 - 1; j > 0; j--)
                tree[i][j] = j >= m ? T({vals[i][j - m].second}) : combine(tree[i][j << 1], tree[i][j << 1 | 1]);
        }
    }

    T combine(const T& a, const T& b)
    {
        if (a[0] == -1 || b[0] == -1)
            return {-1};
        if (a[0] == 0)
            return b;
        if (b[0] == 0)
            return a;
        T res = {};
        int p1 = 0, p2 = 0; 
        while (p1 < a.size() || p2 < b.size())
        {
            if (p1 < a.size() && (p2 == b.size() || a[p1] < b[p2]))
            {
                res.push_back(a[p1++]);
            }
            else
            {
                res.push_back(b[p2++]);
            }
            if (res.size() >= 3)
            {
                if (res.end()[-3] + res.end()[-2] > res.end()[-1])
                    return {-1};
            }
        }
        return res;
    }

    T query(int l, int r, int y1, int y2)
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

    T query(int index, int y1, int y2)
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
using ST = SegTree2D<vector<int>>;

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
        
        int l = lower_bound(trees, trees + n, x1, [&](Tree &t, int x) { return t.x < x; }) - trees;
        int r = upper_bound(trees, trees + n, x2, [&](int x, Tree &t) { return x < t.x; }) - trees;
        cout << (st.query(l, r, y1, y2)[0] == -1) << endl;
    }
}