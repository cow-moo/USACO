#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
#define MAXN 100000
#define MAXM 50000

vector<pair<int, int>> edges[MAXM];
vector<int> succ[MAXN];
int pred[MAXN];
int result[MAXN];
int n;

bool doable(int k) {
    for (int i = 0; i < n; i++) {
        succ[i].clear();
        pred[i] = 0;
    }
    for (int i = 0; i < k; i++) {
        for (pair<int, int> p : edges[i]) {
            succ[p.first].push_back(p.second);
            pred[p.second]++;
        }
    }

    priority_queue<int> q;
    for (int i = 0; i < n; i++) {
        if (pred[i] == 0) {
            q.push(-i);
        }
    }

    for (int i = 0; i < n; i++) {
        if (q.empty()) {
            return false;
        }
        int v = -q.top();
        result[i] = v;
        q.pop();
        for (int next : succ[v]) {
            pred[next]--;
            if (pred[next] == 0) {
                q.push(-next);
            }
        }
    }

    return true;
}


int main() {
    freopen("milkorder.in", "r", stdin);
    freopen("milkorder.out", "w", stdout);

    int m;
    cin >> n >> m;

    int M_i, a, b;
    for (int i = 0; i < m; i++) {
        cin >> M_i;
        for (int j = 0; j < M_i; j++) {
            cin >> b;
            b--;
            if (j > 0) {
                edges[i].push_back(make_pair(a, b));
            }
            a = b;
        }
    }

    //low <= ans < high
    int low = 0, high = m + 1;
    while (high > low + 1) {
        int mid = (low + high) / 2;
        if (doable(mid)) {
            low = mid;
        }
        else {
            high = mid;
        }
    }

    doable(low);
    for (int i = 0; i < n - 1; i++) {
        cout << result[i] + 1 << " ";
    }
    cout << result[n - 1] + 1;
}
