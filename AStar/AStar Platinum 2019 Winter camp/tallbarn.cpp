#include <iostream>
#include <cmath>
using namespace std;

int solve(long long a, double target) {
    return ceil((-1 + sqrt(1 + 4 * (double) a / target)) / 2);
}

long long barn[100000];
long long cows[100000];

int main() {
    long long n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> barn[i];
    }

    double l = 0;
    double r = 1e12;
    double mid;
    long long totalCows;
    for (int i = 0; i < 200; i++) {
        totalCows = 0;
        mid = (l + r) / 2;
        for (int i = 0; i < n; i++) {
            cows[i] = solve(barn[i], mid);
            totalCows += cows[i];
        }
        if (totalCows > k) {
            l = mid;
        }
        else if (totalCows < k) {
            r = mid;
        }
    }

    double ans = 0;
    for (int i = 0; i < n; i++) {
        ans += (double) barn[i] / (double) cows[i];
    }
    cout << (int) round(ans) << endl;
}
