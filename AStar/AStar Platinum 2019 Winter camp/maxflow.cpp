#include <iostream>
#include <vector>
using namespace std;
#define MAXN 100050

vector<int> adj[MAXN];
int startTimes[MAXN];
int endTimes[MAXN];

int dfs1(int curNode, int curTime) {
    startTimes[curNode] = curTime++;
    for (auto neighbor : adj[curNode]) {
        if (startTimes[neighbor] == 0)
            curTime = dfs1(neighbor, curTime);
    }
    endTimes[curNode] = curTime;
    return curTime;
}

//gives the start stalls of each end stall and vice versa
vector<int> startStalls[MAXN];
vector<int> endStalls[MAXN];
int ans = 0;

//0 is active starts, 1 is active ends
int bit[MAXN][2];

int sum(int r, int se) {
    int ret = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1)
        ret += bit[r][se];
    return ret;
}

int sum(int l, int r, int se) {
    return sum(r, se) - sum(l - 1, se);
}

void add(int idx, int delta, int se) {
    for (; idx < MAXN; idx = idx | (idx + 1))
        bit[idx][se] += delta;
}

void dfs2(int curNode, int prev) {
    //how many active flows end in subtree (inclusive)
    int flow = sum(startTimes[curNode] + 1, endTimes[curNode] - 1, 1);
    //add flows that start at curNode to active bit
    for (auto ends : endStalls[curNode]) {
        flow++;
        add(startTimes[curNode], 1, 0);
        add(startTimes[ends], 1, 1);
    }
    for (auto neighbor : adj[curNode]) {
        if (neighbor != prev) {
            dfs2(neighbor, curNode);
            //add how many paths are started and not ended in subtree (must pass through curNode)
            flow += sum(startTimes[neighbor], endTimes[neighbor] - 1, 0);
        }
    }
    for (auto starts : startStalls[curNode]) {
        flow++;
        add(startTimes[starts], -1, 0);
        add(startTimes[curNode], -1, 1);
    }
    ans = max(ans, flow);
}

int main() {
    int n, k;
    cin >> n >> k;

    int inp1, inp2;
    for (int i = 0; i < n - 1; i++) {
        cin >> inp1 >> inp2;
        adj[inp1 - 1].push_back(inp2 - 1);
        adj[inp2 - 1].push_back(inp1 - 1);
    }

    dfs1(0, 1);

    for (int i = 0; i < k ; i++) {
        cin >> inp1 >> inp2;
        int s, e;
        if (startTimes[inp1 - 1] < startTimes[inp2 - 1]) {
            s = inp1 - 1;
            e = inp2 - 1;
        }
        else {
            s = inp2 - 1;
            e = inp1 - 1;
        }
        startStalls[e].push_back(s);
        endStalls[s].push_back(e);
    }

    dfs2(0, 0);

    cout << ans << endl;
}
