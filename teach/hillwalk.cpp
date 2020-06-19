#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

struct Hill {
    pair<int, int> p1;
    pair<int, int> p2;

    pair<int, int> slope;
};

Hill hills[100050];

struct ClassComp {
    bool operator() (const int& a, const int& b) const {
        Hill h1 = hills[a];
        Hill h2 = hills[b];

        if (h1.p1.first > h2.p1.first) {
            return (long long) h2.slope.first * (h1.p1.second - h2.p1.second) >
                   (long long) h2.slope.second * (h1.p1.first - h2.p1.first);
        }
        else {
            return (long long) h1.slope.second * (h2.p1.first - h1.p1.first) >
                   (long long) h1.slope.first * (h2.p1.second - h1.p1.second);
        }

//        return (long long) h2.slope.first * h1.slope.second * (gx - h1.p1.first) >
//               (long long) h1.slope.first * h2.slope.second * (gx - h2.p1.first) +
//               (long long) h1.slope.first * h2.slope.first * (h2.p1.second - h1.p1.second);
    }
};

//0 is remove, 1 is add
//x, 0/1, hill index
vector<pair<pair<int, bool>, int> > cPoints;
//erase before inserting
set<int, ClassComp> active;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> hills[i].p1.first >> hills[i].p1.second >> hills[i].p2.first >> hills[i].p2.second;
        hills[i].slope.first = hills[i].p2.first - hills[i].p1.first;
        hills[i].slope.second = hills[i].p2.second - hills[i].p1.second;

        cPoints.push_back({{hills[i].p1.first, 1}, i});
        cPoints.push_back({{hills[i].p2.first, 0}, i});
    }
    sort(cPoints.begin(), cPoints.end());

    int curHill = 0, ans = 1;
    ClassComp comp;

    for (int i = 0; i < 2 * n; i++) {
        bool add = cPoints[i].first.second;
        int curIndex = cPoints[i].second;

        if (add == 0) {
            active.erase(curIndex);
        }
        else {
            //only add if curHill is higher than curIndex
            if (comp(curHill, curIndex) || curHill == curIndex) {
                active.insert(curIndex);
            }
        }

        if (cPoints[i].first.first == hills[curHill].p2.first && cPoints[i + 1].first.first != hills[curHill].p2.first) {
            //new hill selection time
            if (active.empty()) {
                break;
            }
            else {
                curHill = *active.begin();
                ans++;
            }
        }
    }
    cout << ans << endl;
}
