#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
#define MAXN 100050

//num stores length of all neighbor subtrees
vector<int> adj[MAXN], num[MAXN];
//stores size of subtree (including node)
int sub[MAXN];
int n;

int dfs(int curNode, int prevNode) {
    sub[curNode] = 1;
    for (int v : adj[curNode]) {
        if (v == prevNode)
            continue;
        dfs(v, curNode);
        sub[curNode] += sub[v];
        num[curNode].push_back(sub[v]);
    }
    if (sub[curNode] != n)
        num[curNode].push_back(n - sub[curNode]);
}

int lengths[MAXN];
bool ok(int k) {
    if ((n - 1) % k != 0)
        return 0;
    for (int i = 0; i < k; i++)
        lengths[i] = 0;
    for (int i = 0; i < n; i++) {
        int paired = 0;
        for (int j : num[i]) {
            int mod = j % k;
            if (mod == 0)
                continue;
            if (lengths[k - mod] == 0) {
                lengths[mod]++;
                paired++;
            }
            else {
                lengths[k - mod]--;
                paired--;
            }
        }
        if (paired != 0)
            return 0;
    }
    return 1;
}

int main() {
    freopen("deleg.in", "r", stdin);
    freopen("deleg.out", "w", stdout);

    cin >> n;

    int inp1, inp2;
    for (int i = 0; i < n - 1; i++) {
        cin >> inp1 >> inp2;
        adj[inp1 - 1].push_back(inp2 - 1);
        adj[inp2 - 1].push_back(inp1 - 1);
    }
    dfs(0, -1);
    for (int i = 1; i < n; i++) {
        cout << ok(i);
    }
    cout << endl;
}
