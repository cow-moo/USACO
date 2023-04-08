#include <iostream>
#include <queue>
using namespace std;
#define MAXN 1005
 
string arr[MAXN];
string path;

void getPath(int x, int y)
{
    if (arr[x][y] == 'D')
        getPath(x - 1, y);
    else if (arr[x][y] == 'U')
        getPath(x + 1, y);
    else if (arr[x][y] == 'R')
        getPath(x, y - 1);
    else if (arr[x][y] == 'L')
        getPath(x, y + 1);
    else
        return;
    path += arr[x][y];
}

int main()
{
    int n, m;
    cin >> n >> m;
 
    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 'A')
            {
                q.push({i, j});
                arr[i][j] = '#';
            }
        }
    }
 
    while (!q.empty())
    {
        auto [x,y] = q.front();
        q.pop();
 
        pair<pair<int, int>, char> cands[] = {{{x + 1, y}, 'D'}, {{x - 1, y}, 'U'}, {{x, y + 1}, 'R'}, {{x, y - 1}, 'L'}};
        for (auto [coord, c] : cands)
        {
            auto [newx, newy] = coord;
            if (newx < 0 || newx >= n || newy < 0 || newy >= m || (arr[newx][newy] != '.' && arr[newx][newy] != 'B'))
                continue;
            if (arr[newx][newy] == 'B')
            {
                cout << "YES" << endl;
                getPath(x, y);
                path += c;
                cout << path.length() << endl;
                cout << path << endl;
                return 0;
            }
            arr[newx][newy] = c;
            q.push({newx, newy});
        }
    }
    cout << "NO" << endl;
}