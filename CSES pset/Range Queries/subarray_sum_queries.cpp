//... -9 ... 10 ...
//... 10 ... -9 ...

//... -5 ... 10 ... -8 ... 8 ...  -9 ... 3

#include <iostream>
using namespace std;
#define MAXN 200050

int n;
long long arr[MAXN];
long long sum[MAXN * 4];
long long prefix[MAXN * 4];
long long suffix[MAXN * 4];
long long best[MAXN * 4];

//sum = sum[l] + sum[r]
//prefix = max(prefix[l], sum[l] + prefix[r])
//suffix = max(suffix[r], sum[r] + suffix[l])
//best = max(suffix[l] + prefix[r], best[l], best[r])

void build(int v, int tl, int tr)
{
    if (tl == tr)
    {
        sum[v] = arr[tl];
        prefix[v] = max(arr[tl], 0ll);
        suffix[v] = max(arr[tl], 0ll);
        best[v] = max(arr[tl], 0ll);
        return;
    }
    int tm = (tl + tr) / 2;
    build(v * 2, tl, tm);
    build(v * 2 + 1, tm + 1, tr);
    sum[v] = sum[v * 2] + sum[v * 2 + 1];
    prefix[v] = max(prefix[v * 2], sum[v * 2] + prefix[v * 2 + 1]);
    suffix[v] = max(suffix[v * 2 + 1], sum[v * 2 + 1] + suffix[v * 2]);
    best[v] = max(suffix[v * 2] + prefix[v * 2 + 1], max(best[v * 2], best[v * 2 + 1]));
}

void updateVal(int pos, long long val, int v, int tl, int tr)
{
    if (tl == tr)
    {
        sum[v] = val;
        prefix[v] = max(val, 0ll);
        suffix[v] = max(val, 0ll);
        best[v] = max(val, 0ll);
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
    sum[v] = sum[v * 2] + sum[v * 2 + 1];
    prefix[v] = max(prefix[v * 2], sum[v * 2] + prefix[v * 2 + 1]);
    suffix[v] = max(suffix[v * 2 + 1], sum[v * 2 + 1] + suffix[v * 2]);
    best[v] = max(suffix[v * 2] + prefix[v * 2 + 1], max(best[v * 2], best[v * 2 + 1]));
}

int main() {
    int m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    build(1, 0, n - 1);

    for (int i = 0; i < m; i++)
    {
        long long k, x;
        cin >> k >> x;
        updateVal(k - 1, x, 1, 0, n - 1);
        cout << best[1] << endl;
    }
}
