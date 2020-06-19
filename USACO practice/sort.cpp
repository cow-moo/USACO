#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <set>
using namespace std;

int A[100000];
set< pair< int, int > > sortedA;
//pair<pair<int, int>, bool> sortedA[100000];

int main() {
    freopen("sort.in", "r", stdin);
    freopen("sort.out", "w", stdout);
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> A[i];
        //sortedA[i].make_pair(make_pair(A[i], i), true);
        sortedA.insert(make_pair(A[i], i));
    }
    //sort(sortedA, sortedA + n);

    int m = 0, maxim = 0;
    for (int i = 0; i < n; i++) { //move line to pos i
        if (sortedA.count(make_pair(A[i], i)))
            m++;
        if ((*sortedA.begin()).second <= i)
            m--;
        sortedA.erase(sortedA.begin());

        maxim = max(maxim, m);
        //cout << i << " " << m << endl;
    }
    if (maxim == 0)
        cout << 1 << endl;
    else
        cout << maxim << endl;
}
