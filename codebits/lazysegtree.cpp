#include <iostream>
using namespace std;

//stores sum of its range including addends
int tree[400000];
//stores addend that needs to be added to children
int lazy[400000];
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

void push(int v, int tl, int tr) {
    int tm = (tl + tr) / 2;
    tree[v * 2] += (tm - tl + 1) * lazy[v];
    lazy[v * 2] += lazy[v];

    tree[v * 2 + 1] += (tr - tm) * lazy[v];
    lazy[v * 2 + 1] += lazy[v];

    lazy[v] = 0;
}

void updateRange(int v, int tl, int tr, int l, int r, int addend) {
    if (l > r)
        return;
    if (l == tl && r == tr) {
        lazy[v] += addend;
        tree[v] += (tr - tl + 1) * addend;
    }
    else {
        if (lazy[v] != 0 && tl != tr)
            push(v, tl, tr);
        int tm = (tl + tr) / 2;
        updateRange(v * 2, tl, tm, l, min(r, tm), addend);
        updateRange(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, addend);

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
    if (lazy[v] != 0 && tl != tr)
        push(v, tl, tr);
    int tm = (tl + tr) / 2;
    return sum(v * 2, tl, tm, l, min(r, tm)) + sum(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    build(1, 0, n - 1);

    cout << sum(1, 0, n - 1, 0, 2) << endl;
    updateRange(1, 0, n - 1, 1, 2, 1);
}
