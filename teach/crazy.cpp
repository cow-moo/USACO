#include <iostream>
#include <map>
using namespace std;

pair<pair<int, int>, pair<int, int> > fences[1050];
pair<int, int> cows[1050];
map<pair<int, int>

int main() {
    int n, c;
    cin >> n >> c;

    for (int i = 0; i < n; i++) {
        cin >> fences[i].first.first >> fences[i].first.second >> fences[i].second.first >> fences[i].second.second;
    }
    for (int i = 0; i < c; i++) {
        cin >> cows[i];
    }


}
