#include <iostream>
using namespace std;
#define MOD 100000000

int dpPrev[4100];
int dpCur[4100];

int pastures[15];

int main() {
    int m, n;
    cin >> m >> n;

    int inp;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> inp;
            pastures[i] += inp << j;
        }
    }

    for (int config = 0; config < (1 << n); config++) {
        if ((~pastures[0] & config) == 0 && (config & (config >> 1)) == 0) {
            dpCur[config] = 1;
        }
    }

    for (int i = 1; i < m; i++) {
        for (int config = 0; config < (1 << n); config++) {
            dpPrev[config] = dpCur[config];
            dpCur[config] = 0;
        }
        for (int curConfig = 0; curConfig < (1 << n); curConfig++) {
            for (int prevConfig = 0; prevConfig < (1 << n); prevConfig++) {
                if (dpPrev[prevConfig] == 0)
                    continue;
                if ((~pastures[i] & curConfig) == 0 && (curConfig & (curConfig >> 1)) == 0 && (curConfig & prevConfig) == 0) {
                    dpCur[curConfig] += dpPrev[prevConfig];
                    if (dpCur[curConfig] >= MOD) dpCur[curConfig] -= MOD;
                }
            }
        }
    }

    int ans = 0;
    for (int config = 0; config < (1 << n); config++) {
        ans += dpCur[config];
        if (ans >= MOD) ans -= MOD;
    }

    cout << ans << endl;
}
