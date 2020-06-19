#include <iostream>
using namespace std;
#define MOD 100000000

//int rating[2005];
int dp[2005][2];//i%2 is prev, (i+1)%2 is current

int main() {
    int n, f, rating;
    cin >> n >> f;

    dp[0][1] = 1;
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        //cin >> rating[i];
        cin >> rating;
        rating %= f;
        for (int j = 0; j < f; j++) {
            dp[j][(i + 1) % 2] += dp[(f + j - rating) % f][i % 2];
            dp[j][(i + 1) % 2] %= MOD;
        }
        for (int j = 0; j < f; j++) {
            dp[j][i % 2] = dp[j][(i + 1) % 2];
            //cout << dp[j][(i + 1) % 2] << " ";
        }
        //cout << endl;
    }

    cout << dp[0][n % 2] - 1 << endl;
    //subtract one to dp[0] bc can't choose 0 cows
}
