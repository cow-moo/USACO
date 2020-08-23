#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 50050
#define MAXLG 20

char letters[MAXN];
char msg[MAXN];

struct Entry {
    int nr[2], p;
} L[MAXN];

int P[MAXLG][MAXN];
int suf[MAXN];

int cmp(Entry a, Entry b)
{
    return a.nr[0] == b.nr[0] ? (a.nr[1] < b.nr[1] ? 1 : 0) : (a.nr[0] < b.nr[0] ? 1 : 0);
}

int curSz, n;

bool comp(int a, int b) {
    for (int i = 0; i < curSz; i++) {
        if (letters[a + i] < msg[b + i])
            return true;
        else if (letters[a + i] > msg[b + i])
            return false;
    }
    return false;
}

//begin index, size
bool is_sub(int b) {
    int a = *lower_bound(suf, suf + n, b, comp);
    if (a == -1)
        return false;
    for (int i = 0; i < curSz; i++) {
        if (letters[a + i] != msg[b + i])
            return false;
    }
    return true;
}

int main() {
    int m;
    cin >> n >> m;

    int len = 0;
    string line;
    while (len != n) {
        cin >> line;
        for (int i = 0; i < line.size(); i++)
            letters[len++] = line[i];
    }
    letters[n] = '$';

    len = 0;
    while (len != m) {
        cin >> line;
        for (int i = 0 ; i < line.size(); i++)
            msg[len++] = line[i];
    }

    for (int i = 0; i < n; i++)
        P[0][i] = letters[i] - 'A';
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

    int beg = 0, ans = 0;
    while (beg < m) {
        int l = 1, r = m - beg;
        while (l < r) {
            curSz = r - (r - l) / 2;
            if (is_sub(beg) == 1) {
                l = curSz;
            }
            else {
                r = curSz - 1;
            }
        }
        beg += l;
        ans++;
    }
    cout << ans << endl;
}
/*
5 5
abacd
cdaaa
*/
