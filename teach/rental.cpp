#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

long long cows[100050];
pair<long long, long long> stores[100050];
long long rental[100050];

long long rentalProfit[100050];
long long storeProfit[100050];

int main() {
    freopen("rental.in", "r", stdin);
    freopen("rental.out", "w", stdout);
    int n, m, r;
    cin >> n >> m >> r;

    for (int i = 0; i < n; i++) {
        cin >> cows[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> stores[i].second >> stores[i].first;
    }
    for (int i = 0; i < r ; i++) {
        cin >> rental[i];
    }
    //cout << endl;

    sort(cows, cows + n, greater<int>());
    sort(stores, stores + m, greater<pair<int, int> >());
    sort(rental, rental + r, greater<int>());
    //for (int i = 0; i < r; i++)
    //    cout << rental[i] << endl;


    for (int i = 1; i <= n; i++) {
        rentalProfit[i] = rentalProfit[i - 1] + rental[i - 1];
    }
//
//    for (int i = 0; i < m; i++)
//        cout << stores[i].first << stores[i].second << endl;

    int curStore = 0;
    for (int i = 1; i <= n; i++) {
        //cows[i]: cur milk left that we need to sell
        //stores[curStore].second: milk left at curstore
        storeProfit[i] = storeProfit[i - 1];
        while (cows[i - 1] > 0 && curStore < m) {
            if (cows[i - 1] < stores[curStore].second) {
                storeProfit[i] += cows[i - 1] * stores[curStore].first;
                stores[curStore].second -= cows[i - 1];
                cows[i - 1] = 0;
            }
            else {
                storeProfit[i] += stores[curStore].second * stores[curStore].first;
                cows[i - 1] -= stores[curStore].second;
                stores[curStore++].second = 0;
            }
        }
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, rentalProfit[i] + storeProfit[n - i]);
    }
    cout << ans << endl;
}
