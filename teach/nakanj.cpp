#include <iostream>
#include <queue>
using namespace std;

bool visited[10][10];
pair<int, int> disp[8] = {{1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}};

//pair<int, int> operator+(pair<int, int> a, pair<int, int> b) {
//    return {a.first + b.first, a.second + b.second};
//}

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        pair<int, int> start, dest;

        string str;
        cin >> str;
        start.first = str[0] - 'a';
        start.second = str[1] - '1';

        cin >> str;
        dest.first = str[0] - 'a';
        dest.second = str[1] - '1';

        if (start == dest) {
            cout << 0 << endl;
            continue;
        }
                    //pos, dist
        queue<pair<pair<int, int>, int> > q;
        q.push({start, 0});

        bool done = false;
        while (!q.empty() && !done) {
            pair<int, int> curPos = q.front().first;
            int curDist = q.front().second;
            q.pop();

            for (int i = 0; i < 8; i++) {
                pair<int, int> neighbor = {curPos.first + disp[i].first, curPos.second + disp[i].second};
                if (neighbor.first >= 0 && neighbor.first < 8 && neighbor.second >= 0 && neighbor.second < 8 &&
                    !visited[neighbor.first][neighbor.second]) {
                    if (neighbor == dest) {
                        cout << curDist + 1 << endl;
                        done = true;
                        break;
                    }
                    q.push({neighbor, curDist + 1});
                    visited[neighbor.first][neighbor.second] = true;
                }
            }
        }

        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                visited[i][j] = false;
            }
        }
    }
}
