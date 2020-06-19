#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 5005

int dp[MAXN];

int main() {
    int n;
    string str, rev;

    cin >> n >> str;
    rev = str;
    reverse(rev.begin(), rev.end());

//    str = "AGGTABZ";
//    rev = "GXTXAYB";
//    n = 7;

    int ans = n;

    for (int i = 0; i < n; i++) {
        for (int j = n - 1; j >= 1; j--) {
            if (rev[i] == str[j])
                dp[j] = dp[j - 1] + 1;
        }
        if (rev[i] == str[0])
            dp[0] = 1;
        for (int j = 1; j < n; j++) {
            dp[j] = max(dp[j], dp[j - 1]);
        }

        if (n - 2 - i >= 0)
            ans = min(ans, n - 2 * dp[n - 2 - i]);
        if (n - 3 - i >= 0)
            ans = min(ans, n - 1 - 2 * dp[n - 3 - i]);
//        for (int j = 0; j < n; j++)
//            cout << dp[j] << " ";
//        cout << endl;
    }
    cout << ans << endl;

    //for (int i = 0; i < 7; i++) {
    //    cout << dp[i] << " ";
    //}
    //cout << str << endl << rev << endl;
}
/*
  A G G T A B
G 0 1 1 1 1 1
X 0 1 1 1 1 1
T 0 1 1 2 2 2
X 0 1 1 2 2 2
A 1 1 1 2 3 3
Y 1 1 1 2 3 3
B 1 1 1 2 3 4
*/
