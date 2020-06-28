#include <iostream>
#include <algorithm>
using namespace std;
#define INF 1000000000

//width, height
pair<long long, long long> plots[50005]; //plots[j].second is m

//dp[i] = min(dp[j] + width[i - 1] * height[j])
long long dp[50005]; //dp[j] is b

//line, floor of x value of intersection with next line
//intersections are stored as integers bc queries are all integers
pair<int, long long> hull[50005]; //sorted decreasing slope

bool comp(pair<int, long long> h, long long x) {
    return h.second < x;
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> plots[i].first >> plots[i].second;
    }

    sort(plots, plots + n);

    int rn = 0; //reduced n, we get rid of all plots that are completely enclosed
    for (int i = 0; i < n; i++) {
        while (rn - 1 >= 0 && plots[i].second >= plots[rn - 1].second) {
            rn--;
        }
        plots[rn++] = plots[i];
    }

    int sz = 0;
    hull[sz++] = {0, INF};
    for (int i = 1; i <= rn; i++) {
        //finds first intersection greater than or equal to x
        int j = lower_bound(hull, hull + sz, plots[i - 1].first, comp)->first;
        dp[i] = dp[j] + plots[i - 1].first * plots[j].second;
        //new line is plots[i].second * x + dp[i]

        //find point of intersection with last hull line, see if it replaces any of the last few lines in the hull
        long long p = (dp[i] - dp[hull[sz - 1].first]) / (plots[hull[sz - 1].first].second - plots[i].second);
        while (sz - 2 >= 0 && p < hull[sz - 2].second) {
            sz--;
            p = (dp[i] - dp[hull[sz - 1].first]) / (plots[hull[sz - 1].first].second - plots[i].second);
        }
        hull[sz - 1].second = p;
        hull[sz++] = {i, INF};
    }

    cout << dp[rn] << endl;
}
