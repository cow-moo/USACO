#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAXN 1000050

int n, r, m;
vector<int> adj[MAXN];
int visited[MAXN];
//unvisited = 0
//visited = protected by soldier based at whatever value city

bool bfs(int startCity, int strength) {
    if (visited[startCity] != 0)
        return false;
    queue<pair<int, int> > q; //city, distance

    q.push({startCity, 0});
    while(!q.empty()) {
        int curCity = q.front().first;
        int curDist = q.front().second;
        q.pop();

        if (visited[curCity] == startCity)
            continue;
        else {
            visited[curCity] = startCity;
            if (curDist < strength) {
                for (int neighbor : adj[curCity]) {
                    if (visited[neighbor] == startCity)
                        continue;
                    else if (visited[neighbor] != 0)
                        return false;
                    else
                        q.push({neighbor, curDist + 1});
                }
            }
        }
    }
    return true;
}

int main() {
    int t;
    cin >> t;

    for (int a = 0; a < t; a++) {
        cin >> n >> r >> m;

        int inp1, inp2;
        for (int i = 0; i < r; i++) {
            cin >> inp1 >> inp2;
            adj[inp1].push_back(inp2);
            adj[inp2].push_back(inp1);
        }

        bool no = false;
        for (int i = 0; i < m; i++) {
            cin >> inp1 >> inp2;
            if (!bfs(inp1, inp2)) {
                no = true;
                break;
            }
        }

        if (no == false) {
            for (int i = 1; i <= n; i++) {
                if (visited[i] == 0) {
                    no = true;
                    break;
                }
            }
        }


        if (no)
            cout << "No" << endl;
        else
            cout << "Yes" << endl;

        for (int i = 1; i <= n; i++) {
            //cout << visited[i] << endl;
            visited[i] = 0;
        }
        for (int i = 1; i <= n; i++) {
            adj[i].clear();
        }
    }
}
