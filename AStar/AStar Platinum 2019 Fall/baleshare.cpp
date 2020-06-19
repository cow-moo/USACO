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
        for (int b = bales[i]; b <= 1000; b++) {
            for (int c = bales[i]; c <= 667; c++) {
                if ((cur[b - bales[i]][c] || cur[b][c - bales[i]]))// && b >= c)
                    succ[b][c] = true;
            }
        }
        for (int b = 0; b <= 1000; b++) {
            for (int c = 0; c <= 667; c++) {
                cur[b][c] = succ[b][c];
            }
        }
    }

    for (int b = 0; b <= 1000; b++) {
        for (int c = 0; c <= 667; c++) {
            if (cur[b][c])
                cout << b << " " << c << endl;
        }
    }
}
