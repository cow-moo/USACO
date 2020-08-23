#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

pair<int, int> favorites[155];
int pastures[105];
bool impossible[105][5];

int main() {
    freopen("revegetate.in", "r", stdin);
    freopen("revegetate.out", "w", stdout);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> favorites[i].first >> favorites[i].second;
        if (favorites[i].first > favorites[i].second) {
            swap(favorites[i].first, favorites[i].second);
        }
    }
    sort(favorites, favorites + m);
//    cout << endl;
//    for (int i = 0; i < m; i++) {
//        cout << favorites[i].first << " " << favorites[i].second << endl;
//    }

    for (int i = 0; i < m; i++) {
        if (pastures[favorites[i].first] == 0) {
            for (int j = 1; j <= 4; j++) {
                if (!impossible[favorites[i].first][j]) {
                    pastures[favorites[i].first] = j;
                    break;
                }
            }
        }
        impossible[favorites[i].second][pastures[favorites[i].first]] = 1;

        //cout << pastures[favorites[12].first] << " " << pastures[favorites[12].second] << endl;
    }

//    cout << favorites[12].first << " " << favorites[12].second << endl;
//    cout << pastures[favorites[12].first] << " " << pastures[favorites[12].second] << endl;

//    for (int i = 0; i < n; i++) {
//        for (int j = 1; j <= 4; j++) {
//            cout << impossible[i][j] << " ";
//        }
//        cout << endl;
//    }

    for (int i = 1; i <= n; i++) {
        if (pastures[i] == 0) {
            for (int j = 1; j <= 4; j++) {
                if (!impossible[i][j]) {
                    pastures[i] = j;
                    break;
                }
            }
        }
        cout << pastures[i];
    }
}
/*
1 8 good
1 17 good
1 19 good
2 6 good
2 8 good
2 22 good
4 20 1 2
4 22 1 2
4 23 1 2
5 8 1 2
5 13 1 2
5 14 1 2
6 15 2 3
7 9 1 2
7 13 1 2
7 24 1 3
9 16
9 21
10 12
10 15
12 16
12 24
15 25
16 25
17 19
18 20
19 21
20 25
22 24

1 2 3 4 5 6 7 8 910111213141516171819202122232425
1 1 1 1 1 2 1 2 2 1 1 2 2 2 2 1 2 1 3 2 1 2 2 3 3
1 1 1 1 1 2 1 2 2 1 1 2 2 2 3 1 2 1 3 2 1 2 2 3 4
*/
