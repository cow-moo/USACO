#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int t1, t2, n;
    cin >> t1 >> t2 >> n;

    int hours = 0, it1, it2;
    for (int i = 0; i < n; i++) {
        cin >> it1 >> it2;

        hours += max(0, min(it2, t2) - max(it1, t1));
    }

    double ans = 1;
    for (int i = 0; i < hours; i++) {
        ans *= 0.98;
    }
    cout << round(100 * (1 - ans)) << endl;
}
