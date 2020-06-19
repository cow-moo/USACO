#include <iostream>
#include <vector>
using namespace std;
#define MAXN 100000

vector<int> children[MAXN];
long long reqOrnaments[MAXN];
long long ornamentTime[MAXN];
long long ans = 0;

//returns subMin, subCount
pair<long long, long long> dfs(int curNode) {
    long long subCount = 0;
    long long subMin = ornamentTime[curNode];
    for (auto child : children[curNode]) {
        pair<long long, long long> subtree = dfs(child);
        subCount += subtree.second;
        subMin = min(subMin, subtree.first);
    }
    if (subCount < reqOrnaments[curNode]) {
        ans += (long long) (reqOrnaments[curNode] - subCount) * (long long) subMin;
        subCount = reqOrnaments[curNode];
    }
    return {subMin, subCount};
}

int main() {
    int n;
    cin >> n;

    int parent;
    for (int i = 0; i < n; i++) {
        cin >> parent >> reqOrnaments[i] >> ornamentTime[i];
        parent--;
        if (parent >= 0) {
            children[parent].push_back(i);
        }
    }

    dfs(0);
    cout << ans << endl;
}

