#include <iostream>
#include <bitset>
#include <map>
using namespace std;
#define INF 1000000000

struct c {
bool operator()(bitset<35> a, bitset<35> b) const {
    return a.to_ullong() < b.to_ullong();
}
};

bitset<35> toggles[35];
map<bitset<35>, int, c> outcomes1;

int n, ans = INF;

void recurse1(bitset<35> outcome, int toggleCount, int toggleIndex) {
    //cout << outcome << " " << toggleCount << endl;
    if (outcomes1.count(outcome) == 0) {
        outcomes1[outcome] = toggleCount;
    }
    else {
        outcomes1[outcome] = min(toggleCount, outcomes1[outcome]);
    }
    if (toggleIndex + 1 <= n / 2) {
        recurse1(outcome, toggleCount, toggleIndex + 1);
        outcome ^= toggles[toggleIndex];
        recurse1(outcome, toggleCount + 1, toggleIndex + 1);
    }
}

void recurse2(bitset<35> outcome, int toggleCount, int toggleIndex) {
    //outcomes1[outcome] = toggleCount;
    //cout << outcome << " " << toggleCount << endl;
    map<bitset<35>, int, c>::iterator mSearch = outcomes1.find(outcome);
    if (mSearch != outcomes1.end()) {
        ans = min(ans, (*mSearch).second + toggleCount);
    }

    if (toggleIndex + 1 <= n) {
        recurse2(outcome, toggleCount, toggleIndex + 1);
        outcome ^= toggles[toggleIndex];
        recurse2(outcome, toggleCount + 1, toggleIndex + 1);
    }
}

int main() {
    int m;
    cin >> n >> m;

    int inp1, inp2;
    for (int i = 0; i < m; i++) {
        cin >> inp1 >> inp2;
        inp1--; inp2--;
        toggles[inp1][inp2] = 1;
        toggles[inp2][inp1] = 1;
    }
    for (int i = 0; i < n; i++) {
        toggles[i][i] = 1;
    }

    recurse1(bitset<35> (0), 0, 0);
//    for (auto p : outcomes1) {
//        cout << p.first << " " << p.second << endl;
//    }
    //first half 0 to n/2 - 1, second half n/2 to n
    bitset<35> temp (0);
    for (int i = 0; i < n; i++) {
        temp[i] = 1;
    }
    //cout << temp << endl;
    recurse2(temp, 0, n / 2);

    cout << ans << endl;
}
