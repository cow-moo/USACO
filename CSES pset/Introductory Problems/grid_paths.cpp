#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool visited[10][10];
pair<int, int> dir[4] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
long long ans = 0;
string str;


bool blocked(int r, int c)
{
    return r < 0 || r >= 7 || c < 0 || c >= 7 || visited[r][c];
}

int countNeighbors(int r, int c)
{
    int res = 0;
    for (int i = 0; i < 4; i++)
    {
        int newr = r + dir[i].first;
        int newc = c + dir[i].second;
        if (!blocked(newr, newc))
        {
            res++;
        }
    }
    return res;
}

void printBoard()
{
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            cout << visited[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

void dfs(int r, int c, int n)
{
    if (blocked(r + 1, c) && blocked(r - 1, c) && !blocked(r, c + 1) && !blocked(r, c - 1))
        return;

    if (!blocked(r + 1, c) && !blocked(r - 1, c) && blocked(r, c + 1) && blocked(r, c - 1))
        return;

    if (r == 6 && c == 6 && !visited[0][6])
        return;

    //printBoard();
    //cout << "a";

    visited[r][c] = true;

    if (r == 6 && c == 0)
    {
        bool done = true;
        for (int i = 0; i < 7; i++)
        {
            for (int j = 0; j < 7; j++)
            {
                if (!visited[i][j])
                {
                    done = false;
                    break;
                }
            }
        }
        if (done)
            ans++;

        visited[r][c] = false;
        return;
    }


    if (str[n] == '?')
    {
        int singlei = -1;
        for (int i = 0; i < 4; i++)
        {
            int newr = r + dir[i].first;
            int newc = c + dir[i].second;
            if (!blocked(newr, newc) && countNeighbors(newr, newc) == 1 && !(newr == 6 && newc == 0))
            {
                if (singlei != -1)
                {
                    visited[r][c] = false;
                    return;
                }
                singlei = i;
            }
        }

        if (singlei != -1)
        {
            dfs(r + dir[singlei].first, c + dir[singlei].second, n + 1);
        }
        else
        {
            for (int i = 0; i < 4; i++)
            {
                int newr = r + dir[i].first;
                int newc = c + dir[i].second;
                if (!blocked(newr, newc))
                {
                    dfs(newr, newc, n + 1);
                }
            }
        }
    }
    else
    {
        if (str[n] == 'D')
        {
            if (!blocked(r + 1, c))
                dfs(r + 1, c, n + 1);
        }
        else if (str[n] == 'U')
        {
            if (!blocked(r - 1, c))
                dfs(r - 1, c, n + 1);
        }
        else if (str[n] == 'L')
        {
            if (!blocked(r, c - 1))
                dfs(r, c - 1, n + 1);
        }
        else
        {
            if (!blocked(r, c + 1))
                dfs(r, c + 1, n + 1);
        }
    }
    visited[r][c] = false;
}

int main()
{
    cin >> str;

    dfs(0, 0, 0);
    cout << ans << endl;
}
