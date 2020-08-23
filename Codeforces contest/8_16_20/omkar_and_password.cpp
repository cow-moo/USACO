#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    for (int z = 0; z < t; z++) {
        int n;
        cin >> n;

        int ans = n;
        int inp, prev;
        for (int i = 0; i < n; i++) {
            cin >> inp;
            if (i > 0 && inp != prev) {
                ans = 1;
            }
            prev = inp;
        }
        cout << ans << endl;
    }
}
