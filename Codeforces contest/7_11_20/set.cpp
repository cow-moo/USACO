#include <iostream>
#include <set>
using namespace std;

int main() {
    set<pair<int, int> > f;
    for (int i = 0; i < 4; i++) {
        f.insert({i, i});
    }



    for (auto a : f) {
        cout << a.first << " " << a.second << endl;
    }
}
