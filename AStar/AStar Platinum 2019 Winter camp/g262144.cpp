#include <iostream>
using namespace std;

int dp[60][300000];
//dp[i][j] = k is range [j,k) creates i
//k = 0 if there is no range starting with j to create i

int main() {
    int n, ans = 0;
    cin >> n;

    int input;
    for (int i = 0; i < n; i++) {
        cin >> input;
        dp[input][i] = i + 1;
    }

    for (int i = 1; i < 60; i++) {
        for (int j = 0; j < n; j++) {
            if (dp[i][j] != 0) {
                ans = i;
                if (dp[i][dp[i][j]] != 0) {
                    dp[i + 1][j] = dp[i][dp[i][j]];
                }
            }
        }
    }
    cout << ans << endl;
}
