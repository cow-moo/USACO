#include <iostream>
using namespace std;

int main () {
    int t;
    cin >> t;

    for (int z = 0; z < t; z++) {
        int n, m;
        cin >> n >> m;

        bool good = true;
        int inp;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> inp;
                if ((i == 0 || i == n - 1) && (j == 0 || j == m - 1)) {
                    if (inp > 2)
                        good = false;
                }
                else if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                    if (inp > 3)
                        good = false;
                }
                else {
                    if (inp > 4)
                        good = false;
                }
            }
        }
        if (good) {
            cout << "YES" << endl;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if ((i == 0 || i == n - 1) && (j == 0 || j == m - 1)) {
                        cout << 2 << " ";
                    }
                    else if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                        cout << 3 << " ";
                    }
                    else {
                        cout << 4 << " ";
                    }
                }
                cout << endl;
            }
        }
        else {
            cout << "NO" << endl;
        }
    }
}
