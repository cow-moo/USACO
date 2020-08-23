#include <iostream>
#include <algorithm>
using namespace std;

int cnt[200050];
int e[200050];

int main() {
    int t;
    cin >> t;

    for (int z = 0; z < t; z++) {
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
                cin >> e[i];
        }
        sort(e, e + n);

        int lastGroup = -1, groups = 0;

        for (int i = 0; i < n; i++) {
            //cout << i << ": " << lastGroup << " " << e[i] << endl;
            if (e[i] <= i - lastGroup) {
                lastGroup = i;
                //cout << lastGroup << " " << e[i] << endl;
                groups++;
            }
        }

        cout << groups << endl;

//        for (int i = 1; i <= n; i++) {
//            cnt[i] = 0;
//        }
//        int inp;
//        for (int i = 0; i < n; i++) {
//            cin >> inp;
//            cnt[inp]++;
//        }
//        int groups = 0, leftover = 0;
//        for (int i = 1; i <= n; i++) {
//
//        }
    }
}
