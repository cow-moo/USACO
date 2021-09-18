#include <iostream>
#include <queue>
using namespace std;

//(i, j) is neighbors with [i][neighbor[i][j].first] and [neighbor[i][j].second][j]
pair<int, int> neighbors[1005][1005];
bool visited[1005][1005];
string crossword[1005];

int main()
{
    int t;
    cin >> t;

    for (int z = 1; z <= t; z++)
    {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++)
        {
            cin >> crossword[i];
            for (int j = 0; j < m; j++)
            {
                visited[i][j] = false;
            }
        }

        for (int i = 0; i < n; i++)
        {
            int lastBlack = -1;
            for (int j = 0; j <= m; j++)
            {
                if (j == m || crossword[i][j] == '#')
                {
                    //sum is lastBlack + j
                    for (int k = lastBlack + 1; k < j; k++)
                    {
                        neighbors[i][k].first = lastBlack + j - k;
                    }
                    lastBlack = j;
                }
            }
        }

        for (int j = 0; j < m; j++)
        {
            int lastBlack = -1;
            for (int i = 0; i <= n; i++)
            {
                if (i == n || crossword[i][j] == '#')
                {
                    for (int k = lastBlack + 1; k < i; k++)
                    {
                        neighbors[k][j].second = lastBlack + i - k;
                    }
                    lastBlack = i;
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (crossword[i][j] != '#' && crossword[i][j] != '.' && !visited[i][j])
                {
                    queue<pair<int, int> > q;
                    q.push({i, j});
                    while (!q.empty())
                    {
                        pair<int, int> cur = q.front();
                        q.pop();

                        if (visited[cur.first][cur.second])
                            continue;
                        visited[cur.first][cur.second] = true;
                        if (crossword[cur.first][cur.second] == '.')
                            ans++;
                        crossword[cur.first][cur.second] = crossword[i][j];

                        if (!visited[cur.first][neighbors[cur.first][cur.second].first])
                            q.push({cur.first, neighbors[cur.first][cur.second].first});
                        if (!visited[neighbors[cur.first][cur.second].second][cur.second])
                            q.push({neighbors[cur.first][cur.second].second, cur.second});
                    }
                }
            }
        }

        cout << "Case #" << z << ": " << ans << endl;
        for (int i = 0; i < n; i++)
        {
            cout << crossword[i] << endl;
        }
//        for (int i = 0; i < n; i++)
//        {
//            for (int j = 0; j < m; j++)
//            {
//                cout << "(" << neighbors[i][j].first << ", " << neighbors[i][j].second << ") ";
//            }
//            cout << endl;
//        }
    }
}
