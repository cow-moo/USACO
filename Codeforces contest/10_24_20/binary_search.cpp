#include <iostream>
#include <vector>
using namespace std;
#define MOD 1000000007

vector<pair<int, bool> > checks;

int main()
{
    int n, x, pos;
    cin >> n >> x >> pos;

    int lessCount = 0, greaterCount = 0;

    int l = 0, r = n;
    while (l < r)
    {
        int mid = (l + r) / 2;
        if (mid + 1 <= pos + 1)
        {
            checks.push_back({mid, false});
            lessCount++;
            l = mid + 1;
        }
        else
        {
            checks.push_back({mid, true});
            greaterCount++;
            r = mid;
        }
    }
    lessCount--;

    long long ans = 1;
    if (lessCount > x - 1 || greaterCount > n - x)
    {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 0; i < lessCount; i++)
    {
        ans *= x - 1 - i;
        ans %= MOD;
    }
    for (int i = 0; i < greaterCount; i++)
    {
        ans *= n - x - i;
        ans %= MOD;
    }

    for (int i = 1; i <= n - lessCount - greaterCount - 1; i++)
    {
        ans *= i;
        ans %= MOD;
    }

    cout << ans << endl;
}
