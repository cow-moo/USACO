#include <iostream>
using namespace std;
#define MAXN 1005

string arr[MAXN];
int n, m;

void dfs(int x, int y)
{
    if (x < 0 || x >= n || y < 0 || y >= m || arr[x][y] == '#')
        return;
    arr[x][y] = '#';
    dfs(x + 1, y);
    dfs(x, y + 1);
    dfs(x - 1, y);
    dfs(x, y - 1);
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == '.')
            {
                dfs(i, j);
                ans++;
            }
        }
    }
    cout << ans << endl;
}
