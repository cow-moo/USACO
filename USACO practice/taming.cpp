#include <iostream>
#include <stdio.h>
using namespace std;

int log[105];
int conditions[105][105]; //stores breakouts (1) or not breakouts (2) necessary for each day to be consistent
bool consistent[105]; //stores whether a log is consistent with current breakouts
bool breakouts[105]; //stores whether a breakout was on day i

char output[3] = {'_', 'X', 'O'};

int main() {
    freopen("taming.in", "r", stdin);
    freopen("taming.out", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> log[i];
        for (int j = i; j >= max(i - log[i] + 1, 0); j--) {
            conditions[i][j] = 2;
        }
        if (i - log[i] >= 0) {
            conditions[i][i - log[i]] = 1;
        }
    }

//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < n; j++) {
//            cout << output[conditions[i][j]] << " ";
//        }
//        cout << endl;
//    }

    int consistChange, maxim, maxIndex, counter = 0;
    for (int b = 1; b <= n; b++) {
        maxim = -1000;
        for (int j = 0; j < n; j++) {
            if (breakouts[j])
                continue;
            consistChange = 0;
            for (int i = 0; i < n; i++) {
                if (conditions[i][j] == 1 && consistent[i] == false) {
                    consistChange++;
                }
                else if (conditions[i][j] == 2 && consistent[i] == true) {
                    consistChange--;
                }
            }
            if (consistChange > maxim) {
                maxim = consistChange;
                maxIndex = j;
            }
        }
        for (int i = 0; i < n; i++) {
            if (conditions[i][maxIndex] == 1 && consistent[i] == false) {
                consistent[i] = true;
            }
            else if (conditions[i][maxIndex] == 2 && consistent[i] == true) {
                consistent[i] = false;
            }
        }
        breakouts[maxIndex] = true;
        counter += maxim;

        cout << n - counter << endl;
    }
}
