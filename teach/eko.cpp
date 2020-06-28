#include <iostream>
#include <algorithm>
using namespace std;

long long n, m;

int trees[1000005];
long long pre[1000005];

bool check(long long h) {
    int tree = upper_bound(trees, trees + n, h) - trees;
    return pre[tree] - (n - tree) * h >= m;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> trees[i];
        pre[0] += trees[i];
    }

    sort(trees, trees + n);

    //stores sum of i to end inclusive
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] - trees[i - 1];
    }

    //last one such that check(i) = true
    //l <= ans <= r
    long long l = 0, r = 1000000000, mid;
    while (l < r) {
        mid = (l + r + 1) / 2;
        if (check(mid)) {
            l = mid;
        }
        else {
            r = mid - 1;
        }
        //cout << l << " " << r << endl;
    }
    cout << l << endl;
}
