#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAXN 100050
#define MOD 1000000007

int n;

long long powers[MAXN];
int segEnds[MAXN];
int bit[MAXN * 2];

int sum(int r) {
    r = n * 2 - r;
    int ret = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1)
        ret += bit[r];
    return ret;
}

void add(int idx, int delta) {
    idx = n * 2 - idx;
    for (; idx < MAXN * 2; idx = idx | (idx + 1))
        bit[idx] += delta;
}

int main() {
    freopen("help.in", "r", stdin);
    freopen("help.out", "w", stdout);

    cin >> n;

    powers[0] = 1;
    for (int i = 1; i <= n; i++) {
        powers[i] = powers[i - 1] * 2;
        if (powers[i] > MOD)
            powers[i] -= MOD;
    }

    int start;
    for (int i = 0; i < n; i++) {
        cin >> start >> segEnds[i];
        add(start, 1);
        //cout << beg << endl;
    }

    sort(segEnds, segEnds + n);

    long long ans = powers[n] - 1;
    for (int i = 0; i < n; i++) {
        //cout << segEnds[i] << endl;
        ans += powers[i] * (powers[sum(segEnds[i])] - 1);
        ans %= MOD;
    }

    cout << ans << endl;

//    for (int i = 1; i <= 2 * n; i++) {
//        cout << i << " " << sum(i) << endl;
//    }
}
