#include <iostream>
#include <map>
#include <set>
using namespace std;

int lineup[100050];
map<int, int> cowCount;

int main() {
    int n, k, ans = 0;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> lineup[i];
    }
    //cout << endl;

    int first = 0;
    int last = 0;
    for (; first < n; first++) {
        if (cowCount.size() < k + 1) {
            for (; last < n; last++) {
                if (cowCount.count(lineup[last]) > 0)
                    cowCount[lineup[last]]++;
                else if (cowCount.size() <= k)
                    cowCount[lineup[last]] = 1;
                else
                    break;
            }
        }
        //cout << cowCount.size() << endl;
        ans = max(ans, cowCount[lineup[first]]);
        if (cowCount[lineup[first]] == 1)
            cowCount.erase(lineup[first]);
        else
            cowCount[lineup[first]]--;
    }
    cout << ans << endl;
}
