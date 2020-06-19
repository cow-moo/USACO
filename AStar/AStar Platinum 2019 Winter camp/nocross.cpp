#include <iostream>
#include <set>
using namespace std;
#define MAXN 100050

int bit[MAXN];

//up to and including r
int getmax(int r) {
    int ret = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1)
        ret = max(ret, bit[r]);
    return ret;
}

void update(int idx, int val) {
    for (; idx < MAXN; idx = idx | (idx + 1))
        bit[idx] = max(bit[idx], val);
}

int side1[MAXN];
int side2[MAXN];
//pos of each field on side2
int pos[MAXN];

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> side1[i];
        side1[i]--;
    }
    for (int i = 0; i < n; i++) {
        cin >> side2[i];
        side2[i]--;
        pos[side2[i]] = i;
    }

    for (int i = 0; i < n; i++) {
        set<int, greater<int> > posSet;
        for (int j = max(0, side1[i] - 4); j <= min(n - 1, side1[i] + 4); j++) {
            //cout << side1[i] + 1 << " " << j + 1 << endl;
            posSet.insert(pos[j]);
        }
        for (auto field : posSet) {
            if (field - 1 >= 0) {
                update(field, getmax(field - 1) + 1);
            }
            else {
                update(field, 1);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, getmax(i));
    }
    cout << ans << endl;
}
