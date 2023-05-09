#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 200005
#define SIZE 200005

int arr[MAXN];

long long bit[SIZE];

int n;

long long sum(int i)
{
    i++;
    long long sum = 0;
    while (i > 0)
    {
        sum += bit[i];
        i -= (i) & -(i);
    }
    return sum;
}

void add(int i, long long delta)
{
    i++;
    while (i <= n + 5)
    {
        bit[i] += delta;
        i += (i) & -(i);
    }
}

pair<int, int> queries[MAXN];
int order[MAXN];
int ans[MAXN];

bool comp(int a, int b)
{
    return queries[a] < queries[b];
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    int q;
    cin >> n >> q;

    cin >> arr[0];
    add(0, 1);
    bool decreased = false;
    for (int i = 1; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] > arr[i - 1])
        {
            add(i, 1);
            decreased = false;
        }
        else if (!decreased)
        {
            add(i, 1);
            decreased = true;
        }
    }

    for (int i = 0; i < q; i++)
    {
        order[i] = i;
        cin >> queries[i].first >> queries[i].second;
    }

    sort(order, order + q, comp);

    int l = 0;
    for (int i = 0; i < q; i++)
    {
        pair<int, int> cur = queries[order[i]];
        while (l < cur.first - 1)
        {
            if (l + 2 < n && arr[l] >= arr[l + 1] && arr[l + 1] >= arr[l + 2])
            {
                add(l + 2, 1);
            }
            add(l, -1);
            l++;
        }
        ans[order[i]] = sum(cur.second - 1);
    }

    for (int i = 0; i < q; i++)
    {
        cout << ans[i] << endl;
    }
}