#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

struct Set {
    set<pair<int, int> > intervals;

    Set(pair<int, int> interval) {
        intervals.insert(interval);
    }

    Set intersect(pair<int, int> interval) {
        Set intersection;
        for (pair<int, int> i : this->intervals) {
            if (interval.first > i.second)
                break;

        }
        return intersection;
    }
};

map<int, Set> bales;

int main() {
    int n, q;
    cin >> n >> q;

    pair<int, int> qInt;
    int height;
    for (int i = 0; i < n; i++) {
        cin >> qInt.first >> qInt.second >> height;
        for (pair<int, Set> stackInterval : bales) {

        }
        //bales.insert(pair<int, Set> (height, Set(qInt)));
    }
}
