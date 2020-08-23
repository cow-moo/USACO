#include <iostream>
using namespace std;

int bit[1000050];

int sum(int r) {
    int ret = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1)
        ret += bit[r];
    return ret;
}

void add(int idx, int delta) {
    for (; idx <= 1000050; idx = idx | (idx + 1))
        bit[idx] += delta;
}

int main() {
    int n;
    cin >> n;

    int l, u;
    for (int i = 0; i < n; i++) {
        cin >> l >> u;
        add(l, 1);
        add(u + 1, -1);
    }
    int maxim = 0, maxPos;
    for (int i = 0; i <= 1000000; i++) {
        if (sum(i) > maxim) {
            maxim = sum(i);
            maxPos = i;
        }
    }
    cout << maxPos << endl;
}
