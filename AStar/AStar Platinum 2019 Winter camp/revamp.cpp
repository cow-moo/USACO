#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 1000000000

vector<pair<int, int> > adj[10050];
int minDist[10050][25];
//minDist[i][j] is min dist to each node i having used j free trails

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    int inp1, inp2, inp3;
    for (int i = 0; i < m; i++) {
        cin >> inp1 >> inp2 >> inp3;
        adj[inp1 - 1].push_back({inp2 - 1, inp3});
        adj[inp2 - 1].push_back({inp1 - 1, inp3});
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= k; j++) {
            minDist[i][j] = INF;
        }
    }

    //{cost, {node, freeUsed}}
    priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, greater<pair<int, pair<int, int> > > > pq;
    pq.push({0, {0, 0}});
    while (!pq.empty()) {
        int curCost = pq.top().first;
        int curNode = pq.top().second.first;
        int freeUsed = pq.top().second.second;
        pq.pop();

        if (minDist[curNode][freeUsed] != INF)
            continue;

        minDist[curNode][freeUsed] = curCost;
        if (curNode == n - 1) {
            cout << curCost << endl;
            break;
        }

        for (auto v : adj[curNode]) {
            if (minDist[v.first][freeUsed] == INF) {
                pq.push({curCost + v.second, {v.first, freeUsed}});
            }
            if (minDist[v.first][freeUsed + 1] == INF && freeUsed + 1 <= k) {
                pq.push({curCost, {v.first, freeUsed + 1}});
            }
        }
    }
}
