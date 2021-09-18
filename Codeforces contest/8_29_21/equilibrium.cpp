#include <iostream>
using namespace std;
#define MAXN 100005
#define INF 1000000000000000

//min, max
pair<long long, long long> tree[4 * MAXN];
long long arr[MAXN];

void build(long long v, long long tl, long long tr) {
    if (tl == tr) {
        tree[v] = {arr[tl], arr[tl]};
    }
    else {
        long long tm = (tl + tr) / 2;
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm + 1, tr);
        tree[v] = {min(tree[v * 2].first, tree[v * 2 + 1].first), max(tree[v * 2].second, tree[v * 2 + 1].second)};
    }
}

//long long sum(long long v, long long tl, long long tr, long long l, long long r) {
//    if (l > r) {
//        return 0;
//    }
//    if (l == tl && r == tr) {
//        return tree[v];
//    }
//    long long tm = (tl + tr) / 2;
//    return sum(v * 2, tl, tm, l, min(r, tm)) + sum(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
//}

pair<long long, long long> getMinMax(long long v, long long tl, long long tr, long long l, long long r)
{
    if (l > r) {
        return {INF, -INF};
    }
    if (l == tl && r == tr) {
        return tree[v];
    }
    long long tm = (tl + tr) / 2;
    pair<long long, long long> a = getMinMax(v * 2, tl, tm, l, min(r, tm));
    pair<long long, long long> b = getMinMax(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    return {min(a.first, b.first), max(a.second, b.second)};
}

//void update(long long v, long long tl, long long tr, long long pos, long long newVal) {
//    if (tl == tr) {
//        tree[v] = newVal;
//    }
//    else {
//        long long tm = (tl + tr) / 2;
//        if (pos <= tm)
//            update(v * 2, tl, tm, pos, newVal);
//        else
//            update(v * 2 + 1, tm + 1, tr, pos, newVal);
//        tree[v] = tree[v * 2] + tree[v * 2 + 1];
//    }
//}

int main()
{
    long long n, q;
    cin >> n >> q;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        long long temp;
        cin >> temp;
        arr[i] -= temp;
        if (i > 0)
            arr[i] += arr[i - 1];
    }

    //for (int i = 0; i < n; i++)
    //    cout << arr[i] << endl;

    build(1, 0, n - 1);

    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;

        pair<long long, long long> t = getMinMax(1, 0, n - 1, a, b);
        //cout << t.first << " " << t.second << endl;
        if (a != 0)
        {
            t.first -= arr[a - 1];
            t.second -= arr[a - 1];
        }

        if (t.second > 0 || (a == 0 && arr[b] != 0) || (a != 0 && arr[b] != arr[a - 1]))
            cout << -1 << endl;
        else
            cout << -t.first << endl;
    }
}
