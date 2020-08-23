#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    string inp;
    for (int i = 0; i < n; i++) {
        cin >> inp;
        for (int j = 0; j < m; j++) {
            if (inp[j] == '.') {
                cout << (((i + j) % 2 == 0) ? 'B' : 'W');
            }
            else {
                cout << '-';
            }
        }
        cout << endl;
    }
}
