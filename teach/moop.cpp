#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

pair<int, int> pos[100005];

int main() {
    freopen("moop.in", "r", stdin);
    freopen("moop.out", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> pos[i].first >> pos[i].second;
    }

    sort(pos, pos + n);
//    cout << endl;
//    for (int i = 0; i < n; i++) {
//        cout << pos[i].first << " " << pos[i].second << endl;
//    }

    int ans = 0, curMin = 2000000000;
    for (int i = 0; i < n; i++) {
        int maxY = i;
        for (; maxY <= n; maxY++) {
            if (maxY == n || pos[maxY].first != pos[i].first) {
                maxY--;
                break;
            }
        }
        //cout << i << ", " << maxY << endl;
        if (pos[maxY].second >= curMin) {
            curMin = min(curMin, pos[i].second);
        }
        else {
            ans++;
            curMin = pos[i].second;
        }
    }

    cout << ans << endl;
}
