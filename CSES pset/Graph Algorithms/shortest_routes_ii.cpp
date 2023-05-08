#include <iostream>
using namespace std;
#define MAXN 505

long long dist[MAXN][MAXN];

int main()
{
    int n, m, q;
    cin >> n >> m >> q;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dist[i][j] = -1;
        }
        dist[i][i] = 0;
    }

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        if (dist[a][b] == -1 || dist[a][b] > c)
        {
            dist[a][b] = c;
            dist[b][a] = c;
        }
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dist[i][k] != -1 && dist[k][j] != -1 && (dist[i][j] == -1 || dist[i][j] > dist[i][k] + dist[k][j]))
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    //cout << "a" << dist[i][j] << endl;
                }
                //dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << dist[a - 1][b - 1] << endl;
    }
}
/*
4 3 5
1 2 5
1 3 9
2 3 3
1 2
2 1
1 3
1 4
3 2
*/