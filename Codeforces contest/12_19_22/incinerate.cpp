#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 100050

pair<long long, int> monsters[MAXN];

int main()
{
    int t;
    cin >> t;

    for (int z = 0; z < t; z++)
    {
        int n, k;
        cin >> n >> k;

        for (int i = 0; i < n; i++)
        {
            cin >> monsters[i].first;
        }
        for (int i = 0; i < n; i++)
        {
            cin >> monsters[i].second;
        }
        sort(monsters, monsters + n);

        for (int i = n - 2; i >= 0; i--)
        {
            monsters[i].second = min(monsters[i].second, monsters[i + 1].second);
        }

        long long damage = 0;
        while (k > 0)
        {
            damage += k;
            int cur = upper_bound(monsters, monsters + n, make_pair(damage + 1, 0)) - monsters;
            if (cur == n)
            {
                break;
            }
            k -= monsters[cur].second;
        }
        if (damage >= monsters[n - 1].first)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}
