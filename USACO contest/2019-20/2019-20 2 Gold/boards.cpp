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
    return (springboards[i].second.first - springboards[i].first.first) +
           (springboards[i].second.second - springboards[i].first.second);
}

void dfs(int curNode, int curSaved) {
    //could probably add curNode to springboards.begin()
    pair<pair<int, int>, pair<int, int> > temp = {{springboards[curNode].second.first, 0}, {0, 0}};
    for (int i = lower_bound(springboards.begin(), springboards.end(), temp) -
                 springboards.begin(); i <= p; i++) {
        if (springboards[i].first.second < springboards[curNode].second.second)
            continue;
        if (curSaved + savedDist(i) > maxSaved[i]) {
            maxSaved[i] = curSaved + savedDist(i);
            if (i != p)
                dfs(i, maxSaved[i]);
        }
    }
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
        springboards.push_back({{inp1, inp2}, {inp3, inp4}});
    }
    springboards.push_back({{0, 0}, {0, 0}});
    sort(springboards.begin(), springboards.end());
    springboards.push_back({{n, n}, {n, n}});

    dfs(0, 0);
    cout << 2 * n - maxSaved[p] << endl;
}
