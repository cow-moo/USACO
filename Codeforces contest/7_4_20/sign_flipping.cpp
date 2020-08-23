#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    for (int z = 0; z < t; z++) {
        int n;
        cin >> n;

        int inp;
        for (int i = 0; i < n; i++) {
            cin >> inp;
            inp = (inp > 0) ? inp : -inp;
            cout << ((i % 2 == 0) ? inp : -inp) << " ";
        }
        cout << endl;
    }
}
