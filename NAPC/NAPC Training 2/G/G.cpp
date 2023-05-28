#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <iterator>
#include <optional>
#include <numeric>
#include <tuple>
using namespace std;
using ll = long long;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> adj(n, vector<int>());
    vector<vector<int>> adj_inv(n, vector<int>());
    vector<int> irons(n);
    for (int i=0;i<m;i++) {
        int u;
        cin >> u;
        --u;
        irons[u] = true;
    }
    vector<int> coals(n);
    for (int i=0;i<k;i++){
        int u;
        cin >> u;
        --u;
        coals[u] = true;
    }
    for (int u=0;u<n;u++) {
        int c;
        cin >> c;
        while (c--) {
            int v;
            cin >> v;
            --v;
            adj[u].push_back(v);
            adj_inv[v].push_back(u);
        }
    }
    const int inf = 1e8;
    queue<tuple<int,int,int>> q;
    vector<vector<vector<int>>> dist(n, vector<vector<int>>(2, vector<int>(2,inf)));
    for (int i=0;i<n;i++){
        if (coals[i] || irons[i]) {
            q.push({i, coals[i], irons[i]});
            dist[i][coals[i]][irons[i]] = 0;
        }
    }
    while (!q.empty()) {
        auto [u, c, i] = q.front();
        q.pop();
        for (int v : adj_inv[u]) {
            int nc = c | coals[v];
            int ni = i | irons[v];
            if (dist[v][nc][ni] == inf) {
                dist[v][nc][ni] = dist[u][c][i] + 1;
                q.push({v,nc,ni});
            }
        }
    }
    q.push({0,0,0});
    dist[0][0][0] = 0;
    while (!q.empty()) {
        auto [u, _,__] = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (dist[v][0][0] == inf) {
                dist[v][0][0] = dist[u][0][0] + 1;
                q.push({v,0,0});
            }
        }
    }

    // for (int j=0;j<2;j++){
    //     for(int z=0;z<2;z++){
    //         for (int i=0;i<n;i++){
    //             cout << dist[i][j][z] << " ";
    //         }
    //         cout << "\n";
    //     }
    // }

    int ans = inf;
    for (int i=0;i<n;i++){
        ans = min(ans, dist[i][0][0] + dist[i][1][1]);
        for (int u : adj[i]) {
            for (int v : adj[i]) {
                ans = min(ans, dist[i][0][0] + 2 + dist[u][1][0] + dist[v][0][1]);
            }
        }
    }
    if (ans == inf) {
        cout << "impossible" << "\n";
    } else {
        cout << ans << "\n";
    }
}