#include <iostream>
using namespace std;
#define MAXN 1005

int trees[MAXN][MAXN];

int main()
{
    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++)
    {
        string row;
        cin >> row;
        for (int j = 1; j <= n; j++)
        {
            trees[i][j] = trees[i - 1][j] + trees[i][j - 1] - trees[i - 1][j - 1] + (row[j - 1] == '*');
            //cout << i << " " << j << " " << trees[i][j] << endl;
        }
    }

    for (int i = 0; i < q; i++)
    {
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        if (y1 > y2)
            swap(y1, y2);
        if (x1 > x2)
            swap(x1, x2);
        cout << trees[y2][x2] - trees[y2][x1 - 1] - trees[y1 - 1][x2] + trees[y1 - 1][x1 - 1] << endl;
    }
}