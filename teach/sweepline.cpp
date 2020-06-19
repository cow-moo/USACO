#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

pair<pair<int, int>, bool> events[2 * MAXN];
multiset<int> curBuildings;

int main() {
    int n;
    cin >> n;

    //x1, x2, y
    int x1, x2, y;
    for (int i = 0; i < n; i++) {
        cin >> x1 >> x2 >> y;
        events[2 * i] = {{x1, y}, 0}; //building starts
        events[2 * i + 1] = {{x2, y}, 1}; //building ends
    }

    sort(events, events + 2 * n);

    curBuildings.insert(events[0].first.second);

    int area = 0;
    for (int i = 1; i < 2 * n; i++) {
        area += *curBuildings.front() * (events[i].first.first - events[i - 1].first.first);
        if (events[i].second == 0) {
            curBuildings.insert(events[i].first.second);
        }
        else {
            curBuildings.erase(curBuildings.find(events[i].first.second));
        }
    }
}
