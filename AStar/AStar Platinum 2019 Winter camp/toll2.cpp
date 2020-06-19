#include <iostream>
#include <queue>
#include <map>
using namespace std;
#define INF 1000000000

vector<pair<int, int> > adj[255];
int pastureToll[255];
map<int, int> dist[255][255];//maps greatest pasture toll to min total toll
int minToll[255][255];
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
            int curToll = pq.top().first;
            int curNode = pq.top().second.second;
            int curMax = pq.top().second.first;
            pq.pop();

            //if (dist[i][curNode].count(curMax) > 0 && dist[i][curNode][curMax] >= curToll) {

                continue;
            }

            dist[i][curNode][curMax] = curToll;
            maxToll[i][curNode] = max(maxToll[i][curNode], curToll);

            for (auto v : adj[curNode]) {
                int newMax = max(curMax, pastureToll[v.first]);
                int newToll = curToll + v.second + newMax - curMax;
                pq.push(make_pair(newToll, make_pair(newMax, v.first)));
            }
        }
    }

//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < n; j++) {
//            if (i != j) {
//                dist[i][j] = min(dist[i][j], dist[j][i]);
//                dist[j][i] = dist[i][j];
//            }
//        }
//    }

    int minim;
    for (int i = 0; i < k; i++) {
        cin >> inp1 >> inp2;
        inp1--; inp2--;
        minim = INF;
        for (auto a : dist[inp1][inp2]) {
            minim = min(minim, a.second);
        }
        cout << minim << endl;
    }
}


