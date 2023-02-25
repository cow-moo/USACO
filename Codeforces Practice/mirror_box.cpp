#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAXC 100050
#define MAXN 105
#define H 100
#define X 100000
#define PP pair<pair<int, int>, int>

int h1, hr, n;
vector<PP> ceiling, floor;

int solve()
{
    int res = 0;

    //i is number of rooms
    for (int i = 2;; i++)
    {
        int dy;
        if (i % 2 == 0)
        {
            dy = i * H - hr - h1;
        }
        else
        {
            dy = (i - 1) * H + hr - h1;
        }

        // y = dy/X * x + h1
        // y - h1 = dy/X * x
        // X/dy * (y - h1) = x

        bool fail = false;
        bool done = false;
        int score = 0;
        vector<PP>::iterator prev = ceiling.end();

        //ceil
        for (int j = 1; j < i; j += 2)
        {
            int y = X * j;
            int x = X * (y - h1) / dy;

            PP temp = {{x, 0}, 0};
            auto it = lower_bound(ceiling.begin(), ceiling.end(), temp);
            auto itfive = lower_bound(ceiling.begin(
            ))
            if (it == ceiling.begin())
            {
                done = true;
                break;
            }
            
            it--;

            if (it->first.second > x)
            {
                if (prev == it)
                {
                    fail = true;
                    break;
                }

                score += it->second;
                prev = it;
            }
        }

        if (done)
            break;

                //ceil
        for (int j = 2; j < i; j += 2)
        {
            int y = X * j;
            int x = X * (y - h1) / dy;

            auto it = lower_bound(floor.begin(), floor.end(), {{x, 0}, 0});
            
            if (it == ceiling.begin())
            {
                done = true;
                break;
            }
            
            it--;

            if (it->first.second > x)
            {
                if (prev == it)
                {
                    fail = true;
                    break;
                }

                score += it->second;
                prev = it;
            }
        }

        if (!fail)
        {
            res = max(res, score);
        }
    }
    
    return res;
}

int main()
{
    cin >> h1 >> hr >> n;

    for (int i = 0; i < n; i++)
    {
        int score, a, b;
        char pos;
        cin >> score >> pos >> a >> b;

        if (pos == 'T')
        {
            ceiling.push_back({{a, b}, score});
        }
        else
        {
            floor.push_back({{a, b}, score});
        }
    }

    sort(ceiling.begin(), ceiling.end());
    sort(floor.begin(), floor.end());

    int ans = solve();
    swap(floor, ceiling);
    ans = max(ans, solve());
    cout << ans << endl;
}