#include <iostream>
using namespace std;

int bit[100050];

void add(int idx, int delta) {
    for (; idx < 100050; idx = idx | (idx + 1))
        bit[idx] += delta;
}

int sum(int r) {
    int ret = 0;
    for (--r; r >= 0; r = (r & (r + 1)) - 1)
        ret += bit[r];
    return ret;
}

int convert[100050];
int side2[100050];
int pos2[100050];
//gives pos of cow i on side2

int main() {
    int n;
    cin >> n;

    int inp;
    for (int i = n - 1; i >= 0; i--) {
        cin >> inp;
        convert[inp - 1] = i;
    }
    for (int i = 0; i < n; i++) {
        cin >> inp;
        side2[n - 1 - i] = convert[inp - 1];
        pos2[side2[n - 1 - i]] = n - 1 - i;
    }

    long long interCount = 0;
    for (int i = n - 1; i >= 0; i--) {
        interCount += sum(pos2[i]);
        add(pos2[i], 1);
    }

    long long ans = interCount;
    for (int i = 0; i < n; i++) {
        interCount += n - 1 - 2 * side2[i];
        ans = min(ans, interCount);
    }
    for (int i = 0; i < n; i++) {
        interCount += n - 1 - 2 * pos2[i];
        ans = min(ans, interCount);
    }

    cout << ans << endl;
}
