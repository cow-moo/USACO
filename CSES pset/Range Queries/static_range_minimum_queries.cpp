#include <iostream>
using namespace std;
#define MAXN 200050
#define INF 1000000000

int tree[4 * MAXN];
int arr[MAXN];
int n;

int build(int v = 1, int tl = 0, int tr = n - 1)
{
    if (tl == tr)
    {
        return tree[v] = arr[tl];
    }
    int tm = (tl + tr) / 2;
    return tree[v] = min(build(v * 2, tl, tm), build(v * 2 + 1, tm + 1, tr));
}

int query(int l, int r, int v = 1, int tl = 0, int tr = n - 1)
{
    if (l > r)
        return INF;
    if (tl == l && tr == r)
    {
        return tree[v];
    }
    int tm = (tl + tr) / 2;
    return min(query(l, min(r, tm), v * 2, tl, tm), query(max(l, tm + 1), r, v * 2 + 1, tm + 1, tr));
}

int main()
{
    int q;
    cin >> n >> q;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    build();

    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << query(a - 1, b - 1) << endl;
    }
}