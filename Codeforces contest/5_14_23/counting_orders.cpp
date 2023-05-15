#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 200005
#define MOD 1000000007ll

int a[MAXN], b[MAXN];

long long solve()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    sort(a, a + n);
    sort(b, b + n);

    long long ans = 1;
    int r = n - 1;
    for (int i = n - 1; i >= 0; i--)
    {
        while (r != -1 && a[r] > b[i])
            r--;
        //ans = ans * (n - 1 - r - (n - 1 - i)) % MOD;
        ans = ans * (i - r < 0 ? 0 : i - r) % MOD;
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        cout << solve() << endl;
    }
}