#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 50050
#define MAXLG 20

struct Entry {
    int nr[2], p;
} L[MAXN];

int P[MAXLG][MAXN];
int suf[MAXN];

int cmp(Entry a, Entry b)
{
    return a.nr[0] == b.nr[0] ? (a.nr[1] < b.nr[1] ? 1 : 0) : (a.nr[0] < b.nr[0] ? 1 : 0);
}

char arr[MAXN];

int main() {
    for (int i = 0; i < n; i++)
        P[0][i] = arr[i] - 'A';
    int stp, cnt;
    for (stp = 1, cnt = 1; cnt >> 1 < n; stp++, cnt <<= 1) {
        for (int i = 0; i < n; i++) {
            L[i].nr[0] = P[stp - 1][i];
            L[i].nr[1] = i + cnt < n ? P[stp - 1][i + cnt] : -1;
            L[i].p = i;
        }
        sort(L, L + n, cmp);
        for (int i = 0; i < n; i++)
            P[stp][L[i].p] = i > 0 && L[i].nr[0] == L[i - 1].nr[0] && L[i].nr[1] == L[i - 1].nr[1] ? P[stp][L[i - 1].p] : i;
    }

    for (int i = 0; i < n; i++) {
        suf[P[stp - 1][i]] = i;
    }
    suf[n] = -1;
}


