#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>
using namespace std;

//will deal with distance squared
pair<int, int> cows[50050];
int ids[50050];
pair<int, int> ans = {50001, 50001};
int totalmin = 1000000000;

int dist(int a, int b) {
    return (cows[b].first - cows[a].first) * (cows[b].first - cows[a].first) +
           (cows[b].second - cows[a].second) * (cows[b].second - cows[a].second);
}

bool comp1(int a, int b) {
    return cows[a].first < cows[b].first;
}

bool comp2(int a, int b) {
    return cows[a].second < cows[b].second;
}

int closest(int frst, int last) {
    if (frst + 1 >= last)
        return 1000000000;
    //cout << first << " " << last << endl;
    //line at cows[mid].first, ones on line may not be on the same side
    int mid = (frst + last) / 2;//lower_bound(ids + frst, ids + last, ids[(frst + last) / 2], comp1) - ids;
    //cout << frst << " " << mid << " " << last << endl;

    int c = min(closest(frst, mid), closest(mid, last));

    vector<int> slice;
    for (int i = frst; i < last; i++) {
        if ((cows[ids[i]].first - cows[ids[mid]].first) * (cows[ids[i]].first - cows[ids[mid]].first) <= c) {
            slice.push_back(ids[i]);
        }
    }
    sort(slice.begin(), slice.end(), comp2);

    for (int i = 0; i < slice.size(); i++) {
        for (int j = i + 1; j < min((int) slice.size(), i + 12); j++) {
            c = min(c, dist(slice[i], slice[j]));
            if (dist(slice[i], slice[j]) == 1)
                cout << slice[i] << " a " << slice[j] << endl;
            if (dist(slice[i], slice[j]) < totalmin) {
                ans = {min(slice[i], slice[j]), max(slice[i], slice[j])};
                //cout << "a" << ans.first << " " << ans.second << " " << dist(slice[i], slice[j]) << endl;
                totalmin = dist(slice[i], slice[j]);
            }
            else if (dist(slice[i], slice[j]) == totalmin &&
                   (min(slice[i], slice[j]) < ans.first || (min(slice[i], slice[j]) == ans.first && max(slice[i], slice[j]) < ans.second))) {
                    //cout << ans.first << " " << ans.second << endl;
                ans = {min(slice[i], slice[j]), max(slice[i], slice[j])};
            }
        }
    }
    return c;
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> cows[i].first >> cows[i].second;
        ids[i] = i;
    }

    sort(ids, ids + n, comp1);

//    cout << endl;
//    for (int i = 0; i < n; i++) {
//        //cout << ids[i] << endl;
//        cout << i << ": " << cows[ids[i]].first << " " << cows[ids[i]].second << endl;
//    }
//    cout << endl;

    closest(0, n);
    //cout << closest(0, n) << endl;

    //cout << cows[ans.first].first << " " << cows[ans.first].second << " to " << cows[ans.second].first << " " << cows[ans.second].second << endl;

    //cout << 'd' << dist(ans.first, ans.second) << endl;
    cout << ans.first + 1 << " " << ans.second + 1 << endl;
}
