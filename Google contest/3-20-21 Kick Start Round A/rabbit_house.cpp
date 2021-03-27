#include <iostream>
#include <queue>
using namespace std;

int house[305][305];
int disp[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int main()
{
    int t;
    cin >> t;

    for (int z = 1; z <= t; z++)
    {
        int r, c;
        cin >> r >> c;

        priority_queue<pair<int, pair<int, int> > > pq;

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cin >> house[i][j];
                pq.push({house[i][j], {i, j}});
            }
        }

        long long ans = 0;
        while (!pq.empty())
        {
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            if (house[x][y] != pq.top().first)
            {
                pq.pop();
                continue;
            }
            else
                pq.pop();

            //cout << x << " " << y << endl;
            for (int i = 0; i < 4; i++)
            {
                int newx = x + disp[i][0];
                int newy = y + disp[i][1];
                if (newx == -1 || newx == r || newy == -1 || newy == c)
                    continue;
                if (house[newx][newy] < house[x][y] - 1)
                {
                    ans += house[x][y] - 1 - house[newx][newy];
                    house[newx][newy] = house[x][y] - 1;

                    pq.push({house[newx][newy], {newx, newy}});
                }
            }
        }

        cout << "Case #" << z << ": " << ans << endl;
    }
}
