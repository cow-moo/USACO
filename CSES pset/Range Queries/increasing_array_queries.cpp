#include <iostream>
#include <queue>
using namespace std;
#define MAXN 200005
#define INF 1000000010

long long arr[MAXN];
long long suffix[MAXN];
priority_queue<pair<pair<int, int>, int>> queries;
vector<int> stack;
long long ans[MAXN];

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

    SegmentTree(long long n, long long (*op)(long long, long long), long long id) : n(n), op(op), id(id)
    {
        for (int i = 0; i < 4 * n; i++)
        {
            tree[i] = lazy[i] = 0;
        }
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
        int tm = (tl + tr) / 2;
        tree[v * 2] += (tm - tl + 1) * lazy[v];
        lazy[v * 2] += lazy[v];

        tree[v * 2 + 1] += (tr - tm) * lazy[v];
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
            tree[v] += addend * (tr - tl + 1);
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

long long add(long long a, long long b)
{
    return a + b;
}

int main()
{
    int n, q;
    cin >> n >> q;

    SegmentTree tree(n, &add, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        queries.push({{a - 1, b - 1}, i});
    }

    arr[n] = INF;
    stack.push_back(n);
    for (int i = n - 1; i >= 0; i--)
    {
        suffix[i] = suffix[i + 1] + arr[i];
        tree.updateRange(i, stack.back() - 1, arr[i]);
        while (arr[i] >= arr[stack.back()])
        {
            int temp = stack.back();
            stack.pop_back();
            tree.updateRange(temp, stack.back() - 1, arr[i] - arr[temp]);
        }
        stack.push_back(i);

        while (!queries.empty() && queries.top().first.first == i)
        {
            auto [a, b] = queries.top().first;
            ans[queries.top().second] = tree.query(a, b) - (suffix[i] - suffix[b + 1]);
            queries.pop();
        }
    }

    for (int i = 0; i < q; i++)
    {
        cout << ans[i] << endl;
    }
}