#include <iostream>
using namespace std;
#define MAXN 5005

int coins[MAXN];
int dp[2][MAXN][2]; //length, start, which cow

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    for (int l = 1; l <= n; l++) {
        for (int s = 0; s <= n - l; s++) {
            int cow = l % 2;
            if (dp[(l + 1) % 2][s][cow] + coins[l + s - 1] > dp[(l + 1) % 2][s + 1][cow] + coins[s]) {
                dp[l % 2][s][cow] = dp[(l + 1) % 2][s][cow] + coins[l + s - 1];
                dp[l % 2][s][1 - cow] = dp[(l + 1) % 2][s][1 - cow];
            }
            else {
                dp[l % 2][s][cow] = dp[(l + 1) % 2][s + 1][cow] + coins[s];
                dp[l % 2][s][1 - cow] = dp[(l + 1) % 2][s + 1][1 - cow];
            }
        }
    }

    cout << dp[n % 2][0][n % 2] << endl;
}
