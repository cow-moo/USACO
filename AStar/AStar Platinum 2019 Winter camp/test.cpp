#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

int n = 1000;
int bit[1000];

int sum(int r) {
    int ret = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1)
        ret += bit[r];
    return ret;
}

int sum(int l, int r) {
    return sum(r) - sum(l - 1);
}

void add(int idx, int delta) {
    for (; idx < n; idx = idx | (idx + 1))
        bit[idx] += delta;
}

int main() {
    add(5, 3);
    add(4, 2);
    cout << sum(5, 5) << endl;
}
//101
