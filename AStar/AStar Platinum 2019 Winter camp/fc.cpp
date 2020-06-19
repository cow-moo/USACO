#include <iostream>
#include <vector>
#include <math.h>
#include <stdio.h>
#include <algorithm>
using namespace std;

bool ccw(pair<double, double> o, pair<double, double> a, pair<double, double> b) {
    return (a.first - o.first) * (b.second - o.second) - (a.second - o.second) * (b.first - o.first) > 0;
}
//returns if OA to OB is ccw

pair<double, double> cows[10050];
vector<pair<double, double> > hull (20050);

double dist(pair<double, double> a, pair<double, double> b) {
    return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> cows[i].first >> cows[i].second;
    }

    if (n == 0 || n == 1) {
        cout << "0.00" << endl;
        //printf("%.2f\n", 0);
        return 0;
    }
    else if (n == 2) {
        printf("%.2f\n", dist(cows[0], cows[1]));
        return 0;
    }

    sort(cows, cows + n);

    int k = 0;
    for (int i = 0; i < n; i++) {
        while (k >= 2 && !ccw(hull[k - 2], hull[k - 1], cows[i]))
            k--;
        hull[k++] = cows[i];
    }

    for (int i = n - 1, t = k + 1; i > 0; i--) {
        while (k >= t && !ccw(hull[k - 2], hull[k - 1], cows[i - 1]))
            k--;
        hull[k++] = cows[i - 1];
    }

    double ans = 0;
    for (int i = 0; i < k - 1; i++) {
        ans += dist(hull[i], hull[i + 1]);
        //cout << hull[i].first << " " << hull[i].second << endl;
    }
    printf("%.2f\n", ans);
}
