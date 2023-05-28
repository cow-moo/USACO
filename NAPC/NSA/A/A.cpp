#include <iostream>
#include <algorithm>

using namespace std;

int main() {

    int k, x;
    cin >> k >> x;
    int rr = k - x;
    int lr = k - rr;
    int l[lr], r[rr];

    for (int i = 0; i < lr; i++) {
        l[i] = i;
    }
    for (int i = 0; i < rr; i++) {
        r[i] = x + i;
    }
    do {
        do {
            for (int i = 0; i < lr; i++) {
                cout << l[i];
            }
            for (int j = 0; j < rr; j++) {
                cout << r[j];
            }
            cout << "\n";
        } while (next_permutation(r, r + rr));
    } while (next_permutation(l, l + lr));



    return 0;
}