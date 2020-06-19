#include <iostream>
#include <map>
#include <vector>
using namespace std;

//price, value
//map<int, int> consoles;

map<int, int> dp;

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

    dp[0] = 0;

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
        for (auto a : comb1) {
            cout << a.first << " " << a.second << endl;
        }

        vector<pair<int, int> > newdp;

        //after cleaning strictly bad combinations
        //map<int, int> comb2;
        int prev = 0;
        int temp = 0;
        for (pair<int, int> a : comb1) {
            //prunes bad combinations
            if (a.second > prev && a.first <= budget) {
                prev = a.second;
                temp++;
                //comb2[a.first] = a.second;

                for (pair<int, int> b : dp) {
                    if (b.first + a.first <= budget)
                        newdp.push_back({b.first + a.first, b.second + a.second});
                    else
                        break;
                }
            }
        }
        cout << temp << endl;

        for (pair<int, int> a : newdp) {
            //if (dp.count(a.first))
                dp[a.first] = max(dp[a.first], a.second);
            //else
            //    dp[a.first] = a.second;
        }

        prev = -1;
        for (auto it = dp.begin(); it != dp.end();) {
            if (it->second > prev) {
                prev = it->second;
                it++;
            }
            else {
                dp.erase(it++);
            }
        }

        cout << newdp.size() << endl;
        cout << dp.size() << endl;

//        for (pair<int, int> a : comb2)
//            cout << a.first << " " << a.second << endl;
//        cout << endl;


    }
//    for (auto a : dp) {
//        cout << a.first << " " << a.second << endl;
//    }
    cout << dp.rbegin()->second << endl;
}
/*
1 100000
300 1 30 50
*/
