#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    for (int z = 1; z <= t; z++) {
        int n, a, b, c;
        cin >> n >> a >> b >> c;
        a -= c;
        b -= c;
        cout << "Case #" << z << ": ";
        if (a + b + c > n) {
            cout << "IMPOSSIBLE ";
        }
        else if (c != 1) {
            for (int i = 0; i < a; i++) {
                cout << n - 1 << " ";
            }
            cout << n << " ";
            for (int i = 0; i < n - (a + b + c); i++) {
                cout << "1 ";
            }
            for (int i = 0; i < c - 1; i++) {
                cout << n << " ";
            }
            for (int i = 0; i < b; i++) {
                cout << n - 1 << " ";
            }
        }
        else {
            if (a == 0 && b == 0) {
                if (n == 1) {
                    cout << "1 ";
                }
                else {
                    cout << "IMPOSSIBLE ";
                }
            }
            else if (a > 0) {
                for (int i = 0; i < a; i++) {
                    cout << n - 1 << " ";
                }
                for (int i = 0; i < n - (a + b + c); i++) {
                    cout << "1 ";
                }
                for (int i = 0; i < c; i++) {
                    cout << n << " ";
                }
                for (int i = 0; i < b; i++) {
                    cout << n - 1 << " ";
                }
            }
            else {
                for (int i = 0; i < c; i++) {
                    cout << n << " ";
                }
                for (int i = 0; i < n - (a + b + c); i++) {
                    cout << "1 ";
                }
                for (int i = 0; i < b; i++) {
                    cout << n - 1 << " ";
                }
            }
        }
        cout << endl;
    }
}
