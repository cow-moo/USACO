#include <iostream>
#include <bitset>
#include <vector>
#include <map>
using namespace std;
#define INF 1000000000

struct comp {
    bool operator() (const bitset<20>& a, const bitset<20>& b) const {
        return a.to_ulong() < b.to_ulong();
    }
};

int n, k, ans = INF;
int pastures[20][20];
map<bitset<20> , int, comp> vFenceMap;

bool check(bitset<20> vFences, int usedVFences, int minGroup) {
    vector<int> groups (usedVFences + 1, 0);
    int curGroup = 0;
    int usedHFences = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            groups[curGroup] += pastures[i][j];
            if (vFences[j]) {
                curGroup++;
            }
        }
        curGroup = 0;
        for (int j = 0; j <= usedVFences; j++) {
            if (groups[j] > minGroup) {
                if (usedVFences + usedHFences >= k) {
                    return false;
                }
                else {
                    usedHFences++;
                    for (int l = 0; l <= usedVFences; l++) {
                        groups[l] = 0;
                    }
                    i--;
                }
                break;
            }
        }
    }
    return true;
}

//0th bit is state of fence after pasture 0
void b_search(bitset<20> vFences, int usedVFences, int curPos) {
    int lo = 0;
    int hi = 225000;
    while (hi > lo) {
        int mid = (lo + hi) / 2;
        if (check(vFences, usedVFences, mid)) {
            //success
            hi = mid;
        }
        else {
            lo = mid + 1;
        }
    }
    ans = min(ans, lo);
}

int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> pastures[i][j];
        }
    }

    vFenceMap.insert({bitset<20> (0), 0});
    for (int i = 0; i < n - 1; i++) {
        for (auto a : vFenceMap) {
            if (a.first[i] == 0) {
                if (a.second < k){
                    bitset<20> newSet = a.first;
                    newSet[i] = 1;
                    vFenceMap.insert({newSet, a.second + 1});
                }
            }
            else {
                break;
            }
        }
    }

    for (auto a : vFenceMap) {
        b_search(a.first, a.second, 0);
    }
    cout << ans << endl;
}
