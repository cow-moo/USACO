#include <iostream>
using namespace std;
#define MAXN 100005

long long books[MAXN];
int n;

int check(long long money)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (money >= books[i])
        {
            money -= books[i];
            cnt++;
        }
    }
    return cnt;
}

void solve()
{
    int m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> books[i];
        if (books[i] == 0)
        {
            i--; n--; m--;
        }
    }
    if (m < 0)
    {
        cout << "Impossible" << endl;
        return;
    }
    if (n == m)
    {
        cout << "Richman" << endl;
        return;
    }

    long long l = 0, r = 1000000000000000;
    while (l < r)
    {
        long long mid = (l + r) / 2;
        if (check(mid) > m)
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << l - 1 << endl;
}

int main()
{
    int t;
    cin >> t;

    for (int z = 0; z < t; z++)
    {
        solve();
    }
}