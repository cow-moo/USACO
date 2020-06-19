#include <iostream>
#include <set>
using namespace std;

set<int> bessie1;
set<int> bessie2;
int prefix[50005];
int suffix[50005];
int elsie[50005];

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= 2 * n; i++) {
        bessie1.insert(i);
    }
    for (int i = 0; i < n; i++) {
        cin >> elsie[i];
        bessie1.erase(elsie[i]);
    }

    for (int i = 0; i < n; i++) {
        set<int>::iterator larger = bessie1.upper_bound(elsie[i]);
        if (larger != bessie1.end()) {
            bessie2.insert(-*larger);
            bessie1.erase(larger);
            prefix[i + 1] = prefix[i] + 1;
        }
        else{
            bessie2.insert(-*bessie1.begin());
            bessie1.erase(bessie1.begin());
            prefix[i + 1] = prefix[i];
        }
        elsie[i] *= -1;
    }
//    for (auto a : bessie2)
//        cout << a << endl;
    for (int i = n - 1; i >= 0; i--) {
        set<int>::iterator smaller = bessie2.upper_bound(elsie[i]);
        if (smaller != bessie2.end()) {
            bessie2.erase(smaller);
            suffix[n - i] = suffix[n - i - 1] + 1;
        }
        else {
            bessie2.erase(bessie2.begin());
            suffix[n - i] = suffix[n - i - 1];
        }
    }
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        ans = max(ans, prefix[i] + suffix[n - i]);
        //cout << prefix[i] << endl;
    }
    cout << ans << endl;
}
