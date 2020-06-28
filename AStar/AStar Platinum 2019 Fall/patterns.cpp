#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
#define EXP 10000019

int n, k;
int milk[20005];

struct Range {
    int *s, *e;
    size_t h;
};

struct Equal {
    bool operator()(const Range &a, const Range &b) const {
        return (a.h == b.h && equal(a.s, a.e, b.s));
    }
};

struct Hash {
    size_t operator()(const Range &a) const {
        return a.h;
    }
};

bool check(int length) {
    Range cur = {milk, milk + length, 0};
    unordered_map<Range, int, Hash, Equal> hsh;

    size_t expl = 1;
    for (int i = 0; i < length; i++) {
        expl *= EXP;
        cur.h = cur.h * EXP + milk[i];
    }

    for (int i = 0; i + length <= n; i++) {
        if (++hsh[cur] >= k)
            return true;
        cur.h = cur.h * EXP - expl * milk[i] + milk[i + length];
        cur.s++;
        cur.e++;
    }
    return false;
}

int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> milk[i];
    }

    //l <= mid <= r
    int l = 1, r = n, mid;
    while (l < r) {
        mid = r - (r - l) / 2;
        if (check(mid)) {
            l = mid;
        }
        else {
            r = mid - 1;
        }
    }
    cout << l << endl;
}
