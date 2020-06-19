#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
using namespace std;

vector< pair<int, int> > change;

int main() {
    freopen("teleport.in", "r", stdin);
    freopen("teleport.out", "w", stdout);

    int n, a, b;
    long long sum = 0;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        sum += abs(a - b);

        if (abs(a) >= abs(a - b)) {
            continue;
        }
        change.push_back(make_pair(b, 2)); //-1 to 1
        if ( (a < 0 && 0 < b) || (b < 0 && 0 < a)) {
            change.push_back(make_pair(0, -1));
            change.push_back(make_pair(2 * b, -1));
        }
        else {
            change.push_back(make_pair(2 * a, -1));
            change.push_back(make_pair(2 * b - 2 * a, -1));
        }
    }
    long long minim = sum;

    sort(change.begin(), change.end());

    int slope = change[0].second;
    for (int i = 1; i < change.size(); i++) {
        sum += slope * (change[i].first - change[i - 1].first);
        slope += change[i].second;

        minim = min(minim, sum);
    }

    cout << minim << endl;
}
