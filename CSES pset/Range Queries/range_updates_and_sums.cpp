#include <iostream>
using namespace std;
#define MAXN 200005

struct SegmentTree
{
    int n;
    long long tree[4 * MAXN];
    long long lazy[4 * MAXN];
    //lazy[v] != 0 means tree[v] is updated but not its children
    //negative means set
    //queries must be non-negative
    //if negative queries, then just have 2 arrays for lazyAdd and lazySet (or array of bool flags)

    static const long long id = 0;

    long long op(long long a, long long b)
    {
        return a + b;
    }

    void updateLazy(long long addend, int v, int tl, int tr)
    {
        if (addend >= 0)
        {
            if (lazy[v] >= 0)
            {
                lazy[v] += addend;
                tree[v] += (tr - tl + 1) * addend;
            }
            else
            {
                lazy[v] -= addend;
                tree[v] = (tr - tl + 1) * -lazy[v];
            }
        }
        else
        {
            lazy[v] = addend;
            tree[v] = (tr - tl + 1) * -lazy[v];
        }
    }

    SegmentTree(long long arr[], int n) : n(n)
    {
        build(1, 0, n - 1, arr);
    }

    long long build(int v, int tl, int tr, long long arr[])
    {
        if (tl == tr)
        {
            return tree[v] = arr[tl];
        }
        int tm = (tl + tr) / 2;
        return tree[v] = op(build(v * 2, tl, tm, arr), build(v * 2 + 1, tm + 1, tr, arr));
    }

    long long query(int l, int r)
    {
        return query(l, r, 1, 0, n - 1);
    }

    long long query(int l, int r, int v, int tl, int tr)
    {
        if (l > r)
        {
            return id;
        }
        if (l == tl && r == tr)
        {
            return tree[v];
        }
        if (lazy[v] != 0 && tl != tr)
            push(v, tl, tr);
        int tm = (tl + tr) / 2;
        return op(query(l, min(r, tm), v * 2, tl, tm), query(max(l, tm + 1), r, v * 2 + 1, tm + 1, tr));
    }

    void push(int v, int tl, int tr)
    {
        int tm = (tl + tr) / 2;
        updateLazy(lazy[v], v * 2, tl, tm);
        updateLazy(lazy[v], v * 2 + 1, tm + 1, tr);
        lazy[v] = 0;
    }

    void updateRange(int l, int r, long long addend)
    {
        updateRange(l, r, addend, 1, 0, n - 1);
    }

    void updateRange(int l, int r, long long addend, int v, int tl, int tr)
    {
        if (l > r)
            return;
        if (l == tl && r == tr)
        {
            updateLazy(addend, v, tl, tr);
        }
        else
        {
            if (lazy[v] != 0 && tl != tr)
                push(v, tl, tr);
            int tm = (tl + tr) / 2;
            updateRange(l, min(r, tm), addend, v * 2, tl, tm);
            updateRange(max(l, tm + 1), r, addend, v * 2 + 1, tm + 1, tr);

            tree[v] = op(tree[v * 2], tree[v * 2 + 1]);
        }
    }
};

long long arr[MAXN];

int main()
{
    int n, q;
    cin >> n >> q;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    SegmentTree tree(arr, n);

    for (int i = 0; i < q; i++)
    {
        int inp;
        cin >> inp;

        if (inp == 1)
        {
            int a, b;
            long long x;
            cin >> a >> b >> x;
            a--; b--;

            tree.updateRange(a, b, x);
        }
        else if (inp == 2)
        {
            int a, b;
            long long x;
            cin >> a >> b >> x;
            a--; b--;

            tree.updateRange(a, b, -x);
        }
        else
        {
            int a, b;
            cin >> a >> b;
            a--; b--;

            cout << tree.query(a, b) << endl;
        }
    }
}
/*
66
11
18
28
138
164
717
194
170
220
371
667
115
245
723
60
201
736
7
76
56
253
144
180
67
204
375
262
107
8
32
368
266
28
*/