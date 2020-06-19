#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int bit[1000];

int getmax(int r) {
    int ret = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1)
        ret = max(ret, bit[r]);
    return ret;
}

void update(int idx, int val) {
    for (; idx < 1000; idx = idx | (idx + 1))
        bit[idx] = max(bit[idx], val);
}

int main() {
    update(0, 11);
    update(1, 100);
    cout << getmax(1) << endl;
}
