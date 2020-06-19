#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int n, d;
pair<int, int> raindrops[100050];

bool check(int w) {
    //x, enter/exit, y
    vector<pair<pair<int, int>, int> > cPoints;

    for (int i = 0; i < n; i++) {
        cPoints.push_back({{raindrops[i].first, 0}, raindrops[i].second});
        cPoints.push_back({{raindrops[i].first + w, 1}, raindrops[i].second});
    }

    sort(cPoints.begin(), cPoints.end());

    multiset<int> active;
    //add, check, remove

    for (int i = 0; i < 2 * n; i++) {
        if (cPoints[i].first.second == 0) {
            active.insert(cPoints[i].second);
            if (cPoints[i + 1].first.second == 1) {
                if (*active.rbegin() - *active.begin() >= d)
                    return true;
            }
        }
        else {
            active.erase(active.find(cPoints[i].second));
        }
    }
    return false;
}

int main() {
    cin >> n >> d;

    for (int i = 0; i < n; i++) {
        cin >> raindrops[i].first >> raindrops[i].second;
    }

    //l <= ans < r
    int l = 1, r = 1000001, mid;
    while (l < r) {
        mid = (l + r) / 2;
        if (check(mid)) {
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }
    if (l == 1000001)
        cout << -1 << endl;
    else
        cout << l << endl;
}
