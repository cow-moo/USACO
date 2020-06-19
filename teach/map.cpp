#include <iostream>
#include <map>
#include <stdio.h>
using namespace std;
/*
6
MIAMI FL MIFL
DALLAS TX DATX
FLINT MI FLMI
CLEMSON SC CLSC
BOSTON MA BOMA
ORLANDO FL ORFL
8
MIAMI FL
DALLAS TX
FLINT MI
CLEMSON SC
BOSTON MA
ORLANDO FL
MIAMI FL
FLINT MI
3
AA AA
AA AA
AA AA
*/
map<string, int> citystates;

int main() {
    freopen("citystate.in", "r", stdin);
    freopen("citystate.out", "w", stdout);
    int n;
    long long ans = 0;
    cin >> n;

    string city, state;
    for (int i = 0; i < n; i++) {
        cin >> city >> state;

        string rev = state + city.substr(0, 2);
        if (citystates.find(rev) != citystates.end()) {
            ans += citystates[rev];
        }

        string citystate = city.substr(0, 2) + state;
        if (citystates.find(citystate) == citystates.end()) {
            citystates[citystate] = 1;
        }
        else {
            citystates[citystate]++;
        }
    }

//    for (map<string, int>::iterator it = citystates.begin(); it != citystates.end(); it++) {
//        cout << it->first << " " << it->second << endl;
//    }

    cout << ans << endl;
}
