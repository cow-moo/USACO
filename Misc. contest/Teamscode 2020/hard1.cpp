#include <iostream>
using namespace std;

bool used[25];
float prices[25];

int main() {
    int n;
    float p;
    cin >> n >> p;

    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    float profit = 0;
    int ans = 0;
    while (profit < p) {
        float maxp = 0;
        int a, b;
        for (int i = 0; i < n; i++) {
            if (used[i])
                continue;
            for (int j = i + 1; j < n; j++) {
                if (used[j])
                    continue;
                if (prices[j] - prices[i] > maxp) {
                    maxp = prices[j] - prices[i];
                    a = i; b = j;
                }
            }
        }
        profit += maxp;
        used[a] = true;
        used[b] = true;
        ans += 2;
    }

    cout << ans << endl;
}
/*
5 20
5.6 9 11.2 8.3 10.9 11.1
*/
