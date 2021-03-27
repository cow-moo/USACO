#include <iostream>
#include <stdio.h>
#include <set>
using namespace std;

pair<int, int> bales[100050];

int main()
{
    freopen("hayfeast.in", "r", stdin);
    freopen("hayfeast.out", "w", stdout);

    int n;
    long long m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> bales[i].first >> bales[i].second;
    }

    multiset<int> spice;
    int ans = 1e9;
    int l = 0, r = 0;
    long long flavor = 0;
    for (; l < n; l++)
    {
        for (; r < n; r++)
        {
            flavor += bales[r].first;
            //cout << flavor << endl;
            spice.insert(bales[r].second);
            //cout << "add " << r << endl;
            if (flavor >= m)
            {
                r++;
                break;
            }
        }
        //cout << l << " " << r << " " << flavor << endl;

        if (flavor >= m)
        {
            ans = min(ans, *spice.rbegin());
        }
        else
            break;

        //cout << "remove " << l << endl;
        flavor -= bales[l].first;
        spice.erase(spice.find(bales[l].second));
    }

    cout << ans << endl;
}
