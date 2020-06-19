#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 100005
#define INF 1000000000

int bit[MAXN];

int sum(int idx) {
    int ret = 0;
    for (; idx > 0; idx -= idx & -idx)
        ret += bit[idx];
    return ret;
}

void add(int idx, int delta) {
    for (++idx; idx < MAXN; idx += idx & -idx)
        bit[idx] += delta;
}

pair<pair<int, int>, int> cows[MAXN];
int cowsy[MAXN];

bool comp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
    return a.first.second < b.first.second;
}

int main() {
    int n, ans = INF;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> cows[i].first.first >> cows[i].first.second;
    }

    sort(cows, cows + n, comp);

    for (int i = 0; i < n; i++) {
        cows[i].second = i;
        cowsy[i] = cows[i].first.second;
    }

    sort(cows, cows + n);

//    for (int i = 0; i < n; i++) {
//        cout << cowsy[i] << endl;
//    }

    //build fence before cow i
    for (int i = 0; i < n; i++) {
        if (i != 0 && cows[i].first.first != cows[i - 1].first.first) {
            //build fence below of i
            int l = 1;
            int r = n - 1;

            while (r > l) {
                int mid1 = l + (r - l) / 3;
                int mid2 = r - (r - l) / 3;

                while(mid1 < n - 1 && cowsy[mid1] == cowsy[mid1 + 1]) mid1++;
                while(mid2 > 1 && cowsy[mid2] == cowsy[mid2 - 1]) mid2--;
                mid1++;

                //cout << cowsy[mid2] << " " << cowsy[mid2 - 1] << endl;

                int maxCows1 = max(max(i - sum(mid1), n - i - mid1 + sum(mid1)), max(sum(mid1), mid1 - sum(mid1)));
                int maxCows2 = max(max(i - sum(mid2), n - i - mid2 + sum(mid2)), max(sum(mid2), mid2 - sum(mid2)));

//                cout << "x = " << cows[i].first.first - 1 << endl;
//                cout << "y = " << cowsy[mid2] - 1 << endl;
//                cout << n - i - mid2 + sum(mid2) << endl;
//                cout << endl;

                ans = min(ans, min(maxCows1, maxCows2));

                if (maxCows1 >= maxCows2) {
                    l = mid1 + 1;
                }
                if (maxCows1 <= maxCows2) {
                    r = mid2 - 1;
                }
            }
            //cout << i << " " << ans << endl;
        }
        add(cows[i].second, 1);
    }
    cout << ans << endl;
}
