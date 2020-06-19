#include <iostream>
#include <map>
#include <vector>
using namespace std;

//milk amount, count
map<int, int> milk;
map<int, int> half1;
vector<int> half2;
//diff, count

int main() {
    int n;
    cin >> n;

    int input;
    for (int i = 0; i < n; i++) {
        cin >> input;
        if (milk.count(input) == 0) {
            milk[input] = 1;
        }
        else {
            milk[input]++;
        }
    }

//    for (auto a : milk) {
//        cout << a.first << " " << a.second << endl;
//    }

    n = milk.size();

    map<int, int>::iterator curMilk = milk.begin();
    half1[0] = 1;
    for (int i = 0; i < n / 2; i++) {
        vector<int> temp;
        for (auto diff : half1) {
            for (int j = 0; j <= curMilk->second; j++) {
                //temp.push_back(diff.first + curMilk->first * j * 2 - curMilk->first * curMilk->second);
                //temp.push_back(diff.first - curMilk->first * j);

            }
        }
        for (auto a : temp) {
            if (half1.count(a) == 0) {
                half1[a] = 1;
            }
            else {
                half1[a]++;
            }
        }
        curMilk++;
    }

    for (auto a : half1)
        cout << a.first << " " << a.second << endl;

    half2.push_back(0);

    long long ans = 0;
    ans += half1[0];
    for (int i = n / 2; i < n; i++) {
        cout << " " << curMilk->first << " " << curMilk->second << endl;
        vector<int> temp;
        for (int diff : half2) {
            for (int j = 0; j <= curMilk->second; j++) {
                temp.push_back(diff + curMilk->first * j * 2 - curMilk->first * curMilk->second);
                //temp.push_back(diff.first - curMilk->first * j);
            }
        }
        for (int a : temp) {
            cout << a << endl;
            half2.push_back(a);
            if (half1.count(-a) > 0) {
                ans += half1[-a];
            }
        }
        curMilk++;
    }

    //cout << ans << endl;
    cout << (ans - 1) / 2 << endl;
}
