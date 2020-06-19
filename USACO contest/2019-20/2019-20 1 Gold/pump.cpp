#include <iostream>
#include <stdio.h>
#include <tuple>
#include <algorithm>
#include <queue>
using namespace std;
#define MAXN 1000
#define MAXM 1000

tuple<int, int, int, int> edges[MAXM]; //flow rate, cost, a, b
vector<pair<int, int>> adj[MAXN]; //node, cost

priority_queue<pair<int, int>> q; //-cost, node
int dist[MAXN];

int main() {
    freopen("pump.in", "r", stdin);
    freopen("pump.out", "w", stdout);

    int n, m, maxSol = 0;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> get<2>(edges[i]) >> get<3>(edges[i]) >> get<1>(edges[i]) >> get<0>(edges[i]);
        get<2>(edges[i])--;
        get<3>(edges[i])--;
    }

    sort(edges, edges + m);

    for (int i = m - 1; i >=0; i--) {
        adj[get<2>(edges[i])].push_back(make_pair(get<3>(edges[i]), get<1>(edges[i])));
        adj[get<3>(edges[i])].push_back(make_pair(get<2>(edges[i]), get<1>(edges[i])));

        for (int j = 0; j < n; j++) {
            dist[j] = -1;
        }

        q.push(make_pair(0, 0));
        while (!q.empty()) {
            pair<int, int> n = q.top();
            q.pop();
            n.first *= -1;
            if (dist[n.second] != -1)
                continue;
            dist[n.second] = n.first;
            for (auto neighbor : adj[n.second]) {
                if (dist[neighbor.first] == -1) {
                    q.push(make_pair(-(n.first + neighbor.second), neighbor.first));
                }
            }
        }

        if (dist[n - 1] != -1) {
            maxSol = max(maxSol, 1000000 * get<0>(edges[i]) / dist[n - 1]);
        }
        //cout << get<0>(edges[i]) << endl;
    }
    cout << maxSol << endl;
//    for (int i = 0; i < n; i++) {
//        for (auto a : adj[i]) {
//            cout << i << " " << a.first << " " << a.second << endl;
//        }
//    }
}
