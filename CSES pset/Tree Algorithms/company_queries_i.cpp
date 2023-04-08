#include <iostream>
using namespace std;
#define MAXN 200005

int parent[MAXN][20];

int main()
{
    int n, q;
    cin >> n >> q;

    for (int i = 2; i <= n; i++)
    {
        cin >> parent[i][0];
    }

    for (int i = 1; i <= 18; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            parent[j][i] = parent[parent[j][i - 1]][i - 1];
        }
    }

    for (int i = 0; i < q; i++)
    {
        int x, k;
        cin >> x >> k;

        for (int j = 0; k > 0; j++)
        {
            if (k & (1 << j))
            {
                x = parent[x][j];
                k ^= 1 << j;
            }
        }

        cout << (x == 0 ? -1 : x) << endl;
    }
}