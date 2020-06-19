#include <iostream>
#include <map>
#include <vector>
using namespace std;

//price, value
//map<int, int> consoles;

int dp[100000][2];

int main() {
//    map<int, int> test;
//    test[3] = 2;
//    test[1] = 7;
//    for (map<int, int>::reverse_iterator rit = test.rbegin(); rit != test.rend(); rit++) {
//        test[rit->first+5] = 1;
//    }
//    for (pair<int, int> a : test)
//        cout << a.first << " " << a.second << endl;

    int n, budget;
    cin >> n >> budget;

    for (int i = 1; i <= budget; i++) {
        dp[i][0] = -1;
    }

    dp[0][0] = 0;

    for (int i = 0; i < n; i++) {
        int p, g;
        cin >> p >> g;

        if (p > budget)
            continue;

        //all combinations of games
        map<int, int> comb1;

        comb1[p] = 0;
        for (int j = 0; j < g; j++) {
            int price, value;
            cin >> price >> value;

            for (map<int, int>::reverse_iterator rit = comb1.rbegin(); rit != comb1.rend(); ++rit) {
                //if (rit->first + price <= budget && (--consoles[i].upper_bound(rit->first + price))->second < rit->second + value) {
                if (comb1.count(rit->first + price))
                    comb1[rit->first + price] = max(comb1[rit->first + price], rit->second + value);
                else
                    comb1[rit->first + price] = rit->second + value;
                //}
            }
        }
//        for (auto a : comb1) {
//            cout << a.first << " " << a.second << endl;
//        }

        //after cleaning strictly bad combinations
        //map<int, int> comb2;
        int prev = 0;
        for (pair<int, int> a : comb1) {
            //prunes bad combinations
            if (a.first > budget)
                break;
            if (a.second > prev) {
                prev = a.second;
                //comb2[a.first] = a.second;

                for (int j = a.first; j <= budget; j++) {
                    if (dp[j - a.first][0] != -1) {
                        dp[j][1] = max(dp[j][1], dp[j - a.first][0] + a.second);
                    }
                }
            }
        }

        for (int j = 0; j <= budget; j++) {
            dp[j][0] = dp[j][1];
        }

//        for (pair<int, int> a : comb2)
//            cout << a.first << " " << a.second << endl;
//        cout << endl;


    }
//    for (auto a : dp) {
//        cout << a.first << " " << a.second << endl;
//    }
    int ans = 0;
    for (int i = 0; i <= budget; i++) {
        ans = max(ans, dp[i][0]);
    }
    cout << ans << endl;
}
/*
1 100000
300 1 30 50
*/

