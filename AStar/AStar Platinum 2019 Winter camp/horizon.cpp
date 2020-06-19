#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

//x, height (+- for add or take out)
vector<pair<int, int> > changePts;
multiset<int> curHeights;

int main() {
    int n;
    cin >> n;

    int inp1, inp2, inp3;
    for (int i = 0; i < n; i++) {
        cin >> inp1 >> inp2 >> inp3;
        changePts.push_back({inp1, inp3});
        changePts.push_back({inp2, -inp3});
    }

    sort(changePts.begin(), changePts.end());

    long long ans = 0;
    curHeights.insert(changePts[0].second);
    curHeights.insert(0);
    for (int i = 1; i < 2 * n; i++) {
        ans += ((long long) *(--curHeights.end())) * (long long) (changePts[i].first - changePts[i - 1].first);
        if (changePts[i].second > 0) {
            curHeights.insert(changePts[i].second);
        }
        else {
            curHeights.erase(curHeights.find(-changePts[i].second));
        }
    }

    cout << ans << endl;
}
