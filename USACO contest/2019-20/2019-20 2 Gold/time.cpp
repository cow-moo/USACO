#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;

vector<int> adj[1005];
int moonies[1005];
int highestMooney[1005];

int main() {
    freopen("time.in", "r", stdin);
    freopen("time.out", "w", stdout);

    int n, m, c;
    cin >> n >> m >> c;

    for (int i = 0; i < n; i++) {
        cin >> moonies[i];
        highestMooney[i] = -1000000000;
    }
    highestMooney[0] = 0;

    int inp1, inp2;
    for (int i = 0; i < m; i++) {
        cin >> inp1 >> inp2;
        adj[inp1 - 1].push_back(inp2 - 1);
    }

    //node, mooney
    queue<pair<int, int> > q, q_next;
    q.push(make_pair(0, 0));
    for (int t = 0; t < 1000; t++) {
        while (!q.empty()) {
            int curNode = q.front().first;
            int curMooney = q.front().second;
            q.pop();
            for (int neighbor : adj[curNode]) {
                //cout << t << " " << neighbor + 1 << " " << curMooney << endl;
                if (curMooney + moonies[neighbor] - c * (2 * t + 1) > highestMooney[neighbor]) {
                    highestMooney[neighbor] = curMooney + moonies[neighbor] - c * (2 * t + 1);
                    q_next.push(make_pair(neighbor, highestMooney[neighbor]));
                }
            }
        }
        if (q_next.empty())
            break;
        while (!q_next.empty()) {
            q.push(q_next.front());
            q_next.pop();
        }
    }

    //for (int i = 0; i < n; i++)
    //    cout << highestMooney[i] << endl;
    cout << highestMooney[0] << endl;
}
