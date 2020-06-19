#include <iostream>
#include <set>
using namespace std;

set<string> cards;

int main() {
    int n, k, ans = 0;
    cin >> n >> k;

    string inp;
    for (int i = 0; i < n; i++) {
        cin >> inp;
        cards.insert(inp);
    }

    for (set<string>::iterator it1 = cards.begin(); it1 != --cards.end(); it1++) {
        set<string>::iterator it2 = it1;
        it2++;
        for (; it2 != cards.end(); it2++) {
            //cout << *it1 << " " << *it2 << endl;
            string third = "";
            for (int i = 0; i < k; i++) {
                if (it1->at(i) == it2->at(i))
                    third += it2->at(i);
                else if (it1->at(i) != 'S' && it2->at(i) != 'S')
                    third += 'S';
                else if (it1->at(i) != 'E' && it2->at(i) != 'E')
                    third += 'E';
                else if (it1->at(i) != 'T' && it2->at(i) != 'T')
                    third += 'T';
            }
            //cout << *it1 << " " << *it2 << " " << third << endl;
            if (cards.count(third) > 0)
                ans++;
        }
    }
    cout << ans / 3 << endl;
}
