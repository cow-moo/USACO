#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int milk[30];
map<int, int> globalCount;
int n, half, ans = 0;

void recurse1(set<int> possibleDiffs, int curIndex) {
    if (curIndex + 1 < half) {
        recurse1(possibleDiffs, curIndex + 1);
    }
    //calculate new set of diffs
    set<int> newDiffs;
    for (auto diff : possibleDiffs) {
        newDiffs.insert(diff - milk[curIndex]);
        newDiffs.insert(diff + milk[curIndex]);
    }
    //add to globalCount
    for (auto diff : newDiffs) {
        //cout << diff << " ";
        if (globalCount.count(diff) == 0) {
            globalCount[diff] = 1;
        }
        else {
            globalCount[diff]++;

        }
    }
    //recurse
    if (curIndex + 1 < half) {
        recurse1(newDiffs, curIndex + 1);
    }
}

void recurse2(set<int> possibleDiffs, int curIndex) {
    if (curIndex + 1 < n) {
        recurse2(possibleDiffs, curIndex + 1);
    }
    //calculate new set of diffs
    set<int> newDiffs;
    for (auto diff : possibleDiffs) {
        newDiffs.insert(diff - milk[curIndex]);
        newDiffs.insert(diff + milk[curIndex]);
    }
    //add to ans
    for (auto diff : newDiffs) {
        //cout << diff << " ";
        if (globalCount.count(diff) > 0 && diff >= 0) {
            ans += globalCount[diff];
            //cout << diff << endl;
        }
    }
    //recurse
    if (curIndex + 1 < n) {
        recurse2(newDiffs, curIndex + 1);
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> milk[i];
    }

    sort(milk, milk + n);

    for (int i = n / 2 - 1; i >= 0; i--) {
        if (milk[i] != milk[i + 1]) {
            half = i + 1;
            break;
        }
    }
    for (int i = n / 2; i < n; i++) {
        if (milk[i] != milk[i - 1]) {
            half = i;
            break;
        }
    }
//    cout << half << endl;
//
//    cout << endl;
//    for (int i = 0; i < half; i++) {
//        cout << milk[i] << endl;
//    }
//    cout << endl;
//    for (int i = half; i < n; i++) {
//        cout << milk[i] << endl;
//    }

    set<int> temp;
    temp.insert(0);
    recurse1(temp, 0);
    globalCount[0]++; //empty set

    for (auto a : globalCount) {
        cout << a.first << " " << a.second << endl;
    }

    recurse2(temp, half);

    cout << ans + globalCount[0] - 1 << endl;
    //for (auto a : globalCount) {
        //cout << a.first << " " << a.second << endl;
    //}
}
