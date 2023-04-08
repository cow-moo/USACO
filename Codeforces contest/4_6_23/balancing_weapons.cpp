#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 3005

struct Gun
{
    long long f, d, p;
} guns[MAXN];

long long ceil(long long a, long long b)
{
    return (a + b - 1) / b;
}

void solve()
{
    int n;
    long long k;
    cin >> n >> k;

    for (int i = 0; i < n; i++)
        cin >> guns[i].f;
    for (int i = 0; i < n; i++)
    {
        cin >> guns[i].d;
        guns[i].p = guns[i].f * guns[i].d;
    }
    
    int ans = n;
    for (int i = 0; i < n; i++)
    {
        int res = 0;
        bool bad = false;
        for (int j = 0; j < n; j++)
        {
            if (abs(guns[j].p - guns[i].p) <= k)
                continue;
            if (ceil(guns[i].p - k, guns[j].f) * guns[j].f > guns[i].p + k)
            {
                bad = true;
                break;
            }
            res++;
        }
        if (!bad)
            ans = min(ans, res);
    }
    cout << ans << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}