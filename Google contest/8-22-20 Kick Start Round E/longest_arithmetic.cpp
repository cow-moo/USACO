#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    for (int z = 1; z <= t; z++) {
        int n;
        cin >> n;

        int maxim = 0;
        int curLength = 2;
        int cur, prev;
        cin >> prev;
        cin >> cur;
        int prevDiff = cur - prev;
        for (int i = 0; i < n - 2; i++) {
            prev = cur;
            cin >> cur;
            if (cur - prev == prevDiff) {
                curLength++;
            }
            else {
                maxim = max(maxim, curLength);
                curLength = 2;
                prevDiff = cur - prev;
            }
        }
        maxim = max(maxim, curLength);

        cout << "Case #" << z << ": " << maxim << endl;
    }
}
