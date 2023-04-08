#include <iostream>
using namespace std;
#define MAXN 25

bool grid[MAXN][MAXN];
int edges[MAXN][MAXN];

int main()
{
    int n;
    cin >> n;

    int x = 0, y = 0;
    while (x <= n && y <= n)
    {
        grid[x][y] = true;
        x++;
        grid[x][y] = true;
        y++;
        grid[x][y] = true;
        y++;
        grid[x][y] = true;
        x++;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            pair<int, int> poss[] = {{i + 1, j}, {i, j + 1}, {i - 1, j}, {i, j - 1}};
            for (int k = 0; k < 4; k++)
            {
                auto [newi, newj] = poss[k];
                bool adj;
                if (newi < 0 || newi >= n || newj < 0 || newj >= n)
                    adj = 0;
                else
                    adj = grid[newi][newj];
                edges[i][j] += adj != grid[i][j];
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << edges[i][j] << " ";
        cout << endl;
    }
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n; i++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}