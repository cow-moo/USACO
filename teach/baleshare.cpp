#include <iostream>
using namespace std;

int bales[22];
int cur[1005][670];
int succ[1005][670];
//b >= c
int main() {
    int n, total = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> bales[i];
        total += bales[i];
    }

    cur[0][0] = true;
    succ[0][0] = true;

    for (int i = 0; i < n; i++) {
        for (int c = 0; c <= 667; c++) {
            for (int b = 0; b <= 1000; b++) {
                if ((b - bales[i] >= 0 && cur[b - bales[i]][c]) || (c - bales[i] >= 0 && cur[b][c - bales[i]]))
                    succ[b][c] = true;
            }
        }
        for (int c = 0; c <= 667; c++) {
            for (int b = 0; b <= 1000; b++) {
                cur[b][c] = succ[b][c];
            }
        }
    }

    int ans = 3000;
    for (int c = 0; c <= 667; c++) {
        for (int b = c; b <= 1000; b++) {
            if (cur[b][c]) {
                ans = min(ans, max(max(b, c) , total - b - c));
                //cout << total - b - c << " " << b << " " << c << endl;
            }
        }
    }

    cout << ans << endl;
}
