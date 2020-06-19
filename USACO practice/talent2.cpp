#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAXN 250
#define MAXW 1000
#define INF 100000000000LL

int n, w;
int weight[MAXN];
int talent[MAXN];


long long dp[MAXW + 1]; //dp[i] is max adjusted talent score for weight i

bool doable(int r) {
    for (int i = 0; i <= w; i++) {
        dp[i] = -INF;
    }
    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        long long value = 1000 * (long long) talent[i] - r * (long long) weight[i];
        for (int j = w; j >= 0; j--) {
            int j1 = min(w, j + weight[i]);
            if (dp[j] != -INF) {
                dp[j1] = max(dp[j1], dp[j] + value);
            }
        }
    }

    return dp[w] >= 0;
}

int main() {
    freopen("talent.in", "r", stdin);
    freopen("talent.out", "w", stdout);

    cin >> n >> w;

    for (int i = 0; i < n; i++) {
        cin >> weight[i] >> talent[i];
    }

    // Binary search
    // Invariant: lo <= answer < hi
    int lo = 0;
    int hi = (1000 * 250 * 1000) + 1;
    while (hi > lo + 1) {
        int mid = (lo + hi) / 2;
        if (doable(mid)) {
            lo = mid;
        }
        else {
            hi = mid;
        }
    }

    cout << lo << endl;
}

