#include <iostream>
using namespace std;

int values[105][105]; //[flower][vase]
int dp[105][105]; //dp[i][j] is max points using first i flowers in the vases up to and including j, given i at j

int main() {
    int f, v;
    cin >> f >> v;

    for (int i = 1; i <= f; i++) {
        for (int j = 1; j <= v; j++) {
            cin >> values[i][j];
            dp[i][j] = -10000;
        }
    }

    //dp[0][0] = 0;
    for (int i = 1; i <= f; i++) {
        for (int j = i; j <= v; j++) {
            for (int k = i - 1; k < j; k++) {
                dp[i][j] = max(dp[i][j], dp[i - 1][k] + values[i][j]);
            }
        }
    }

    int ans = -10000;
    for (int j = f; j <= v; j++) {
        ans = max(ans, dp[f][j]);
    }
    cout << ans << endl;
}
