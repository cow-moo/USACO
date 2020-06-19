#include <iostream>
#include <map>
#include <algorithm>
#include <set>
using namespace std;
#define MAXN 100050

pair<int, pair<int, int> > events[MAXN];
map<int, int> cows;
set<int> maxCows;

int main() {
    int n, g, ans = 0;
    cin >> n >> g;

    for (int i = 0; i < n; i++) {
        cin >> events[i].first >> events[i].second.first >> events[i].second.second;
        cows[events[i].second.first] = g;
        maxCows.insert(events[i].second.first);
    }

    sort(events, events + n);

    int maxim = g;
    for (int i = 0; i < n; i++) {
        int id = events[i].second.first;
        int change = events[i].second.second;
        if (change > 0) {
            cows[id] += change;
            if (cows[id] > maxim) {
                maxim = cows[id];
                maxCows.clear();
                maxCows.insert(id);
                ans++;
            }
            else if (cows[id] == maxim) {
                maxCows.insert(id);
                ans++;
            }
        }
        else {
            if (cows[id] == maximum) {

            }
        }
    }
}
