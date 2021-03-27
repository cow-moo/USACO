#include <iostream>
#include <stdio.h>
#include <map>
#include <algorithm>
using namespace std;

struct Subset
{
    int sz;
    int flavor[5];
};

bool operator< (const Subset &a, const Subset &b)
{
    for (int i = 0; i < 5; i++)
    {
        if (a.flavor[i] < b.flavor[i])
            return true;
        if (a.flavor[i] > b.flavor[i])
            return false;
    }
    return false;
}

map<Subset, int> subsets;

Subset generate_subset(Subset &complete, int x)
{
    Subset s = {0, {0, 0, 0, 0, 0}};
    for (int i = 0; i < 5; i++)
    {
        if ((1 << i) & x)
            s.flavor[s.sz++] = complete.flavor[i];
    }
    return s;
}

int main()
{
    freopen("cowpatibility.in", "r", stdin);
    freopen("cowpatibility.out", "w", stdout);

    long long n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        Subset complete = {5, {0, 0, 0, 0, 0}};
        for (int j = 0; j < 5; j++)
            cin >> complete.flavor[j];
        sort(complete.flavor, complete.flavor + 5);

        for (int j = 1; j < 32; j++)
            subsets[generate_subset(complete, j)]++;
        //subsets[complete]++;
    }

    long long ans = n * (n - 1) / 2;
    for (auto p : subsets)
    {
//        cout << p.second << " ";
//        for (int i = 0; i < 5; i++)
//            cout << p.first.flavor[i] << " ";
//        cout << endl;
        ans -=  ((p.first.sz % 2 == 0) ? -1ll : 1ll) * p.second * (p.second - 1) / 2;
    }
    cout << ans << endl;
}
