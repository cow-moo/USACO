#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAXN 250
#define MAXW 1000

pair<int, int> cows[MAXN]; //w, t

long long dp[MAXW]; //dp[i] is max talent for weight i
pair<int, int> dpSuff; //stores talent and weight of max ratio for sufficient weight >= w
//dp: ratio only increases if the new talent/weight is greater than the current running talent/weight

int main() {
    freopen("talent.in", "r", stdin);
    freopen("talent.out", "w", stdout);

    int n, w;
    cin >> n >> w;

    for (int i = 0; i < n; i++) {
        cin >> cows[i].first >> cows[i].second;
    }

    for (int i = 1; i < w; i++) {
        dp[i] = -1;
    }

    for (int i = 0; i < n; i++) { //i is curcow being added
        if (cows[i].second * dpSuff.second > dpSuff.first * cows[i].first && dpSuff.second != 0) { //unsure if this greedy works
            dpSuff.first += cows[i].second;
            dpSuff.second += cows[i].first;
        }
        for (int j = w - 1; j >= max(0, w - cows[i].first); j--) { //weight plus curcow is > w
            if (dp[j] == -1)
                continue;
            //if ((dp[j] + cows[i].second) / (j + cows[i].first) > dpSuff.first / dpSuff.second) {
            if ((dp[j] + cows[i].second) * dpSuff.second > dpSuff.first * (j + cows[i].first) || (dpSuff.second == 0)) {
                dpSuff.first = dp[j] + cows[i].second;
                dpSuff.second = j + cows[i].first;
            }
        }
        for (int j = w - 1; j >= cows[i].first; j--) { //j is weight plus curcow
            if (dp[j - cows[i].first] != -1) {
                dp[j] = dp[j - cows[i].first] + cows[i].second;
            }
        }

        //cout << dpSuff.first << " " << dpSuff.second << endl;
    }

//    for (int i = 0; i < w; i++) {
//        cout << dp[i] << endl;
//    }
//    cout << dpSuff.first << " " << dpSuff.second << endl;
     cout << 1000 * dpSuff.first / dpSuff.second << endl;
}
