#include <iostream>
#include <stack>
using namespace std;

int curSupports[200005];
//stack<int> curSupports;

int main() {
    int t;
    cin >> t;

    for (int z = 0; z < t; z++) {
        int sz = 0;
        int n;
        long long ans = 0;
        cin >> n;

        int cur;
        cin >> cur;
        curSupports[sz++] = cur;
        for (int i = 1; i <= n; i++) {
            if (i != n) {
                cin >> cur;
            }
            else {
                cur = 2000000000;
            }
            if (cur > curSupports[sz - 1]) {
                while (sz > 1) {
//                    curSupports[sz - 1]++;
//                    ans++;
                    if (curSupports[sz - 2] <= cur) {
                        ans += curSupports[sz - 2] - curSupports[sz - 1];
                        sz--;
                    }
                    else {
                        ans += cur - curSupports[sz - 1];
                        curSupports[sz - 1] = cur;
                        break;
                    }

//                    if (curSupports[sz - 1] == curSupports[sz - 2]) {
//                        sz--;
//                    }
//                    if (curSupports[sz - 1] == cur) {
//                        break;
//                    }
                }
                if (sz == 1) {
                    curSupports[0] = cur;
                }
            }
            else if (cur < curSupports[sz - 1]) {
                curSupports[sz++] = cur;
            }
        }
        cout << ans << endl;
    }
}
