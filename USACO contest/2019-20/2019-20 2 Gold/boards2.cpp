#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define MAXP 100050
#define TYPE vector<pair<pair<int, int>, pair<int, int> > >

int p;
int maxSaved[MAXP];
TYPE springboards;

int savedDist(int i) {
    return (springboards[i].first.first - springboards[i].second.first) +
           (springboards[i].first.second - springboards[i].second.second);
}

int bit[MAXP];

int getmax(int r) {
    int ret = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1)
        ret = max(ret, bit[r]);
    return ret;
}

void update(int idx, int val) {
    for (; idx < MAXP; idx = idx | (idx + 1))
        bit[idx] = max(bit[idx], val);
}

int main() {
    freopen("boards.in", "r", stdin);
    freopen("boards.out", "w", stdout);

    int n;
    cin >> n >> p;

    int inp1, inp2, inp3, inp4;
    for (int i = 0; i < p; i++) {
//        cin >> springboards[i].first.first >> springboards[i].first.second
//            >> springboards[i].second.first >> springboards[i].second.second;
        cin >> inp1 >> inp2 >> inp3 >> inp4;
        springboards.push_back({{inp4, inp3}, {inp2, inp1}});
        //endY, endX, beginY, beginX
    }
    //springboards.push_back({{0, 0}, {0, 0}});
    sort(springboards.begin(), springboards.end());
    //springboards.push_back({{n, n}, {n, n}});

    vector<pair<pair<int, int>, bool> > changepts;

    for (int i = 0; i < p; i++) {
        changepts.push_back({{springboards[i].second.second, i}, 0});
        changepts.push_back({{springboards[i].first.second, i}, 1});
    }

    sort(changepts.begin(), changepts.end());

    for (auto pt : changepts) {
        //cout << pt.first.first << " " << pt.first.second << " " << pt.second << endl;
        if (!pt.second) {
            //start
            pair<pair<int, int>, pair<int, int> > temp = {springboards[pt.first.second].second, {0, 0}};
            maxSaved[pt.first.second] = savedDist(pt.first.second) +
                                        getmax(upper_bound(springboards.begin(), springboards.end(), temp) - springboards.begin() - 1);
            //cout << maxSaved[pt.first.second] << endl;
        }
        else {
            //end
            update(pt.first.second, maxSaved[pt.first.second]);
        }
    }

    cout << 2 * n - getmax(p) << endl;
}

