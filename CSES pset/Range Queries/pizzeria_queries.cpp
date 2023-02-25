// 8  6  4  5  7  5
// 8  7  6  8 11 10
//          5  8  7
//13 10  7  7  8  5
//11  8  5  5
#include <iostream>
using namespace std;
#define MAXN 200050
#define INF 2000000000

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

int min(int a, int b)
{
    return a < b ? a : b;
}

int arr[MAXN];
int prefix[MAXN];
int suffix[MAXN];

int main() {
    int n, q;
    cin >> n >> q;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        prefix[i] = arr[i] + n - 1 - i;
        suffix[i] = arr[i] + i;
    }

    SegmentTree prefixTree(prefix, n, &min, INF);
    SegmentTree suffixTree(suffix, n, &min, INF);

    for (int i = 0; i < q; i++)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int k, x;
            cin >> k >> x;
            k--;
            prefixTree.updateVal(k, x + n - 1 - k);
            suffixTree.updateVal(k, x + k);
        }
        else
        {
            int k;
            cin >> k;
            k--;
            cout << min(prefixTree.query(0, k) - (n - 1 - k), suffixTree.query(k + 1, n - 1) - k) << endl;
        }
    }
}
