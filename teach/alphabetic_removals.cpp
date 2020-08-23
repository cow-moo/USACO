#include <iostream>
#include <list>
using namespace std;

list<char> l;

int main() {
    int n, k;
    string str;
    cin >> n >> k >> str;

    for (int i = 0; i < n; i++) {
        l.push_back(str[i]);
    }

    for (char i = 'a'; i <= 'z'; i++) {
        for (list<char>::iterator it = l.begin(); it != l.end(); it++) {
            if (*it == i) {
                it = l.erase(it);
                k--;
            }
            if (k == 0) {
                break;
            }
        }
        if (k == 0) {
            break;
        }
    }

    for (list<char>::iterator it = l.begin(); it != l.end(); it++) {
        cout << *it;
    }
}
