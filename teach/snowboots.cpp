#include <iostream>
#include <stdio.h>
using namespace std;

int n, b, ans = 1000000;
int snow[255];
int boots[255][2];

void recurse(int curBoot, int curPos) {
    //cout << curBoot << " " << curPos << endl;
    if (curPos == n - 1) {
        ans = min(ans, curBoot);
        return;
    }
    for (int i = curBoot + 1; i < b; i++) {
        //cout << i << endl;
        if (boots[i][0] >= snow[curPos])
            recurse(i, curPos);
    }
    for (int i = curPos + 1; i <= min(curPos + boots[curBoot][1], n - 1); i++) {
        if (boots[curBoot][0] >= snow[i])
            recurse(curBoot, i);
    }
}

int main() {
    freopen("snowboots.in", "r", stdin);
    freopen("snowboots.out", "w", stdout);

    cin >> n >> b;

    for (int i = 0; i < n; i++) {
        cin >> snow[i];
    }
    for (int i = 0; i < b; i++) {
        cin >> boots[i][0] >> boots[i][1];
    }

    recurse(0, 0);
    cout << ans << endl;
}
//O(nb) states
//O(n + b) transitions
//O(nnb + nbb)
