#include <iostream>
#include <vector>
using namespace std;

int ans[8][8];

vector<pair<int, int>> getNeighbor(int x, int y)
{
    pair<int, int> cands[] = {{2, 1}, {1, 2}, {-1, 2}, {2, -1}, {1, -2}, {-2, 1}, {-1, -2}, {-2, -1}};
    vector<pair<int, int>> res;
    for (int i = 0; i < 8; i++)
    {
        if (x + cands[i].first >= 0 && x + cands[i].first < 8 && y + cands[i].second >= 0 && y + cands[i].second < 8)
            res.push_back({x + cands[i].first, y + cands[i].second});
    }
    return res;
}

int check(int x, int y)
{
    auto n = getNeighbor(x, y);
    int res = 0;
    for (auto p : n)
    {
        if (ans[p.first][p.second] == 0)
            res++;
    }
    return res;
}

int main()
{
    int x, y;
    cin >> x >> y;
    swap(x, y);
    x--, y--;
    ans[x][y] = 1;

    for (int i = 0; i < 63; i++)
    {
        auto cands = getNeighbor(x, y);
        int best = 10;
        pair<int, int> b;
        for (auto c : cands)
        {
            if (ans[c.first][c.second])
                continue;
            int res = check(c.first, c.second);
            if (res < best)
            {
                best = res;
                b = c;
            }
        }
        ans[b.first][b.second] = ans[x][y] + 1;
        x = b.first, y = b.second;
    }
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
}