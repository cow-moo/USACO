#include <iostream>
#include <stdio.h>
#include <map>
#include <algorithm>
using namespace std;

struct Measurement {
    int day, id, change;
    bool operator<(const Measurement& b) const {
        return day < b.day;
    }
};

Measurement events[100050];
map<int, int> outputs;
map<int, int> cnt;

int main() {
    freopen("measurement.in", "r", stdin);
    freopen("measurement.out", "w", stdout);

    int n, g;
    cin >> n >> g;

    for (int i = 0; i < n; i++) {
        cin >> events[i].day >> events[i].id >> events[i].change;
        if (outputs[events[i].id] == 0) {
            cnt[g]++;
            outputs[events[i].id] = g;
        }
    }

    //cout << cnt[g] << endl;

    sort(events, events + n);

    int ans = 0;
    bool change, alone;
    for (int i = 0; i < n; i++) {
        int prevMilk = outputs[events[i].id];
        outputs[events[i].id] += events[i].change;
        int newMilk = outputs[events[i].id];

        change = false, alone = false;

        if (cnt.find(prevMilk) == --cnt.end()) {
            change = true;
        }
        cnt[prevMilk]--;
        if (cnt[prevMilk] == 0) {
            cnt.erase(prevMilk);
            alone = true;
        }

        cnt[newMilk]++;
        if (cnt.find(newMilk) == --cnt.end()) {
            if (change == false)
                ans++;
            else if (alone == false)
                ans++;
            else if (cnt[newMilk] != 1)
                ans++;
        }
        else {
            if (change == true)
                ans++;
        }

        //ans += change;
    }

//    for (auto a : cnt) {
//        cout << a.first << " " << a.second << endl;
//    }

    cout << ans << endl;
}







