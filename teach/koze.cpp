#include <iostream>
using namespace std;

string field[255];
bool visited[255][255];

int n, m;
int sheep = 0, wolves = 0;
bool backyard = false;
int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void recurse(int curx, int cury) {
    visited[cury][curx] = true;
    if (field[cury][curx] == 'k')
        sheep++;
    else if (field[cury][curx] == 'v')
        wolves++;
    for (int i = 0; i < 4; i++) {
        int newx = curx + dir[i][0];
        int newy = cury + dir[i][1];
        if (newx < m && newx >= 0 && newy < n && newy >= 0) {
            if (field[newy][newx] == '#' || visited[newy][newx])
                continue;
            recurse(newx, newy);
        }
        else {
            backyard = true;
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> field[i];
    }

    int sheepCount = 0, wolfCount = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && field[i][j] != '#') {
                sheep = 0; wolves = 0; backyard = false;
                recurse(i, j);

                //cout << sheep << " " << wolves << endl;
                if (backyard)
                    continue;
                if (sheep > wolves)
                    sheepCount += sheep;
                else
                    wolfCount += wolves;
            }
        }
    }

    cout << sheepCount << " " << wolfCount;
}
