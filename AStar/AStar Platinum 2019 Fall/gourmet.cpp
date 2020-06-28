#include <iostream>
#include <set>
#include <algorithm>
#include <tuple>
using namespace std;

struct Event {
    int c, g;
    bool isGrass;

    bool operator<(const Event &o) const {
        return tie(c, g, isGrass) < tie(o.c, o.g, o.isGrass);
    }
};

Event events[200050];
multiset<int> active;
//pair<int, int> demands[100050];
//pair<int, int> grass[100050];

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> events[i].c >> events[i].g;
        events[i].isGrass = false;
    }
    for (int i = n; i < n + m; i++) {
        cin >> events[i].c >> events[i].g;
        events[i].isGrass = true;
    }
    sort(events, events + n + m);

    long long ans = 0;
    for (int i = 0; i < n + m; i++) {
        if (events[i].isGrass) {
            auto match = active.lower_bound(-events[i].g);
            if (match != active.end()) {
                active.erase(match);
                ans += events[i].c;
            }
        }
        else {
            active.insert(-events[i].g);
        }
    }
    if (active.empty())
        cout << ans << endl;
    else
        cout << -1 << endl;
}
