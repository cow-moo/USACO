#include <iostream>
using namespace std;
#define MAXN 200050

int arr[MAXN];
int pre[MAXN]; //prev index of breed i

int bit[MAXN];
long long sum(int i)
{
    long long sum = 0;
    while (i > 0)
    {
        sum += bit[i];
        i -= (i) & -(i);
    }
    return sum;
}

void add(int i, int delta)
{
    while (i <= MAXN)
    {
        bit[i] += delta;
        i += (i) & -(i);
    }
}

//inclusive
long long range(int l, int r)
{
    return sum(r) - sum(l - 1);
}

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        pre[i] = -1;
    }

    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        add(i, 1);
        if (pre[arr[i]] != -1)
        {
            add(pre[arr[i]], -1);
        }
        ans += range(pre[arr[i]] + 1, i - 1);
        pre[arr[i]] = i;
    }

    cout << ans << endl;
}
