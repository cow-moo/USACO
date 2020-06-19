#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

pair<int, int> trees[305];
int treesUnder[305][305];
int valueCount[300];
//trees under line i-j,

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> trees[i].first >> trees[i].second;
    }

    sort(trees, trees + n);

    for (int i = 0; i < n; i++) { //i < j
        for (int j = i + 1; j < n; j++) {
//            if (trees[i].first == trees[j].first)
//                continue;
            for (int k = 0; k < n; k++) {
                if (k == i || k == j )
                    continue;
                if (trees[k].first > trees[i].first && trees[k].first <= trees[j].first) {
                    //(trees[k].first > trees[j].first && trees[k].first <= trees[i].first)) {
                    //xDiff positive
                    long long xDiff = trees[j].first - trees[i].first;
                    long long yDiff = trees[j].second - trees[i].second;
                    if (yDiff * (long long) (trees[k].first - trees[i].first) > xDiff * (long long) (trees[k].second - trees[i].second)) {
                        treesUnder[i][j]++;
                    }
                }
            }
        }
    }

    int cnt;
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                cnt = treesUnder[i][j] + treesUnder[j][k] - treesUnder[i][k];
                if (cnt < 0)
                    cnt = -cnt - 1;
                //cout << treesUnder[i][j] << " " << treesUnder[j][k] << " " << treesUnder[i][k] << endl;
                //if (cnt == 3) {
                    //cout << i << " " << j << " " << k << endl;
                //}
                valueCount[cnt]++;
            }
        }
    }
    for (int i = 0; i < n - 2; i++) {
        cout << valueCount[i] << endl;
    }
}
