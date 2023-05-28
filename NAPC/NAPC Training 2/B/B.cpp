#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <iterator>
#include <map>
#include <set>
#include <optional>
#include <numeric>
#include <tuple>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i=0;i<n;i++){
        cin >> A[i];
    }
    int q;
    cin >> q;
    vector<vector<pair<int,vector<int>>>> queries(n);
    for (int j=0;j<q;j++) {
        int l, m;
        cin >> l >> m;
        --l;
        vector<int> ss(m);
        for (int i=0;i<m;i++){
            cin >> ss[i];
        }
        queries[l].push_back({j, ss});   
    }
    vector<int> ans(q);
    map<int,deque<int>> indices;
    for (int r=n-1;r>=0;r--) {
        indices[A[r]].push_front(r);
        // sort(begin(indices[A[r]]), end(indices[A[r]]));
        for (auto& [id, qq] : queries[r]) {
            vector<int> qq2 = qq;
            int ok = r-1, ng = n;
            auto check = [&](int rr) {
                int cnt = 0;
                for (int a : qq2) {
                    int cc = upper_bound(indices[a].begin(), indices[a].end(), rr) - indices[a].begin();
                    cnt += cc;
                }
                return cnt == rr-r+1;
            };
            while (ng - ok > 1) { 
                int mid = (ng+ok)/2;
                if (check(mid)) ok = mid;
                else ng = mid;
            }
            ans[id] = ok-r+1;
        }
    }
    for (int i=0;i<q;i++){
        cout << ans[i] << "\n";
    }
}