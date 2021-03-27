#include <iostream>
#include <stdio.h>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> flavors[1000005];

int main()
{
    freopen("cowpatibility.in", "r", stdin);
    freopen("cowpatibility.out", "w", stdout);

    int n;
    cin >> n;

    int ans = n * (n - 1) / 2;

    for (int i = 0; i < n; i++)
    {
        set<int> comp;
        for (int j = 0; j < 5; j++)
        {
            int fav;
            cin >> fav;
            for (int cow : flavors[fav])
                comp.insert(cow);
            flavors[fav].push_back(i);
        }
        ans -= comp.size();
    }

    cout << ans << endl;
}
