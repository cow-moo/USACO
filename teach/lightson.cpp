#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;
#define MAXN 105

bool visited[MAXN][MAXN]; //stores if you've been to this square and pressed the switches
bool lit[MAXN][MAXN];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int n;

vector<pair<int, int> > switches[MAXN][MAXN];

void recurse(int x, int y) {
    visited[x][y] = true;

    for (pair<int, int> room : switches[x][y]) {
        lit[room.first][room.second] = true;
        for (int i = 0; i < 4; i++) {
            if (room.first + dir[i][0] >= 0 && room.first + dir[i][0] < n
                && room.second + dir[i][1] >= 0 && room.second + dir[i][1] < n
                && visited[room.first + dir[i][0]][room.second + dir[i][1]]
                && !visited[room.first][room.second]) {
                recurse(room.first, room.second);
                break;
            }
        }
    }

    for (int i = 0; i < 4; i++) {
        if (x + dir[i][0] >= 0 && x + dir[i][0] < n
            && y + dir[i][1] >= 0 && y + dir[i][1] < n
            && lit[x + dir[i][0]][y + dir[i][1]]
            && !visited[x + dir[i][0]][y + dir[i][1]]) {
            recurse(x + dir[i][0], y + dir[i][1]);
        }
    }
}

int main() {
    freopen("lightson.in", "r", stdin);
    freopen("lightson.out", "w", stdout);

    int m;
    cin >> n >> m;

    int x, y, a, b;
    for (int i = 0; i < m; i++) {
        cin >> x >> y >> a >> b;
        switches[x - 1][y - 1].push_back({a - 1, b - 1});
    }

    lit[0][0] = true;

    recurse(0, 0);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans += lit[i][j];
        }
    }

    cout << ans << endl;
}
