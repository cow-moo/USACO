#include <iostream>
using namespace std;

int arr[200050];

int main() {
    int t;
    cin >> t;

    for (int z = 0; z < t; z++) {
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        bool inc = true;
        for (int i = n - 1; i >= 0; i--) {
            if (inc && arr[i] < arr[i + 1]) {
                inc = false;
            }
            if (!inc && arr[i] > arr[i + 1]) {
                cout << i + 1 << endl;
                break;
            }
            if (i == 0) {
                cout << 0 << endl;
            }
        }
    }
}
