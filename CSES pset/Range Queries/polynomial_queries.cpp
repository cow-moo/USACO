#include <iostream>
using namespace std;
#define MAXN 200005

struct SegmentTree
{
    int n;
    long long tree[4 * MAXN];
    pair<long long, long long> lazy[4 * MAXN];
    //lazy[v] != 0 means tree[v] is updated but not its children
    //start, step

    static const long long id = 0;

    long long op(long long a, long long b)
    {
        return a + b;
    }

    void updateLazy(long long start, long long step, int v, int tl, int tr)
    {
        //(start + (start + (len - 1) * step)) * len / 2
        //(2 * start + (len - 1) * step) * len / 2
        //5 7 9
        //5 2 3
        //0 0
        //1 1
        lazy[v].first += start;
        lazy[v].second += step;
        long long len = tr - tl + 1;
        tree[v] += start * len + step * (len - 1) * len / 2;
    }

    SegmentTree(long long arr[], int n) : n(n)
    {
        build(1, 0, n - 1, arr);
    }

    long long build(int v, int tl, int tr, long long arr[])
    {
        lazy[v] = {0, 0};
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
        if (lazy[v].first != 0 && tl != tr)
            push(v, tl, tr);
        int tm = (tl + tr) / 2;
        return op(query(l, min(r, tm), v * 2, tl, tm), query(max(l, tm + 1), r, v * 2 + 1, tm + 1, tr));
    }

    void push(int v, int tl, int tr)
    {
        //tl = first
        //tl + 1 = first + second
        //tl + i = first + i * second
        //tl + (tm + 1 - tl)
        int tm = (tl + tr) / 2;
        updateLazy(lazy[v].first, lazy[v].second, v * 2, tl, tm);
        updateLazy(lazy[v].first + (tm - tl + 1) * lazy[v].second, lazy[v].second, v * 2 + 1, tm + 1, tr);
        lazy[v] = {0, 0};
    }

    void updateRange(int l, int r)
    {
        updateRange(l, r, l, 1, 0, n - 1);
    }

    void updateRange(int l, int r, long long l0, int v, int tl, int tr)
    {
        if (l > r)
            return;
        if (l == tl && r == tr)
        {
            updateLazy(l - l0 + 1, 1, v, tl, tr);
        }
        else
        {
            if (lazy[v].first != 0 && tl != tr)
                push(v, tl, tr);
            int tm = (tl + tr) / 2;
            updateRange(l, min(r, tm), l0, v * 2, tl, tm); //max(l, tm + 1)
            updateRange(max(l, tm + 1), r, l0, v * 2 + 1, tm + 1, tr);

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
            cin >> a >> b;
            a--; b--;

            tree.updateRange(a, b);
        }
        else if (inp == 2)
        {
            int a, b;
            cin >> a >> b;
            a--; b--;

            cout << tree.query(a, b) << endl;
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                cout << tree.query(i, i) << " ";
            }
            cout << endl;
        }
    }
}

/*
100 100
7 6 4 6 2 9 4 8 10 4 10 3 7 10 2 9 4 1 7 4 5 9 9 7 9 6 5 10 8 4 7 10 5 3 3 1 6 7 6 1 5 7 7 7 7 2 3 5 10 8 4 8 7 5 8 6 8 6 7 9 3 10 6 6 8 1 5 8 5 9 9 5 8 8 4 6 6 3 1 2 1 2 9 2 10 9 9 6 5 7 9 10 5 8 2 7 4 1 4 7
1 62 83
1 72 96
1 20 81
2 42 51

*/