#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    for (int z = 0; z < t; z++) {
        int n;
        cin >> n;

        bool f0 = false;
        bool f01 = false;
        bool f010 = false;
        //int ans = 0;
        for (int i = 1; i <= n; i++) {
            int inp;
            cin >> inp;

            if (inp != i) {
                f0 = true;
            }
            if (f0 && inp == i) {
                f01 = true;
            }
            if (f01 && inp != i) {
                f010 = true;
            }
        }
        if (f010) {
            cout << 2 << endl;
        }
        else if (f0) {
            cout << 1 << endl;
        }
        else {
            cout << 0 << endl;
        }
    }
}
