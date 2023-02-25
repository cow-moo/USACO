#include <iostream>
#include <map>
#include <climits>
#include <vector>
using namespace std;

struct {
    int x;
    int y;
    long long c;
} customers[15];

map<int, long long> dp[11][11][22];
pair<char, long long> tolls[4];
//pair<int, int> customers[15];

long long calc(int dir, long long c)
{
    if (tolls[dir].first == '+')
        return c + tolls[dir].second;
    if (tolls[dir].first == '-')
        return c - tolls[dir].second;
    if (tolls[dir].first == '*')
        return c * tolls[dir].second;
    if (tolls[dir].first == '/')
    {
        if (c >= 0)
            return c / tolls[dir].second;
        else
            return (c + 1) / tolls[dir].second - 1;
    }
}

long long test(long long a, long long b)
{
    return (a + 1) / b - 1;
}

int main()
{
    //cout << test(-8, 7);
    int t;
    cin >> t;

    for (int z = 1; z <= t; z++)
    {
        int n, p, m, r, c;
        cin >> n >> p >> m >> r >> c;
        r--; c--;

        for (int i = 0 ; i < 4; i++)
        {
            cin >> tolls[i].first >> tolls[i].second;
        }

        for (int i = 0; i < p; i++)
        {
            cin >> customers[i].x >> customers[i].y >> customers[i].c;
            customers[i].x--;
            customers[i].y--;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                dp[i][j][0].clear();
        }

        dp[r][c][0][0] = 0;
        for (int time = 1; time <= m; time++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                    dp[i][j][time].clear();
            }

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    //if (i > 0)
                    //for (auto v : dp[i - 1][j])
                    for (auto state : dp[i][j][time - 1])
                    {
                        if (i - 1 >= 0)
                        {
                            //north
                            long long val = calc(0, state.second);
                            auto it = dp[i - 1][j][time].find(state.first);
                            if (it == dp[i - 1][j][time].end())
                            {
                                dp[i - 1][j][time][state.first] = val;
                            }
                            else
                            {
                                it->second = max(it->second, val);
                            }
                            //dp[i - 1][j][time] = max(dp[i - 1][j][time])
                        }
                        if (j + 1 < n)
                        {
                            //east
                            long long val = calc(1, state.second);
                            auto it = dp[i][j + 1][time].find(state.first);
                            if (it == dp[i][j + 1][time].end())
                            {
                                dp[i][j + 1][time][state.first] = val;
                            }
                            else
                            {
                                it->second = max(it->second, val);
                            }
                        }
                        if (j - 1 >= 0)
                        {
                            //west
                            long long val = calc(2, state.second);
                            auto it = dp[i][j - 1][time].find(state.first);
                            if (it == dp[i][j - 1][time].end())
                            {
                                dp[i][j - 1][time][state.first] = val;
                            }
                            else
                            {
                                it->second = max(it->second, val);
                            }
                        }
                        if (i + 1 < n)
                        {
                            //south
                            long long val = calc(3, state.second);
                            auto it = dp[i + 1][j][time].find(state.first);
                            if (it == dp[i + 1][j][time].end())
                            {
                                dp[i + 1][j][time][state.first] = val;
                            }
                            else
                            {
                                it->second = max(it->second, val);
                            }
                        }
                        //long long val = //calc(0, state.second);
                        auto it = dp[i][j][time].find(state.first);
                        if (it == dp[i][j][time].end())
                        {
                            dp[i][j][time][state.first] = state.second;
                        }
                        else
                        {
                            it->second = max(it->second, state.second);
                        }
                    }

                }
            }

            for (int i = 0; i < p; i++)
            {
                vector<pair<int, long long> > temp;
                for (auto state : dp[customers[i].x][customers[i].y][time])
                {
                    //cout <<  "b" << customers[i].x << " " << customers[i].y << " " << state.first << endl;
                    if ((state.first & (1 << i)) == 0)
                    {
                        //cout << "wow" << endl;
                        long long val = state.second + customers[i].c;
                        auto it = dp[customers[i].x][customers[i].y][time].find(state.first + (1 << i));
                        if (it == dp[customers[i].x][customers[i].y][time].end())
                        {
                            temp.push_back({state.first + (1 << i), val});
                        }
                        else
                        {
                            it->second = max(it->second, val);
                        }
                    }
                }

                for (auto state : temp)
                {
                    dp[customers[i].x][customers[i].y][time][state.first] = state.second;
                    //cout << "a" << state.first << " " << state.second << endl;
                }
            }
        }

        int bitmask = (1 << p) - 1;
        long long ans = LLONG_MIN;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                auto it = dp[i][j][m].find(bitmask);
                if (it != dp[i][j][m].end())
                    ans = max(ans, it->second);
//                for (auto state : dp[i][j][m])
//                {
//                    ans = max(ans, state.second);
//                }
            }
        }

        cout << "Case #" << z << ": ";
        if (ans == LLONG_MIN)
        {
            cout << "IMPOSSIBLE" << endl;
        }
        else
            cout << ans << endl;

//        int temp = 1;
//        for (int i = 0; i < n; i++)
//        {
//            for (int j = 0; j < n; j++)
//            {
//                if (dp[i][j][m].count(temp) == 1)
//                    cout << dp[i][j][m][0] << " ";
//                else
//                    cout << "  ";
//            }
//            cout << endl;
//        }
//        cout << endl;
    }
}

/*
2
3 0 3 2 2
+ 1
- 2
+ 3
/ 4
3 0 1 2 3
- 2
- 2
- 2
- 2
*/
