#include <iostream>
using namespace std;
//     time   exhaustion
int dp[10005][505];

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            dp[i][j] = -1;
        }
    }

    dp[1][0] = 0;

    int dist;
    for (int i = 1; i <= n; i++) {
        cin >> dist;
        for (int j = 0; j <= m; j++) {
            if (dp[i][j] != -1) {
                //run
                if (j + 1 <= m)
                    dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + dist);
                //rest
                if (j == 0)
                    dp[i + 1][0] = max(dp[i + 1][0], dp[i][j]);
                else if (i + j <= n + 1)
                    dp[i + j][0] = max(dp[i + j][0], dp[i][j]);
            }
        }
    }
    cout << dp[n + 1][0] << endl;
}
