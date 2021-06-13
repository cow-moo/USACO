#include <iostream>
using namespace std;

bool grid[1005][1005];
int segments[1005][1005][2][2];
//stores max length of segments with endpoint at i, j in the 4 directions
//00 - left
//01 - right
//10 - up
//11 - down

int getLShapes(int x, int y)
{
    int result = 0;
    for (int i = 0; i <= 1; i++)
    {
        for (int j = 0; j <= 1; j++)
        {
            result += max(min(segments[x][y][0][i] / 2, segments[x][y][1][j]) - 1, 0);
            result += max(min(segments[x][y][0][i], segments[x][y][1][j] / 2) - 1, 0);
            //segment[x][y][1][j]
        }
    }
    return result;
}

int main()
{
    int t;
    cin >> t;

    for (int z = 1; z <= t; z++)
    {
        int r, c;
        cin >> r >> c;

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cin >> grid[i][j];
            }
            grid[i][c] = 0;
        }
        for (int j = 0; j < c; j++)
            grid[r][j] = 0;

        for (int i = 0; i < r; i++)
        {
            int curStart = -1;
            for (int j = 0; j <= c; j++)
            {
                if (grid[i][j] == 1)
                {
                    if (curStart == -1)
                        curStart = j;
                }
                if (grid[i][j] == 0)
                {
                    if (curStart != -1)
                    {
                        int length = j - curStart;
                        for (int k = 0; k < length; k++)
                        {
                            segments[i][curStart + k][0][0] = k + 1;
                            segments[i][curStart + k][0][1] = length - k;
                        }

                        curStart = -1;
                    }
                }
            }
        }

        for (int j = 0; j < c; j++)
        {
            int curStart = -1;
            for (int i = 0; i <= r; i++)
            {
                if (grid[i][j] == 1)
                {
                    if (curStart == -1)
                        curStart = i;
                }
                if (grid[i][j] == 0)
                {
                    if (curStart != -1)
                    {
                        int length = i - curStart;
                        for (int k = 0; k < length; k++)
                        {
                            segments[curStart + k][j][1][0] = k + 1;
                            segments[curStart + k][j][1][1] = length - k;
                        }

                        curStart = -1;
                    }
                }
            }
        }

//        for (int i = 0; i < 4; i++)
//        {
//            cout << segments[3][0][i] << " ";
//        }
//        cout << endl;

        int ans = 0;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (grid[i][j] == 1)
                    ans += getLShapes(i, j);
            }
        }
        cout << "Case #" << z << ": " << ans << endl;
    }
}

/*
1
4 3
1 0 0
1 0 1
1 0 0
1 1 0
*/
