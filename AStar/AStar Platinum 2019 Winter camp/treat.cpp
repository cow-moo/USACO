#include <iostream>
#include <queue>
using namespace std;
#define MAXN 100000

//int cycleLength[MAXN]; //in a cycle, stores length of the cycle. if not cycle, it will be 0
int candy[MAXN];
int visited[MAXN];
int succ[MAXN];
queue<int> cur;

void dfs1(int node, int length) {
    visited[node] = -length;
    cur.push(node);
    if (visited[succ[node]] == 0) {
        dfs1(succ[node], length + 1);
    }
    else if (candy[succ[node]] == 0 && visited[succ[node]] < 0) {
        int cLength = length + visited[succ[node]] + 1; //visited is negative
        for (int i = 0; i < cLength; i++) {
            candy[node] = cLength;
            node = succ[node];
        }
    }
}

void dfs2(int node) {
    if (candy[succ[node]] == 0) {
        dfs2(succ[node]);
    }
    candy[node] = candy[succ[node]] + 1;
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> succ[i];
        succ[i]--;
    }

    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) {
            dfs1(i, 1);
            while (!cur.empty()) {
                visited[cur.front()] *= -1;
                cur.pop();
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (candy[i] == 0) {
            dfs2(i);
        }
        cout << candy[i] << endl;
    }

}
