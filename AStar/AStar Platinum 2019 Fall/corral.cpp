#include <iostream>
using namespace std;

int c, n;
int clovers[505][2];

bool check(int length) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (clovers[i][0] <= clovers[j][0] && clovers[j][1] <= clovers[i][1]) {
                int counter = 0;
                for (int k = 0; k < n; k++) {
                    if (clovers[k][0] >= clovers[i][0] && clovers[k][0] < clovers[i][0] + length &&
                        clovers[k][1] >= clovers[j][1] && clovers[k][1] < clovers[j][1] + length) {
                        counter++;
                    }
                }
                if (counter >= c)
                    return true;
            }
        }
    }
    return false;
}

int main() {
    cin >> c >> n;

    for (int i = 0; i < n; i++) {
        cin >> clovers[i][0] >> clovers[i][1];
    }

    //cout << check(4) << endl;

    //l <= ans < r;
    int l = 1, r = 10001, mid;
    while (l < r) {
        mid = (l + r) / 2;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    cout << l << endl;
}
