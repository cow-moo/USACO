#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 1050

struct Fabric
{
    string c;
    int d;
    int u;
};

Fabric color[MAXN], durability[MAXN];

bool sortc(Fabric a, Fabric b)
{
    return (a.c == b.c) ? a.u < b.u : a.c < b.c;
}

bool sortd(Fabric a, Fabric b)
{
    return (a.d == b.d) ? a.u < b.u : a.d < b.d;
}

int main()
{
    int t;
    cin >> t;

    for (int z = 1; z <= t; z++)
    {
        int n;
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            cin >> color[i].c >> color[i].d >> color[i].u;
            durability[i] = color[i];
        }

        sort(color, color + n, sortc);
        sort(durability, durability + n, sortd);

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (color[i].u == durability[i].u)
                ans++;
        }

        cout << "Case #" << z << ": " << ans << endl;
    }
}
