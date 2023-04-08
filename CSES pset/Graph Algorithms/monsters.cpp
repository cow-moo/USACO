#include <iostream>
#include <queue>
using namespace std;
#define MAXN 1005

string maze[MAXN];
string path;

void getPath(int x, int y)
{
    if (maze[x][y] == 'D')
        getPath(x - 1, y);
    else if (maze[x][y] == 'U')
        getPath(x + 1, y);
    else if (maze[x][y] == 'R')
        getPath(x, y - 1);
    else if (maze[x][y] == 'L')
        getPath(x, y + 1);
    else
        return;
    path += maze[x][y];
}

struct Entry
{
    int i, j;
    bool monster;
};

int main()
{
    int n, m;
    cin >> n >> m;

    Entry start;
    queue<Entry> q;
    for (int i = 0; i < n; i++)
    {
        cin >> maze[i];
        for (int j = 0; j < m; j++)
        {
            if (maze[i][j] == 'M')
                q.push({i, j, true});
            else if (maze[i][j] == 'A')
                start = {i, j, false};
        }
    }
    q.push(start);
    if (start.i == 0 || start.i == n - 1 || start.j == 0 || start.j == m - 1)
    {
        cout << "YES\n0" << endl;
        return 0;
    }
    string dirs = "DRUL";
    while (!q.empty())
    {
        Entry cur = q.front();
        q.pop();

        pair<int, int> adj[] = {{cur.i + 1, cur.j}, {cur.i, cur.j + 1}, {cur.i - 1, cur.j}, {cur.i, cur.j - 1}};
        for (int i = 0; i < 4; i++)
        {
            auto [newi, newj] = adj[i];
            if (newi < 0 || newi >= n || newj < 0 || newj >= m)
                continue;
            
            if (maze[newi][newj] == '.')
            {
                if (cur.monster)
                {
                    maze[newi][newj] = 'M';
                    q.push({newi, newj, true});
                }
                else
                {
                    maze[newi][newj] = dirs[i];
                    q.push({newi, newj, false});

                    if (newi == 0 || newi == n - 1 || newj == 0 || newj == m - 1)
                    {
                        getPath(newi, newj);
                        cout << "YES" << endl << path.length() << endl << path << endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout << "NO" << endl;
}