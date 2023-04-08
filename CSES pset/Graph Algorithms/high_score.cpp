#include <iostream>
using namespace std;
#define MAXN 2505
#define MAXM 5005
#define INF 1000000000000000

long long d[MAXN];
bool cycle[MAXN];

struct Edge
{
    int a, b;
    long long x;
} edges[MAXM];

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> edges[i].a >> edges[i].b >> edges[i].x;
    }

    for (int i = 1; i <= n; i++)
    {
        d[i] = -INF;
    }
    d[1] = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (d[edges[j].a] > -INF && d[edges[j].b] < d[edges[j].a] + edges[j].x)
            {
                d[edges[j].b] = d[edges[j].a] + edges[j].x;
                if (i == n - 1)
                    cycle[edges[j].a] = cycle[edges[j].b] = true;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (cycle[edges[j].a])
                cycle[edges[j].b] = true;
        }
    }

    // for (int i = 1; i <= n; i++)
    //     cout << d[i] << endl;

    if (cycle[n])
    {
        cout << -1 << endl;
    }
    else
    {
        cout << d[n] << endl;
    }
}