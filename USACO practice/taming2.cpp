#include <iostream>
#include <stdio.h>
using namespace std;
#define INF 1000;

int log[105];
int dp[100][100][105]; //[current index][last breakout][breakout num]

char output[3] = {'_', 'X', 'O'};

int main() {
    freopen("taming.in", "r", stdin);
    freopen("taming.out", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> log[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            for (int k = 0; k <= n; k++) {
                dp[i][j][k] = INF;
            }
        }
    }

    dp[0][0][1] = !(log[0] == 0);

    for (int k = 1; k <= n; k++) {
        for (int j = k - 1; j < n; j++) {
            if (j != 0) { //i == j
                for (int j1 = 0; j1 < j; j1++) {
                    dp[j][j][k] = min(dp[j][j][k], dp[j - 1][j1][k - 1]);
                }
                dp[j][j][k] += !(log[j] == 0);
            }
            for (int i = j + 1; i < n; i++) {
                dp[i][j][k] = dp[i - 1][j][k] + !(log[i] == i - j);
            }
        }
    }

//    for (int j = 0; j < n; j++) {
//        cout << dp[j][2][1] << " ";
//    }
//    cout << endl;

    int minim;
    for (int k = 1; k <= n ;k++) {
        minim = INF;
        for (int j = k - 1; j < n; j++) {
            minim = min(minim, dp[n - 1][j][k]);
        }
        cout << minim << endl;
    }
}

