#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    for (int z = 0; z < t; z++) {
        int n;
        cin >> n;

        bool found = false;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                n /= i;
                cout << n << " ";
                n *= (i - 1);
                cout << n << endl;
                found = true;
                break;
            }
        }
        if (!found)
            cout << 1 << " " << n - 1 << endl;
    }
}
