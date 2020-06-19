#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MOD 1000000007

vector<int> adj[100050];
bool visited[100050];

int main() {
    int n, m;
    long long ans = 1;
    cin >> n >> m;

    int inp1, inp2;
    for (int i = 0; i < m; i++) {
        cin >> inp1 >> inp2;
        inp1--;
        inp2--;
        adj[inp1].push_back(inp2);
        adj[inp2].push_back(inp1);
    }

    queue<pair<int, int> > q;
    int counter;
    bool cycle;
    for (int i = 0; i < n; i++) {
        if(!visited[i]) {
            counter = 0;
            cycle = false;

            q.push(make_pair(i, -1));
            visited[i] = true;
            counter++;
            while(!q.empty()) {
                int cur = q.front().first;
                int prev = q.front().second;
                q.pop();
                for (int next : adj[cur]) {
                    if (visited[next] && next != prev) {
                        cycle = true;
                    }
                    else if (!visited[next]) {
                        q.push(make_pair(next, cur));
                        visited[next] = true;
                        counter++;
                    }
                }
            }

            if (cycle) {
                ans *= 2;
                ans %= MOD;
            }
            else {
                ans *= counter;
                ans %= MOD;
            }
        }
    }

    cout << ans << endl;
}
