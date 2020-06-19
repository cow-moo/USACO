#include <iostream>
#include <map>
using namespace std;

int bulbs[105];
multimap<int, int> holes[2];

int main() {
    int n, ans = 0;
    cin >> n;

    //mod 0 and mod 1 available
    int unused[2] = {n / 2, (n + 1) / 2};

    for (int i = 0; i < n; i++) {
        cin >> bulbs[i];
        if (bulbs[i] == 0)
            bulbs[i] = -1;
        else {
            bulbs[i] %= 2;
            unused[bulbs[i]]--;
        }
    }

    int prev = bulbs[0], prevIndex = 0;
    for (int i = 1; i < n; i++) {
        if (bulbs[i] == -1)
            continue;
        if (prev == -1) {
            holes[bulbs[i]].insert({i - prevIndex, 1});
        }
        else if (bulbs[i] == prev) {
            if (i - prevIndex - 1 > 0)
                holes[bulbs[i]].insert({i - prevIndex - 1, 2});
        }
        else {
            ans++;
        }
        prev = bulbs[i];
        prevIndex = i;
    }
    if (prevIndex < n - 1) {
        if (prev == -1) {
            cout << 1 << endl;
            return 0;
        }
        holes[prev].insert({n - 1 - prevIndex, 1});
    }

    for (int i = 0; i <= 1; i++) {
        for (auto hole : holes[i]) {
            unused[i] -= hole.first;
            if (unused[i] < 0)
                ans += hole.second;
                //ans += 2;
            //cout << hole << endl;
        }
        //cout << endl;
    }
    //cout << unused[0] << " " << unused[1] << endl;
    cout << ans << endl;
}
/*
12
1 0 3 0 5 0 7 8 10 12 0 0
  9   11  2           4 6
17
1 0 0 0 0 0 0 0 3 2 4 6 8 10 12 14 16
5
0 0 0 0 1
*/
