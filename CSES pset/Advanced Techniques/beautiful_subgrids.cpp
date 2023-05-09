#include <iostream>
#include <bitset>
using namespace std;
#define MAXN 3005
#pragma GCC target("popcnt")

bitset<MAXN> rows[MAXN];

int main()
{
    int n;
    cin >> n;

    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> rows[i];
        for (int j = 0; j < i; j++)
        {
            long long cnt = (rows[i] & rows[j]).count();
            ans += cnt * (cnt - 1) / 2;
        }
    }
    cout << ans << endl;
}