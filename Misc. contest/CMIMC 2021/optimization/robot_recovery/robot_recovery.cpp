#include <iostream>
#include <vector>
#include <queue>
#include <stdio.h>
#include <fstream>
using namespace std;

pair<int, int> dir[4] = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
string dirStr = "DRLU";

string maze[1005];
vector<pair<int, int> > robots;
int dist[1005][1005];
int goodDir[1005][1005][4];
int r, c, n;
vector<int> ans;
pair<int, int> entrance;

void bfs()
{
    queue<pair<int, int> > q;
    q.push(entrance);

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            dist[i][j] = -1;
        }
    }

    dist[entrance.first][entrance.second] = 0;

    while (!q.empty())
    {
        int curr = q.front().first;
        int curc = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int newr = curr + dir[i].first;
            int newc = curc + dir[i].second;
            if (newr >= 0 && newr < r && newc >= 0 && newc < c && maze[newr][newc] != 'X')
            {
                if (dist[newr][newc] == -1)
                {
                    dist[newr][newc] = dist[curr][curc] + 1;
                    goodDir[newr][newc][3 - i] = 1;
                    q.push({newr, newc});
                }
                else if (dist[newr][newc] == dist[curr][curc] + 1)
                {
                    goodDir[newr][newc][3 - i] = 1;
                }
                else
                {
                    goodDir[newr][newc][3 - i] = -1;
                }
            }
        }
    }
}

void PrintBFS()
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << i << " " << j << ": " << dist[i][j] << " ";
            for (int k = 0; k < 4; k++)
            {
                if (goodDir[i][j][k] == 1)
                    cout << dirStr[k];
            }
            cout << endl;
        }
    }
}

void PrintRobots()
{
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << robots[i].first << " " << robots[i].second << endl;
    }
}

void MoveAll(int i)
{
    for (int j = 0; j < n; j++)
    {
        if (robots[j] == entrance)
            continue;
        int newr = robots[j].first + dir[i].first;
        int newc = robots[j].second + dir[i].second;
        //cout << newr << " " << newc << endl;
        if (newr >= 0 && newr < r && newc >= 0 && newc < c && maze[newr][newc] != 'X')
        {
            //cout << 'a' << endl;
            robots[j] = {newr, newc};
        }
    }
}

int main()
{
    string caseNum = "2";
    string inputFile = "robotrecovery" + caseNum + ".txt";
    string outputFile = "output" + caseNum + ".txt";
    freopen(inputFile.c_str(), "r", stdin);

    cin >> r >> c >> n;

    for (int i = 0; i < r; i++)
    {
        cin >> maze[i];
        for (int j = 0; j < c; j++)
        {
            if (maze[i][j] == 'E')
                entrance = {i, j};
            else if (maze[i][j] == 'R')
                robots.push_back({i, j});
        }
    }

    bfs();

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (dist[i][j] == -1)
                cout << '-';
            else if (dist[i][j] == 0)
                cout << 'E';
            else
            {
                //cout << dist[i][j] % 10;
                for (int k = 0; k < 4; k++)
                {
                    if (goodDir[i][j][k] == 1)
                    {
                        cout << dirStr[k];
                        break;
                    }
                }
            }

        }
        if (i == entrance.first)
            cout << "e";
        cout << endl;
    }

    while (true)
    {
        int farRobot = -1;
        int closeRobot = -1;
        int netDistChange[4];
        bool hasGood[4];
        for (int i = 0; i < 4; i++)
            netDistChange[i] = 0;

        bool done = true;
        for (int i = 0; i < n; i++)
        {
            if (robots[i] == entrance)
                continue;
            done = false;
            if (farRobot == -1 || dist[robots[i].first][robots[i].second] > dist[robots[farRobot].first][robots[farRobot].second])
            {
                farRobot = i;
            }
            if (closeRobot == -1 || dist[robots[i].first][robots[i].second] < dist[robots[closeRobot].first][robots[closeRobot].second])
            {
                closeRobot = i;
            }

            for (int j = 0; j < 4; j++)
            {
                netDistChange[j] += goodDir[robots[i].first][robots[i].second][j];
                if (goodDir[robots[i].first][robots[i].second][j] == 1)
                    hasGood[j] = true;
            }
        }
        if (done)
            break;

        int maxDir = -1;
        for (int i = 0; i < 4; i++)
        {
            //if (maxDir == -1 || (goodDir[robots[farRobot].first][robots[farRobot].second][i] && (numGood[i] > numGood[maxDir])))
            if (hasGood[i] && (maxDir == -1 || netDistChange[i] > netDistChange[maxDir]))
            {
                maxDir = i;
            }
//            if (goodDir[robots[closeRobot].first][robots[closeRobot].second][i])
//                maxDir = i;
        }
        cout << maxDir << " " << hasGood[maxDir] << " " << netDistChange[maxDir] << endl;
        ans.push_back(maxDir);
        MoveAll(maxDir);
        PrintRobots();
    }

    ofstream fout;
    fout.open(outputFile);
    for (int a : ans)
    {
        fout << dirStr[a];
    }
    fout << endl;
    fout.close();
}
