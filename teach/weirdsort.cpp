#include <iostream>
using namespace std;

int arr[105];
bool pos[105];
bool exists[105];

int main() {
    int t;
    cin >> t;

    for (int a = 0; a < t ; a++) {
        int n, m, p;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            arr[i]--;
        }
        for (int i = 0; i < m; i++) {
            cin >> p;
            pos[p - 1] = 1;
        }

        bool bad;
        int beg = -1;
        for (int i = 0; i <= n; i++) {
            exists[arr[i]] = 1;

            if (pos[i] && beg == -1) {
                beg = i;
            }
            else if (pos[i] == 0 && beg != -1) {
                //we have a contiguous interval from beg to i inclusive
                bad = false;
                for (int j = beg; j <= i; j++) {
                    if (!exists[j]) {
                        bad = true;
                        break;
                    }
                }
                if (bad) {
                    cout << "NO" << endl;
                    break;
                }
            }
        }
        if (!bad)
            cout << "YES" << endl;
    }
}
