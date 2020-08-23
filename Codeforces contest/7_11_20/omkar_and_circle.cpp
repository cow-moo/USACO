#include <iostream>
#include <set>
#include <map>
using namespace std;

//to find neighbors
map<int, long long> circle;
set<pair<long long, int> > curCircle;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        long long inp;
        cin >> inp;
        circle[i] = inp;
        curCircle.insert({inp, i});
    }

    for (int i = 0; i < (n - 1) / 2; i++) {
        pair<long long, int> minim = *curCircle.begin();
        curCircle.erase(curCircle.begin());
        long long newVal = 0;

        auto it = circle.find(minim.second);
        if (it == circle.begin())
            it = circle.end();
        it--;
        newVal += it->second;
        curCircle.erase({it->second, it->first});
        circle.erase(it);

        it = circle.find(minim.second);
        it++;
        if (it == circle.end())
            it = circle.begin();
        newVal += it->second;
        curCircle.erase({it->second, it->first});
        circle.erase(it);
        //cout << newVal << endl;

        curCircle.insert({newVal, minim.second});
        circle[minim.second] = newVal;
    }
    cout << curCircle.begin()->first << endl;
}
