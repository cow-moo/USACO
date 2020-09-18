#include <iostream>
using namespace std;

long long playTime[100050];
long long forgetTime[100050];
bool removed[100050];

int main() {
    int t;
    cin >> t;

    for (int z = 1; z <= t; z++) {
        int n;
        cin >> n;

        //time it takes to play 1 whole round
        long long roundTime = 0;
        for (int i = 0; i < n; i++) {
            cin >> playTime[i] >> forgetTime[i];
            roundTime += playTime[i];
            removed[i] = false;
        }

        int ansRemoved = 0;
        long long ansTime = 0;
        for (int i = 0; i < n; i++) {
            long long curTime = roundTime;
            bool r = false;
            for (int j = 0; j < n; j++) {
                if (removed[j])
                    continue;
                if (roundTime - playTime[j] >= forgetTime[j]) {
                    curTime += playTime[j];
                }
                else {
                    if (curTime > ansTime) {
                        ansRemoved = i;
                        ansTime = curTime;
                    }
                    removed[j] = true;
                    roundTime -= playTime[j];
                    r = true;
                    break;
                }
            }
            if (!r) {
                ansRemoved = i;
                ansTime = -1;
                break;
            }
        }
        cout << "Case #" << z << ": " << ansRemoved << " ";
        if (ansTime == -1) {
            cout << "INDEFINITELY" << endl;
        }
        else {
            cout << ansTime << endl;
        }
    }
}
