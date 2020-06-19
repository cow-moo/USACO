#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

pair<long long, long long> intervals[100050];
int n, m;

bool check (long long dist) {
    long long curPos = intervals[0].first;
    int curInterval = 0;
    int curCow = 1;

    while (true) {
        curPos += dist;
        //cout << curPos << endl;
        for (; curInterval <= m; curInterval++) {
            if (curInterval == m)
                return false;
            if (intervals[curInterval].second >= curPos) {
                curPos = max(intervals[curInterval].first, curPos);
                curCow++;
                break;
            }
        }
        if (curCow == n)
            return true;
    }
}

int main() {
   freopen("socdist.in", "r", stdin);
   freopen("socdist.out", "w", stdout);

    cin >> n >> m;
    for (int  i = 0; i < m; i++)
    {
        cin >> intervals[i].first >> intervals[i].second;
    }
    sort(intervals, intervals + n);

    long long minimum = 1;
    long long maximum = intervals[n - 1].second + 1;
    long long mid;
    while (maximum > minimum)
    {
        mid = (maximum + minimum) / 2;
        if (!check (mid))
        {
            maximum = mid - 1;
        }
        else
            minimum = mid;
    }
    cout << mid << endl;
}
