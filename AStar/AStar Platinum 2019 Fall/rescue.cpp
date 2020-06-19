#include <iostream>
using namespace std;

int starti, startj;

int dist(int exiti, int exitj) {
    if (exiti <= starti && (exitj + 1) / 2 >= (startj + 1) / 2) {
        return (starti - exiti) * 2 + exitj - startj;
    }
    else if (exiti > starti && (exitj + 1) / 2 <= (startj + 1) / 2) {
        return (exiti - starti) * 2 + startj - exitj;
    }
    else if (exiti > starti && (exitj + 1) / 2 > (startj + 1) / 2) {
        return (exiti - starti) * 2 - (startj % 2) + (exitj % 2) + max(0, exitj - startj - (exiti - starti) * 2 + (startj % 2));
    }
    else {
        return (starti - exiti) * 2 - (exitj % 2) + (startj % 2) + max(0, startj - exitj - (starti - exiti) * 2 + (exitj % 2));
    }
}

int main() {
    int n, m;
    cin >> n >> m >> starti >> startj;

    //aka min time to reach (but not exit)
    int minDist = 10000000, mini = 10000000, minj = 10000000;
    for (int i = 0; i < m; i++) {
        int exiti, exitj;
        cin >> exiti >> exitj;

        int exitDist = dist(exiti, exitj);

        if (exitDist < minDist || (exitDist == minDist && (exiti < mini || (exiti == mini && exitj < minj)))) {
            minDist = exitDist;
            mini = exiti;
            minj = exitj;
        }
    }

    cout << mini << " " << minj << endl << minDist + 1 << endl;
}
/*
5000 1
1018 1865
1085 2015

*/
