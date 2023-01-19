#include <iostream>
#include <unordered_map>
#include <math.h>
using namespace std;
#define MAXN 65

unordered_map<string, int> index;
int x[MAXN], y[MAXN], z[MAXN];
double dist[MAXN][MAXN];

int main()
{
    int t;
    cin >> t;

    for (int test = 0; test < t; test++)
    {
        int p;
        cin >> p;

        for (int i = 0; i < p; i++)
        {
            string name;
            cin >> name >> x[i] >> y[i] >> z[i];
            index[name] = i;
        }

        for (int i = 0; i < p; i++)
        {
            for (int j = 0; j < p; j++)
            {
                long long xx = x[i] - x[j];
                long long yy = y[i] - y[j];
                long long zz = z[i] - z[j];
                dist[i][j] = dist[j][i] = sqrt(xx * xx + yy * yy + zz * zz);
            }
        }

        int w;
        cin >> w;
        for (int i = 0; i < w; i++)
        {
            string p1, p2;
            cin >> p1 >> p2;
            dist[index[p1]][index[p2]] = 0;
        }

        for (int k = 0; k < p; k++)
        {
            for (int i = 0; i < p; i++)
            {
                for (int j = 0; j < p; j++)
                {
                    if (dist[i][j] > dist[i][k] + dist[k][j])
                        dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }

        int q;
        cin >> q;
        for (int i = 0; i < q; i++)
        {
            string p1, p2;
            cin >> p1 >> p2;
            cout << dist[index[p1]][index[p2]] << endl;
        }
    }
}
