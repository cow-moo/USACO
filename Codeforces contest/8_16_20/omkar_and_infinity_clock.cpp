#include <iostream>
using namespace std;

int arr[200005];

int main() {
    int t;
    cin >> t;

    for (int z = 0 ; z < t; z++) {
        int n;
        long long k;
        cin >> n >> k;

        int maxim = -2000000000, minim = 2000000000;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            maxim = max(maxim, arr[i]);
            minim = min(minim, arr[i]);
        }

        if (k % 2 == 0) {
            for (int i = 0; i < n; i++) {
                cout << arr[i] - minim << " ";
            }
            cout << endl;
        }
        else {
            for (int i = 0; i < n; i++) {
                cout << maxim - arr[i] << " ";
            }
            cout << endl;
        }
    }
}
