#include <iostream>
#include <algorithm>
using namespace std;

bool sorty(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

pair<int, int> cows[100005];

int main() {
    int n, halfx, totalLeft, totalRight, ans;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> cows[i].first >> cows[i].second;
    }

    sort(cows, cows + n);
    halfx = cows[n - 1].first + 1;
    totalLeft = n;
    totalRight = 0;
    for (int i = (n + 1) / 2; i < n; i++) {
        if (cows[i].first != cows[i - 1].first) {
            totalLeft = i;
            totalRight = n - totalLeft;
            halfx = cows[i].first - 1;
            break;
        }
    }
    //cout << halfx << endl;
    //cout << totalLeft << " " << totalRight << endl;

    int leftc = 0, rightc = 0, minim = max(totalLeft, totalRight);
    sort(cows, cows + n, sorty);
    for (int i = 0; i < n; i++) {
        if (cows[i].first < halfx)
            leftc++;
        if (cows[i].first > halfx)
            rightc++;
        if (i != n - 1 && cows[i].second == cows[i + 1].second) {
            continue;
        }
        //cout << "s: " << leftc << " " << rightc << endl;
        if (max(max(leftc, totalLeft - leftc), max(rightc, totalRight - rightc)) < minim) {
            minim = max(max(leftc, totalLeft - leftc), max(rightc, totalRight - rightc));
        }
        else {
            ans = minim;
            break;
        }
    }
    //cout << ans << endl;

    sort(cows, cows + n);
    halfx = cows[0].first - 1;
    totalLeft = 0;
    totalRight = n;
    for (int i = n / 2 - 1; i >= 0; i--) {
        if (cows[i].first != cows[i + 1].first) {
            totalLeft = i + 1;
            totalRight = n - totalLeft;
            halfx = cows[i].first + 1;
            break;
        }
    }
    //cout << halfx << endl;
    //cout << totalLeft << " " << totalRight << endl;

    leftc = 0, rightc = 0, minim = max(totalLeft, totalRight);
    sort(cows, cows + n, sorty);
    for (int i = 0; i < n; i++) {
        if (cows[i].first < halfx)
            leftc++;
        if (cows[i].first > halfx)
            rightc++;
        if (i != n - 1 && cows[i].second == cows[i + 1].second) {
            continue;
        }
        //cout << "s: " << leftc << " " << rightc << endl;
        if (max(max(leftc, totalLeft - leftc), max(rightc, totalRight - rightc)) < minim) {
            minim = max(max(leftc, totalLeft - leftc), max(rightc, totalRight - rightc));
        }
        else {
            ans = min(ans, minim);
            break;
        }
    }

    cout << ans << endl;
}
