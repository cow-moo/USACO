#include <iostream>
using namespace std;
#define INF 1000000000
#define MAXN 200000

//stores sum of its range including addends, min in range including addends
pair<long long, long long> tree[MAXN * 4];
//stores addend that needs to be added to children
long long lazy[MAXN * 4];
int arr[MAXN];

void build(int v, int tl, int tr) {
    if (tl == tr) {
        tree[v].first = arr[tl];
        tree[v].second = arr[tl];
    }
    else {
        int tm = (tl + tr) / 2;
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm + 1, tr);
        tree[v].first = tree[v * 2].first + tree[v * 2 + 1].first;
        tree[v].second = min(tree[v * 2].second, tree[v * 2 + 1].second);
    }
}

void push(int v, int tl, int tr) {
    int tm = (tl + tr) / 2;

    tree[v * 2].first += (tm - tl + 1) * lazy[v];
    tree[v * 2].second += lazy[v];
    lazy[v * 2] += lazy[v];

    tree[v * 2 + 1].first += (tr - tm) * lazy[v];
    tree[v * 2 + 1].second += lazy[v];
    lazy[v * 2 + 1] += lazy[v];

    lazy[v] = 0;
}

void updateRange(int v, int tl, int tr, int l, int r, long long addend) {
    if (l > r)
        return;
    if (l == tl && r == tr) {
        tree[v].first += (tr - tl + 1) * addend;
        tree[v].second += addend;
        lazy[v] += addend;
    }
    else {
        if (lazy[v] != 0 && tl != tr)
            push(v, tl, tr);
        int tm = (tl + tr) / 2;
        updateRange(v * 2, tl, tm, l, min(r, tm), addend);
        updateRange(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, addend);

        tree[v].first = tree[v * 2].first + tree[v * 2 + 1].first;
        tree[v].second = min(tree[v * 2].second, tree[v * 2 + 1].second);
    }
}

long long sum(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return 0;

    if (l == tl && r == tr) {
        return tree[v].first;
    }
    if (lazy[v] != 0 && tl != tr)
        push(v, tl, tr);
    int tm = (tl + tr) / 2;
    return sum(v * 2, tl, tm, l, min(r, tm)) + sum(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
}

long long minim(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return INF;

    if (l == tl && r == tr) {
        return tree[v].second;
    }
    if (lazy[v] != 0 && tl != tr)
        push(v, tl, tr);
    int tm = (tl + tr) / 2;
    return min(minim(v * 2, tl, tm, l, min(r, tm)), minim(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}

int main() {
    int n, q;
    cin >> n >> q;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    build(1, 0, n - 1);

    char inp1;
    int inp2, inp3;
    long long inp4;
    for (int i = 0; i < q; i++) {
        cin >> inp1 >> inp2 >> inp3;
        inp2--; inp3--;
        if (inp1 == 'M') {
            cout << minim(1, 0, n - 1, inp2, inp3) << endl;
        }
        if (inp1 == 'P') {
            cin >> inp4;
            updateRange(1, 0, n - 1, inp2, inp3, inp4);
        }
        if (inp1 == 'S') {
            cout << sum(1, 0, n - 1, inp2, inp3) << endl;
        }
    }
}

