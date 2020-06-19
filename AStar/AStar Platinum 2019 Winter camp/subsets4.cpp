#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int milk[30];
vector<set<int> > subsetDiffs;
//set of possible differences for each subset
int n, half, ans = 0;
int c = 0;

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
    subsetDiffs.push_back(newDiffs);
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
    for (auto subset : subsetDiffs) {
        set<int>::iterator it1 = subset.begin();
        set<int>::iterator it2 = newDiffs.begin();
        while(it1 != subset.end() && it2 != newDiffs.end()) {
            //c++;
            if (*it1 > *it2) {
                it2++;
            }
            else if (*it1 < *it2) {
                it1++;
            }
            else {
                ans++;
                break;
            }
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

    set<int> temp;
    temp.insert(0);
    recurse1(temp, 0);
    subsetDiffs.push_back(temp);

    recurse2(temp, half);

    //cout << c << endl;

    for (auto subset : subsetDiffs) {
        for (auto diff : subset) {
            if (diff == 0)
                ans++;
        }
    }

    cout << ans - 1 << endl;
}

