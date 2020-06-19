#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define MAXN 100050

int dates[MAXN];
vector<pair<int, int> > adj[MAXN];

bool visited[MAXN];
vector<int> topoSort;

void dfs(int v) {
    visited[v] = true;
    for (pair<int, int> u : adj[v]) {
        if (!visited[u.first])
            dfs(u.first);
    }
    topoSort.push_back(v);
}

int main() {
    freopen("timeline.in", "r", stdin);
    freopen("timeline.out", "w", stdout);

    int n, m, c;
    cin >> n >> m >> c;

    for (int i = 0; i < n; i++) {
        cin >> dates[i];
    }

    int inp1, inp2, inp3;
    for (int i = 0; i < c; i++) {
        cin >> inp1 >> inp2 >> inp3;
        adj[inp1 - 1].push_back({inp2 - 1, inp3});
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i])
            dfs(i);
    }
    reverse(topoSort.begin(), topoSort.end());

    for (int v : topoSort) {
        for (pair<int, int> u : adj[v]) {
            dates[u.first] = max(dates[u.first], dates[v] + u.second);
        }
    }

    for (int i = 0; i < n; i++) {
        cout << dates[i] << endl;
    }
}
