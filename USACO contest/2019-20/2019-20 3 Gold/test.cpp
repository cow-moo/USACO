#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAXN 100050
#define MOD 1000000007

int bit[MAXN * 2];

int sum(int r) {
    //r = n * 2 - r;
    int ret = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1)
        ret += bit[r];
    return ret;
}

void add(int idx, int delta) {
    //idx = n * 2 - idx;
    for (; idx < MAXN; idx = idx | (idx + 1))
        bit[idx] += delta;
}

int main() {

    for (int i = 1; i <= 2 * n; i++) {
        cout << i << " " << sum(i) << endl;
    }
}

