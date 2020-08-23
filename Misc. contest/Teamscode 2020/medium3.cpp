#include <iostream>
#include <stdio.h>
using namespace std;

char me[10050];
char f[10050];
int lengths[10050];

int main() {
    freopen("europeEscapade2.txt", "r", stdin);

    int n, myLength;
    cin >> n;

    cin >> myLength;
    for (int i = 0; i < n; i++) {
        cin >> lengths[i];
    }

    for (int i = 0; i < myLength; i++) {
        cin >> me[i];
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < lengths[i]; j++) {
            cin >> f[j];
        }

        int maxim = 0;
        for (int offset = -lengths[i] + 1; offset < myLength; offset++) {
            int cnt = 0;
            for (int j = 0; j < lengths[i]; j++) {
                if ((j + offset) >= 0 && (j + offset) < myLength) {
                    if (me[j + offset] == f[j]) {
                        cnt++;
                    }
                }
            }
            maxim = max(maxim, cnt);
        }
        ans += maxim;
    }
    cout << ans << endl;
}
/*
1
5 3
A Z Z Z B
Z B A
*/
