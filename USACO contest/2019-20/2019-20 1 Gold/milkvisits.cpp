#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
#define MAXN 100000
#define MAXM 100000

int type[MAXN];
int Rank[MAXN]; //height including itself
int parent[MAXN];

vector<int> adj[MAXN];
int degree[MAXN];

bool query(int a, int b, int c) {
    if (type[a] == c || type[b] == c) {
        return 1;
    }
    while(a != b) {
        if (Rank[a] > Rank[b]) { //b moves up
            b = parent[b];
        }
        else { //a moves up
            a = parent[a];
        }
        if (type[a] == c || type[b] == c) {
            return 1;
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    freopen("milkvisits.in", "r", stdin);
    freopen("milkvisits.out", "w", stdout);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> type[i];
        Rank[i] = 1;
        parent[i] = -1;
    }

    int x, y;
    for (int i = 0; i < n - 1; i++) {
        cin >> x >> y;
        x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
        degree[x]++;
        degree[y]++;
    }

    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (degree[i] == 1)
            q.push(i);
    }

    int v = n;
    while (v > 1) {
        for (int i = 0; i < q.size(); i++) {
            int t = q.front();
            q.pop();
            v--;
            degree[t]--;

            for (auto j : adj[t]) {
                if (degree[j] > 0) {
                    degree[j]--;
                    parent[t] = j;
                    Rank[j] = max(Rank[j], Rank[t] + 1);
                    if (degree[j] == 1){
                        q.push(j);
                    }
                }
            }
        }
    }
//    for (int i = 0; i < n; i++) {
//        cout << i << " " << parent[i] << " " << Rank[i] << endl;
//    }

    int a, b, c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        a--;
        b--;
        cout << query(a, b, c);
    }
    cout << endl;
}
