#include <iostream>
using namespace std;
#define MAXN 100000
#define INF 1000000000

struct SegmentTree
{
    int n;
    int (*op)(int, int);
    int id;
    int tree[4 * MAXN];

    SegmentTree(int arr[], int n, int (*op)(int, int), int id) : n(n), op(op), id(id)
    {
        build(1, 0, n - 1, arr);
    }

    int build(int v, int tl, int tr, int arr[]) {
        if (tl == tr)
        {
            return tree[v] = arr[tl];
        }
        int tm = (tl + tr) / 2;
        return tree[v] = op(build(v * 2, tl, tm, arr), build(v * 2 + 1, tm + 1, tr, arr));
    }

    int query(int l, int r)
    {
        //cout << n - 1 << endl;
        return query(l, r, 1, 0, n - 1);
    }

    int query(int l, int r, int v, int tl, int tr) {
        //cout << v << endl;
        if (l > r)
        {
            return id;
        }
        if (l == tl && r == tr)
        {
            return tree[v];
        }
        int tm = (tl + tr) / 2;
        return op(query(l, min(r, tm), v * 2, tl, tm), query(max(l, tm + 1), r, v * 2 + 1, tm + 1, tr));
    }

    void updateVal(int pos, int val)
    {
        updateVal(pos, val, 1, 0, n - 1);
    }

    void updateVal(int pos, int val, int v, int tl, int tr)
    {
        if (tl == tr)
        {
            tree[v] = val;
            return;
        }
        int tm = (tl + tr) / 2;
        if (pos >= tl && pos <= tm)
        {
            updateVal(pos, val, v * 2, tl, tm);
        }
        else
        {
            updateVal(pos, val, v * 2 + 1, tm + 1, tr);
        }
        tree[v] = op(tree[v * 2], tree[v * 2 + 1]);
    }
};

int add(int a, int b)
{
    return a + b;
}

int min(int a, int b)
{
    return a < b ? a : b;
}

int arr[MAXN];

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    SegmentTree sumTree(arr, n, &add, 0);
    cout << sumTree.query(0, 2) << endl;
    sumTree.updateVal(1, 5);
    cout << sumTree.query(0, 2) << endl;

    SegmentTree minTree(arr, n, &min, INF);
    cout << minTree.query(0, 2) << endl;
    minTree.updateVal(2, 1);
    cout << minTree.query(0, 2) << endl;
}

/*
struct SegmentTree
{
    int n;
    long long (*op)(long long, long long);
    long long id;
    long long tree[4 * MAXN];
    long long lazy[4 * MAXN];
    //lazy[v] != 0 means tree[v] is updated but not its children

    SegmentTree(long long arr[], long long n, long long (*op)(long long, long long), long long id) : n(n), op(op), id(id)
    {
        build(1, 0, n - 1, arr);
    }

    long long build(int v, int tl, int tr, long long arr[]) {
        if (tl == tr)
        {
            return tree[v] = arr[tl];
        }
        int tm = (tl + tr) / 2;
        return tree[v] = op(build(v * 2, tl, tm, arr), build(v * 2 + 1, tm + 1, tr, arr));
    }

    long long query(int l, int r)
    {
        //cout << n - 1 << endl;
        return query(l, r, 1, 0, n - 1);
    }

    long long query(int l, int r, int v, int tl, int tr) {
        //cout << v << endl;
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

    void updateVal(int pos, long long val)
    {
        updateVal(pos, val, 1, 0, n - 1);
    }

    void updateVal(int pos, long long val, int v, int tl, int tr)
    {
        if (tl == tr)
        {
            tree[v] = val;
            return;
        }
        int tm = (tl + tr) / 2;
        if (pos >= tl && pos <= tm)
        {
            updateVal(pos, val, v * 2, tl, tm);
        }
        else
        {
            updateVal(pos, val, v * 2 + 1, tm + 1, tr);
        }
        tree[v] = op(tree[v * 2], tree[v * 2 + 1]);
    }

    void push(int v, int tl, int tr) {
        tree[v * 2] += lazy[v];
        lazy[v * 2] += lazy[v];

        tree[v * 2 + 1] += lazy[v];
        lazy[v * 2 + 1] += lazy[v];

        lazy[v] = 0;
    }

    void updateRange(int l, int r, long long addend)
    {
        updateRange(l, r, addend, 1, 0, n - 1);
    }

    void updateRange(int l, int r, long long addend, int v, int tl, int tr) {
        if (l > r)
            return;
        if (l == tl && r == tr) {
            lazy[v] += addend;
            tree[v] += addend;
        }
        else {
            if (lazy[v] != 0 && tl != tr)
                push(v, tl, tr);
            int tm = (tl + tr) / 2;
            updateRange(l, min(r, tm), addend, v * 2, tl, tm);
            updateRange(max(l, tm + 1), r, addend, v * 2 + 1, tm + 1, tr);

            tree[v] = op(tree[v * 2], tree[v * 2 + 1]);
        }
    }
};

*/