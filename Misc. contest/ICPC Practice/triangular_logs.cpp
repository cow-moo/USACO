#include <iostream>
#include <vector>
#include <math.h>
#include <numeric>
#include <array>
#include <algorithm>
#include <cassert>
using namespace std;
#define MAXN 100005
#define dbg(x) "(" << #x << ": " << (x) << ") "

template<typename Ostream, typename Cont>
enable_if_t<is_same_v<Ostream, ostream>, Ostream&>
operator<<(Ostream& os, const Cont& v) {
    os << "[";
    for(auto &x:v){os<<x<<", ";}
    return os<<"]";
}

struct Tree
{
    int x, y, h;

    bool operator<(const Tree &other) const
    {
        return tie(x, y) < tie(other.x, other.y);
    }
} trees[MAXN];

int order[MAXN], inv[MAXN], n;
bool ans[MAXN];

bool comp(int a, int b)
{
    return trees[a].y < trees[b].y;
}

struct Node {
    Node() = default;
    int n=0;
    bool done = false;
    array<int, 10> vals = {};
};

template <class T>
struct SegTree {
    T def = {};
    int n;
    vector<T> tree;
    SegTree() = default;
    SegTree(int n): n(n), tree(n * 2, def) {}
    
    T combine(const T& a, const T& b)
    {
        //cout << dbg(a) dbg(b) << endl;
        if (a.done || b.done)
            return {0,true};
        if (a.n==0)
            return b;
        if (b.n==0)
            return a;
        T res = {};
        int p1 = 0, p2 = 0; 
        while (p1 < a.n || p2 < b.n)
        {
            if (p1 < a.n && (p2 == b.n || a.vals[p1] < b.vals[p2]))
            {
                res.vals[res.n++] = a.vals[p1++];
            }
            else
            {
                res.vals[res.n++] = b.vals[p2++];
            }
            if (res.n >= 3)
            {
                if (res.vals[res.n-3] + res.vals[res.n-2] > res.vals[res.n-1])
                    return {0, true};
            }
        }
        assert(res.n < 10);
        //cout << dbg(res) << endl;
        return res;
    }

    void init()
    {
        for (int i = n - 1; i > 0; i--)
            tree[i] = combine(tree[i << 1], tree [i << 1 | 1]);
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
            if (l & 1) resl = combine(resl, tree[l++]);
            if (r & 1) resr = combine(tree[--r], resr);
        }
        return combine(resl, resr);
    }
};
using ST = SegTree<Node>;
ST st;

struct mo_query {
    using func = function<void(int)>;
    int n;
    vector<pair<pair<int, int>, pair<int, int>>> lr;
    mo_query(int n) : n(n) {}
    void add(int x1, int y1, int x2, int y2) {
        lr.push_back({{x1, y1}, {x2, y2}});
    }

    void build(const func &add_left, const func &add_right, const func &erase_left, const func &erase_right, const function<void(int, int, int)> &out) {
        int q = (int) lr.size();
        //int bs = n / min<int>(n, (int)sqrt(q));
        const int bs = 300;
        vector<int> ord(q);
        iota(begin(ord), end(ord), 0);
        sort(begin(ord), end(ord), [&](int a, int b) {
            int ablock = lr[a].first.first / bs, bblock = lr[b].first.first / bs;
            if (ablock != bblock) return ablock < bblock;
            return (ablock & 1) ? lr[a].second.first > lr[b].second.first : lr[a].second.first < lr[b].second.first;
        });
        int l = 0, r = 0;
        for (auto idx : ord) {
            //cout << dbg(l) dbg(r) dbg(n) << endl;
            while (l > 0 && trees[l].x >= lr[idx].first.first) add_left(--l);
            while (r < n && trees[r].x <= lr[idx].second.first) add_right(r++);
            while (l < n && trees[l].x < lr[idx].first.first) erase_left(l++);
            while (r > 0 && trees[r].x > lr[idx].second.first) erase_right(--r);
            //cout << dbg(l) dbg(r) dbg(lr[idx].first.first) dbg(lr[idx].second.first) << endl;
            out(idx, lr[idx].first.second, lr[idx].second.second);
        }
    }

    void build(const func &add, const func &erase, const function<void(int, int, int)> &out) {
        build(add, add, erase, erase, out);
    }
};

void add(int index)
{
    Node node = {1, false};
    node.vals[0] = trees[index].h;
    st.update(inv[index], node);
}

void erase(int index)
{
    st.update(inv[index], {0, false});
}



void out(int index, int y1, int y2)
{
    // cout << dbg(index) dbg(y1) dbg(y2) << endl;
    // for (int i = n; i < 2 * n; i++)
    // {
    //     cout << dbg(st.tree[i]) << endl;
    // }
    
    //cout << dbg(y1);
    y1 = lower_bound(order, order + n, y1, [&](int i, int j) {
        return trees[i].y < j;
    }) - order;
    //cout << dbg(y1) << endl;
    //cout << dbg(y2);
    y2 = upper_bound(order, order + n, y2, [&](int i, int j) {
        return i < trees[j].y;
    }) - order;
    //cout << dbg(y2) << endl;
    //cout << dbg(y1) dbg(y2) << endl;
    ans[index] = st.query(y1, y2).done;
}

int main()
{
    // st = ST(7);
    // //            0  1  2  3  4  5  6
    // int temp[] = {5, 2, 6, 0, 8, 9, 3};
    // for (int i = 0; i < 7; i++)
    // {
    //     st.update(i, {temp[i]});
    // }
    // st.update(1, {0});
    // while (true)
    // {
    //     int a, b;
    //     cin >> a >> b;
    //     cout << dbg(st.query(a, b)) << endl;
    // }


    //return 0;
    int q;
    cin >> n >> q;
    st = ST(n);

    for (int i = 0; i < n; i++)
    {
        cin >> trees[i].x >> trees[i].y >> trees[i].h;
    }

    sort(trees, trees + n);
    iota(order, order + n, 0);
    sort(order, order + n, comp);
    for (int i = 0; i < n; i++)
    {
        inv[order[i]] = i;
    }

    // for (int i = 0; i < n; i++)
    // {
    //     cout << dbg(trees[i].x) dbg(trees[i].y) dbg(trees[i].h) << endl;
    //     cout << dbg(inv[i]) << endl;
    // }

    mo_query mq(n);
    for (int i = 0; i < q; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        mq.add(x1, y1, x2, y2);
    }
    mq.build(add, erase, out);

    for (int i = 0; i < q; i++)
    {
        cout << ans[i] << endl;
    }
}

/*
9 2
1 3 3
2 3 1
3 3 4
1 2 1
2 2 5
3 2 9
1 1 2
2 1 6
3 1 5
1 1 5 1
1 1 3 1
*/