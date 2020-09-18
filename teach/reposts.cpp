#include <iostream>
#include <map>
using namespace std;

map<string, int> lengths;

int main() {
    int n;
    cin >> n;

    lengths["POLYCARP"] = 1;

    string name1, name2;
    for (int i = 0; i < n; i++) {
        cin >> name1 >> name2 >> name2;

        for (int i = 0; i < name1.size(); i++) {
            if (name1[i] >= 'a') {
                name1[i] += 'A' - 'a';
            }
        }
        for (int i = 0; i < name2.size(); i++) {
            if (name2[i] >= 'a') {
                name2[i] += 'A' - 'a';
            }
        }

        lengths[name1] = lengths[name2] + 1;
    }

    int ans = 0;
    for (pair<string, int> a : lengths) {
        ans = max(ans, a.second);
    }

    cout << ans << endl;
}
