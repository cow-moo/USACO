#include <iostream>
using namespace std;
#define MAXN 200005

int parent[MAXN][20];
int depth[MAXN];

int getDepth(int cur)
{
    if (depth[cur] == 0)
        return depth[cur] = getDepth(parent[cur][0]) + 1;
    else
        return depth[cur];
}

int getParent(int x, int k)
{
    for (int j = 0; k > 0; j++)
    {
        if (k & (1 << j))
        {
            x = parent[x][j];
            k ^= 1 << j;
        }
    }

    return x;
}

int main()
{
    depth[1] = 1;
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
        int a, b;
        cin >> a >> b;

        if (getDepth(a) > getDepth(b))
            swap(a, b);

        b = getParent(b, getDepth(b) - getDepth(a));

        if (a == b)
        {
            cout << a << endl;
            continue;
        }

        for (int j = 18; j >= 0; j--)
        {
            if (parent[a][j] != parent[b][j])
            {
                a = parent[a][j];
                b = parent[b][j];
            }
        }

        cout << parent[a][0] << endl;
    }
}