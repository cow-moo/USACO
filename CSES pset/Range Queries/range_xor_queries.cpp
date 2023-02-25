#include <iostream>
using namespace std;
#define MAXN 200050
#define INF 1000000000

int arr[MAXN];

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

int xorOp(int a, int b)
{
    return a ^ b;
}

int main() {
    int n, q;
    cin >> n >> q;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    SegmentTree xorTree(arr, n, &xorOp, 0);

    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << xorTree.query(a - 1, b - 1) << endl;
    }
}