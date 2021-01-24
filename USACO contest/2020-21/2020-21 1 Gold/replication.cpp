#include <iostream>
#include <queue>
#include <vector>
using namespace std;

//visited by center
bool visited[1005][1005];
bool possible[1005][1005];
string farm[1005];
//coord, time
queue<pair<pair<int, int>, int> > q;

pair<int, int> disp[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
pair<int, int> pain[4] = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

bool check_dir(pair<int, int> coord, int sz, int i)
{
    vector<pair<int, int> > a;
    for (int j = 0; j < sz; j++)
    {
        int a1, a2, b1, b2;
        if (disp[i].second != 0)
        {
            a1 = j - sz; b1 = j * disp[i].second;
            a2 = sz - j; b2 = j * disp[i].second;
            //j - sz, j * disp[i].second
            //sz - j, j * disp[i].second
        }
        else
        {
            a1 = j * disp[i].first; b1 = j - sz;
            a2 = j * disp[i].first; b2 = sz - j;
            //j * disp[i].first, j - sz
            //j * disp[i].first, sz - j
        }
        if (farm[coord.first + a1][coord.second + b1] == '#' || farm[coord.first + a2][coord.second + b2] == '#')
        {
            return false;
        }

        a.push_back({a1, b1});
        a.push_back({a2, b2});
    }
    if (farm[coord.first + sz * disp[i].first][coord.second + sz * disp[i].second] == '#')
        return false;
    a.push_back({sz * disp[i].first, sz * disp[i].second});

    for (auto b : a)
    {
        possible[coord.first + b.first][coord.second + b.second] = true;
    }
    return true;
}

int main()
{
    int n, d;
    cin >> n >> d;

    for (int i = 0; i < n; i++)
    {
        cin >> farm[i];
        for (int j = 0; j < n; j++)
        {
            if (farm[i][j] == 'S')
            {
                q.push({{i, j}, 0});
                possible[i][j] = true;
                visited[i][j] = true;
            }
        }
    }

    while (!q.empty())
    {
        pair<int, int> coord = q.front().first;
        int time = q.front().second;
        q.pop();

        //if (visited[coord.first][coord.second])
        //    continue;

        int sz = time / d;
        for (int i = 0; i < 4; i++)
        {
            pair<int, int> newCoord = {coord.first + disp[i].first, coord.second + disp[i].second};
            if (visited[newCoord.first][newCoord.second])
                continue;

            //vector<pair<int, int> > newPossible;

            //cout << newCoord.first << " " << newCoord.second << " " << sz << " " << i << endl;
            if (!check_dir(newCoord, sz, i))
            {
                continue;
            }
            //cout << "move success" << endl;

            if ((time + 1) % d == 0)
            {
                if (!check_dir(newCoord, sz + 1, i))
                {
                    continue;
                }
                //cout << "expand success" << endl;
            }

            q.push({newCoord, time + 1});
            visited[newCoord.first][newCoord.second] = true;
        }
    }

    int ans = 0;
    //cout << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ans += possible[i][j];
            // if (possible[i][j])
            //     cout << 'x';
            // else
            //     cout << farm[i][j];
            
        }
        //cout << endl;
    }

    cout << ans << endl;
}