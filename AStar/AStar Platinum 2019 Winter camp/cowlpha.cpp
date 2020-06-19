#include <iostream>
#include <vector>
using namespace std;
#define MOD 97654321

//     u    l    last letter
int dp[255][255][52];
//dp[i + 1][j][k] = dp[i][j][l] + how many lk
vector<pair<int, int> > pairs;

int pos(char c) {
    if (c <= 'Z')
        return c - 'A' + 26;
    else
        return c - 'a';
}

int main() {
    int u, l, p;
    cin >> u >> l >> p;

    string str;
    for (int i = 0; i < p; i++) {
        cin >> str;
        pairs.push_back(make_pair(pos(str[0]), pos(str[1])));
        //cout << pairs[i].first << " " << pairs[i].second << endl;
    }

    for (int i = 0; i < 26; i++) {
        dp[0][1][i] = 1;
    }
    for (int i = 26; i < 52; i++) {
        dp[1][0][i] = 1;
    }

    for (int i = 0; i <= u; i++) {
        for (int j = 0; j <= l; j++) {
            for (int k = 0; k < 52; k++) {
                if (dp[i][j][k] == 0)
                    continue;
                for (pair<int, int> l : pairs) {
                    if (k == l.first) {
                        if (l.second >= 26) {
                            dp[i + 1][j][l.second] += dp[i][j][k] % MOD;
                            if (dp[i + 1][j][l.second] > MOD) dp[i + 1][j][l.second] -= MOD;
                        }
                        else {
                            dp[i][j + 1][l.second] += dp[i][j][k] % MOD;
                            if (dp[i][j + 1][l.second] > MOD) dp[i][j + 1][l.second] -= MOD;
                        }
                    }
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < 52; i++) {
        ans += dp[u][l][i] % MOD;
        if (ans > MOD) ans -= MOD;
    }
    cout << ans << endl;
}
