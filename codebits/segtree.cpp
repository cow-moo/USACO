#include <iostream>
using namespace std;

int tree[400000];
int arr[100000];

void build(int v, int tl, int tr) {
    if (tl == tr) {
        tree[v] = arr[tl];
    }
    else {
        int tm = (tl + tr) / 2;
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm + 1, tr);
        tree[v] = tree[v * 2] + tree[v * 2 + 1];
    }
}

int sum(int v, int tl, int tr, int l, int r) {
    if (l > r) {
        return 0;
    }
    if (l == tl && r == tr) {
        return tree[v];
    }
    int tm = (tl + tr) / 2;
    return sum(v * 2, tl, tm, l, min(r, tm)) + sum(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
}

void update(int v, int tl, int tr, int pos, int newVal) {
    if (tl == tr) {
        tree[v] = newVal;
    }
    else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v * 2, tl, tm, pos, newVal);
        else
            update(v * 2 + 1, tm + 1, tr, pos, newVal);
        tree[v] = tree[v * 2] + tree[v * 2 + 1];
    }
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    build(1, 0, n - 1);

//    cout << sum(1, 0, n - 1, 1, 6) << endl;
//    update(1, 0, n - 1, 3, 5);
//    cout << sum(1, 0, n - 1, 1, 6) << endl;
}
