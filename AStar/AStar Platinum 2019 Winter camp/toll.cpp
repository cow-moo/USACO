#include <iostream>
#include <queue>
using namespace std;

vector<pair<int, int> > adj[255];
int pastureToll[255];
int dist[255][255];
//dist[i][j] is min dist from i to j

int main() {
    int n = 0, m = 0, k = 0;
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        cin >> pastureToll[i];
    }

    int inp1, inp2, inp3;
    for (int i = 0; i < m; i++) {
        cin >> inp1 >> inp2 >> inp3;
        inp1--; inp2--;
        adj[inp1].push_back(make_pair(inp2, inp3));
        adj[inp2].push_back(make_pair(inp1, inp3));
    }

    priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, greater<pair<int, pair<int, int> > > > pq;
    //toll (paths + greatest pasture), current greatest (including curNode), node
    for (int i = 0; i < n; i++) {
        pq.push(make_pair(pastureToll[i], make_pair(pastureToll[i], i)));

        while (!pq.empty()) {
            if (dist[i][pq.top().second.second] > 0) {
                pq.pop();
                continue;
            }

            int curToll = pq.top().first;
            int curNode = pq.top().second.second;
            int curMax = pq.top().second.first;
            pq.pop();
            dist[i][curNode] = curToll;

            for (auto v : adj[curNode]) {
                if (dist[i][v.first] > 0)
                    continue;
                int newMax = max(curMax, pastureToll[v.first]);
                int newToll = curToll + v.second + newMax - curMax;
                pq.push(make_pair(newToll, make_pair(newMax, v.first)));
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                dist[i][j] = min(dist[i][j], dist[j][i]);
                dist[j][i] = dist[i][j];
            }
        }
    }

    for (int i = 0; i < k; i++) {
        cin >> inp1 >> inp2;
        inp1--; inp2--;
        cout << dist[inp1][inp2] << endl;
    }
}

