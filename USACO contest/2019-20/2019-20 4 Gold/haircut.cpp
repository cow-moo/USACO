#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
#define MAXN 100050

vector<int> hairPos[MAXN];
int bit[MAXN];

int sum(int r) {
    int ret = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1)
        ret += bit[r];
    return ret;
}

void add(int idx, int delta) {
    idx++;
    for (; idx < MAXN; idx = idx | (idx + 1))
        bit[idx] += delta;
}

int main() {
    freopen("haircut.in", "r", stdin);
    freopen("haircut.out", "w", stdout);

    int n;
    cin >> n;

    int inp;
    for (int i = 0; i < n ; i++) {
        cin >> inp;
        hairPos[inp].push_back(i);
    }

    for (int i = 0; i < n; i++) {
        add(i, 1);
    }
//    for (int i = 0; i < n; i++) {
//        cout << sum(i) << endl;
//    }
    long long badness = 0;
    cout << badness << endl;

    for (int i = 0; i < n - 1; i++) {
        for (int index : hairPos[i]) {
            add(index, -1);
        }
        for (int index : hairPos[i]) {
            badness += sum(index);
        }
        cout << badness << endl;
    }
}
