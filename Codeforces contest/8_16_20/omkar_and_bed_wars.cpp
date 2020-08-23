#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    for (int z = 0; z < t; z++) {
        int n;
        string players;
        cin >> n >> players;

        bool done = false;
        int curSize = 1;
        for (int i = n - 1; i >= 0; i--) {
            if (players[i] != players[0]) {
                //cout << i << endl;
                curSize += n - 1 - i;
                n = i + 1;
                break;
            }
            if (i == 0) {
                cout << 1 + ((n - 1) / 3) << endl;
                done = true;
                break;
            }
        }
        if (done)
            continue;

        //cout << curSize << endl;

        int ans = 0;
        for (int i = 1; i < n; i++) {
            if (players[i] == players[i - 1]) {
                curSize++;
            }
            else {
                //cout << curSize << endl;
                ans += curSize / 3;
                curSize = 1;
            }
        }
        //cout << curSize << endl;
        ans += curSize / 3;
        cout << ans << endl;
    }
}
