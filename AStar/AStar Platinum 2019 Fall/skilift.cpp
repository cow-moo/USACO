#include <iostream>
using namespace std;
#define MAXN 5005
#define INF 100000

int minSupports[MAXN];//minsupports needed, given there is a support at i
int heights[MAXN];

int main() {
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> heights[i];
        minSupports[i] = INF;
    }

    minSupports[0] = 1;
    for (int i = 1; i < n; i++) {
        long long yMin = 1, xMin = 0;
        for (int j = i - 1; j >= max(0, i - k); j--) {
            long long yDiff = heights[i] - heights[j];
            long long xDiff = i - j;
            if (yDiff * xMin <= yMin * xDiff) {
                yMin = yDiff;
                xMin = xDiff;
                if (minSupports[j] != INF) {
                    minSupports[i] = min(minSupports[i], minSupports[j] + 1);
                }
            }
        }
        //cout << minSupports[i] << endl;
    }

    cout << minSupports[n - 1] << endl;
}
