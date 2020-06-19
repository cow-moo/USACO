#include <iostream>
#include <algorithm>
using namespace std;

int slopes[105]; //min time slope for skill i
//time, length, skill
pair<pair<int, int>, int> lessons[105];
//lesson: largest run count by the start
int dp[105];

int main() {
    int t, s, n;
    cin >> t >> s >> n;

    for (int i = 0; i < s; i++) {
        cin >> lessons[i].first.first >> lessons[i].first.second >> lessons[i].second;
        dp[i] = -1;
    }
    //takes min for all times
    for (int i = 0; i < n; i++) {
        int sTime, sSkill;
        cin >> sSkill >> sTime;
        if (slopes[sSkill] == 0 || slopes[sSkill] > sTime)
            slopes[sSkill] = sTime;
    }

    int minim = 100000;
    for (int i = 1; i <= 100; i++) {
        if (slopes[i] != 0 && slopes[i] < minim)
            minim = slopes[i];
        else
            slopes[i] = minim;
        //cout << slopes[i] << endl;
    }

    lessons[s] = {{0, 0}, 1};
    dp[s] = -1;
    lessons[s + 1] = {{t, 0}, 0};
    dp[s + 1] = -1;
    sort(lessons, lessons + s + 2);

    for (int i = 0; i < s + 2; i++) {
        dp[i] = 0;
        for (int j = 0; j < i; j++) {
            int duration = lessons[i].first.first - (lessons[j].first.first + lessons[j].first.second);
            dp[i] = max(dp[i], dp[j] + duration / slopes[lessons[j].second]);
        }
    }

    cout << dp[s + 1] << endl;
}
/*
10 1 3
3 2 5
4 1
4 2
1 3
*/
