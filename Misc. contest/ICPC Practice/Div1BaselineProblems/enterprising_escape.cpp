#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

unordered_map<char, int> klingons;
string grid[1005];

int main()
{
    pair<int, int> dirs[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    int t;
    cin >> t;

    for (int z = 0; z < t; z++)
    {
        int k, w, h;
        cin >> k >> w >> h;

        for (int i = 0; i < k; i++)
        {
            char label;
            int duration;
            cin >> label >> duration;
            klingons[label] = duration;
        }

        pair<int, int> start;
        for (int i = 0; i < h; i++)
        {
            cin >> grid[i];
            for (int j = 0; j < w; j++)
            {
                if (grid[i][j] == 'E')
                {
                    start = {i, j};
                }
            }
        }

        priority_queue<pair<long long, pair<int, int>>> pq;
        pq.push({0, start});
        while (!pq.empty())
        {
            long long t = pq.top().first;
            pair<int, int> coord = pq.top().second;
            pq.pop();

            grid[coord.first][coord.second] = ' ';
            if (coord.first == 0 || coord.first == h - 1 || coord.second == 0 || coord.second == w - 1)
            {
                cout << -t << endl;
                break;
            }

            for (pair<int, int> dir : dirs)
            {
                pair<int, int> newCoord = {coord.first + dir.first, coord.second + dir.second};
                if (newCoord.first < 0 || newCoord.first >= h || newCoord.second < 0 || newCoord.second >= w || grid[newCoord.first][newCoord.second] == ' ')
                {
                    continue;
                }

                pq.push({t - klingons[grid[newCoord.first][newCoord.second]], newCoord});
            }
        }

        klingons.clear();
    }
}
