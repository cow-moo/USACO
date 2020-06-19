#include <iostream>
#include <stdio.h>
using namespace std;

int cows[100050];
int keys[100050];
int ans[100050];
int cLength[100050];
//1 2 3 4 5 6 7
//1 5 7 6 2 3 4
//i -> keys[keys[keys[keys[i]]]]

//1 2 3 4 5 6 7
//1 5 6 7 2 4 3
void reverse_it(int start, int ending)
{
    while (start < ending)
    {
        int temp = cows[start];
        cows[start] = cows[ending];
        cows[ending] = temp;
        start++;
        ending--;
    }
}

int main() {
    freopen("swap.in", "r", stdin);
    freopen("swap.out", "w", stdout);
    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) {
        cows[i] = i;
    }

    int l, r;

    for (int i = 0; i < m; i++) {
        cin >> l >> r;
        reverse_it(l, r);
    }

    for (int i = 1; i <= n; i++) {
        keys[cows[i]] = i;
    }

    for (int i = 1; i <= n; i++) {
        int curCycle = i, cycleLength = cLength[i];
        if (cLength[i] == 0) {
            do {
                curCycle = keys[curCycle];
                cycleLength++;
            } while (curCycle != i);
            for (int j = 0; j < cycleLength; j++) {
                cLength[curCycle] = cycleLength;
                curCycle = keys[curCycle];
            }
        }
        int pos = k % cycleLength;
        for (int j = 0; j < pos; j++) {
            curCycle = keys[curCycle];
        }
        ans[curCycle] = i;
        //cout << i << " " <<     cycleLength << endl;
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << endl;
    }

/*
1 1
2 2
3 4
4 4
5 2
6 4
7 4
*/

//    for (int i = 1; i <= n; i++) {
//        cout << keys[i] << " ";
//    }

//    for (int i = 1; i <= n; i++) {
//        cout << cows[i] << " ";
//    }
}
