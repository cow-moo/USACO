#include <iostream>
#include <stdio.h>
using namespace std;

int tiles[255],boots[255][2];
bool reachable[255]; //if tile i is reachable at point in time (with boots j)

int main() {
    freopen("snowboots.in","r",stdin);
    freopen("snowboots.out","w",stdout);
    int n, b, curPos = 0;
    cin >> n >> b;
    for (int i = 0; i < n; i++) {
        cin >> tiles[i];
    }
    for (int i = 0; i < b; i++) {
        cin >> boots[i][0] >> boots[i][1];
    }

    reachable[0] = true;

    for (int i = 0; i < b; i++) {
        for (int pos = 0; pos < n; pos++) {
            if (reachable[pos] && boots[i][0] >= tiles[pos]) { //if can use boots here
                for (int newPos = pos + 1; newPos < min(pos + boots[i][1] + 1, n); newPos++) {
                    if (boots[i][0] >= tiles[newPos]) {
                        reachable[newPos] = true;
                    }
                }
            }
        }
        if (reachable[n - 1]) {
            cout << i << endl;
            break;
        }

        /*
        if (boots[i][0] < tiles[curPos]) {
            continue;
        }
        for (int j = min(curPos + boots[i][1], n - 1); j > curPos; j--) {
        //for (int j = curPos; j < min(curPos + boots[i][1], n); j++) {
            //cout << i << " range: " << curPos + 1 << " to " << j << endl;
            if (boots[i][0] >= tiles[j]) {
                //cout << i << " step: " << curPos << " to " << j << endl;
                curPos = j;
                j = min(curPos + boots[i][1], n - 1) + 1;
                //break;
            }
        }
        if (curPos == n - 1) {
            cout << i << endl;
            break;
        }
        */
    }
}
