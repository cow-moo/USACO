#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

int milk[30];
map<int, int> globalCount;
int n;

void recurse1(set<int> possibleDiffs, int curIndex) {
    if (curIndex + 1 < n) {
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
    if (curIndex + 1 < n) {
        recurse1(newDiffs, curIndex + 1);
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> milk[i];
    }

    set<int> temp;
    temp.insert(0);
    recurse1(temp, 0);

    for (auto a : globalCount) {
        cout << a.first << " " << a.second << endl;
    }

    cout << globalCount[0] << endl;
}
/*
6 1 1 1 1 2 2
-4 1
-3 4
-2 7
-1 8
0 8
1 8
2 7
3 4
4 1
30

4 1 1 1 1
-4 1
-3 4
-2 7
-1 8
0 7
1 8
2 7
3 4
4 1
7

2 2 2
-4 1
-2 2
0 1
2 2
4 1
1
*/
