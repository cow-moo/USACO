#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define INF 1000000000

int markets[10];
vector<pair<int, int> > adj[10050];
int minDist[10][10050];
//minDist from each market to each town
int marketDist[10][10];
//marketDist[i][j] stores min dist to travel to each market starting with i and ending with j
bool isMarket[10050];

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 0; i < k; i++) {
        cin >> markets[i];
        markets[i]--;
        isMarket[markets[i]] = true;
    }
    int inp1, inp2, inp3;
    for (int i = 0; i < m; i++) {
        cin >> inp1 >> inp2 >> inp3;
        adj[inp1 - 1].push_back({inp2 - 1, inp3});
        adj[inp2 - 1].push_back({inp1 - 1, inp3});
    }

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            minDist[i][j] = INF;
        }
        for (int j = 0; j < k; j++) {
            marketDist[i][j] = INF;
        }
    }

    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    for (int i = 0; i < k; i++) {
        pq.push({0, markets[i]});

        while (!pq.empty()){
            pair<int, int> cur = pq.top();
            pq.pop();

            if (minDist[i][cur.second] != INF)
                continue;

            minDist[i][cur.second] = cur.first;

            for (auto v : adj[cur.second]) {
                if (minDist[i][v.first] == INF) {
                    pq.push({cur.first + v.second, v.first});
                }
            }
        }
    }

    int order[10];
    for (int i = 0; i < k; i++)
        order[i] = i;

    do {
        int dist = 0;
        for (int i = 0; i < k - 1; i++) {
            dist += minDist[order[i]][markets[order[i + 1]]];
        }
        marketDist[order[0]][order[k - 1]] = min(marketDist[order[0]][order[k - 1]], dist);
    } while (next_permutation(order, order + k));

    int ans = INF;
    for (int farm = 0; farm < n; farm++) {
        for (int market1 = 0; market1 < k; market1++) {
            for (int market2 = 0; market2 < k; market2++) {
                if (!isMarket[farm]) {
                    ans = min(ans, minDist[market1][farm] + marketDist[market1][market2] + minDist[market2][farm]);
                }
            }
        }
    }
    cout << ans << endl;
}

