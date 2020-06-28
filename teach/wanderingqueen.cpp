#include <iostream>
#include <queue>
using namespace std;

struct Event{
    int i, j;
    //1 = horiz, 2 = vert, 3 = upright, 4 = downright
    int prevDir, d;
};

string board[1050];
//int dist[1050][1050];
bool visited[1050][1050];

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, m;
        cin >> n >> m;

        int si, sj;//, fi, fj;
        for (int i = 0; i < n; i++) {
            cin >> board[i];
            for (int j = 0; j < m; j++) {
                //dist[i][j] = -1;
                visited[i][j] = false;
                if (board[i][j] == 'S') {
                    si = i; sj = j;
                }
//                else if (board[i][j] == 'F') {
//                    fi = i; fj = j;
//                }
            }
        }

        bool found = false;
        queue<Event> q;
        q.push({si, sj, 0, 0});
        while (!q.empty()) {
            Event e = q.front();
            q.pop();
            if (board[e.i][e.j] == 'F') {
                cout << e.d << endl;
                found = true;
                break;
            }
            //if (dist[e.i][e.j] == -1)
            //    dist[e.i][e.j] == e.d;
            if (visited[e.i][e.j] == false)
                visited[e.i][e.j] = true;
            else
                continue;
            if (e.prevDir != 1) {
                for (int j = e.j + 1; j < m; j++) {
                    if (board[e.i][j] == 'X')
                        break;
                    q.push({e.i, j, 1, e.d + 1});
                }
                for (int j = e.j - 1; j >= 0; j--) {
                    if (board[e.i][j] == 'X')
                        break;
                    q.push({e.i, j, 1, e.d + 1});
                }
            }
            if (e.prevDir != 2) {
                for (int i = e.i + 1; i < n; i++) {
                    if (board[i][e.j] == 'X')
                        break;
                    q.push({i, e.j, 2, e.d + 1});
                }
                for (int i = e.i - 1; i >= 0; i--) {
                    if (board[i][e.j] == 'X')
                        break;
                    q.push({i, e.j, 2, e.d + 1});
                }
            }
            if (e.prevDir != 3) {
                for (int x = 1; e.i + x < n && e.j - x >= 0; x++) {
                    if (board[e.i + x][e.j - x] == 'X')
                        break;
                    q.push({e.i + x, e.j - x, 3, e.d + 1});
                }
                for (int x = -1; e.i + x >= 0 && e.j - x < m; x--) {
                    if (board[e.i + x][e.j - x] == 'X')
                        break;
                    q.push({e.i + x, e.j - x, 3, e.d + 1});
                }
            }
            if (e.prevDir != 4) {
                for (int x = 1; e.i + x < n && e.j + x < m; x++) {
                    if (board[e.i + x][e.j + x] == 'X')
                        break;
                    q.push({e.i + x, e.j + x, 4, e.d + 1});
                }
                for (int x = -1; e.i + x >= 0 && e.j + x >= 0; x--) {
                    if (board[e.i + x][e.j + x] == 'X')
                        break;
                    q.push({e.i + x, e.j + x, 4, e.d + 1});
                }
            }
        }
        if (found == false)
            cout << -1 << endl;
    }
}
