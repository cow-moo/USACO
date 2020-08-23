#include <iostream>
using namespace std;

//struct Fraction {
//    int n, d;
//    bool operator<(Fraction const& other) {
//        return n * other.d < d * other.n;
//    }
//};

//as1 + bs2 + cs3 >= 0
struct Battle {
    int s1, s2, s3;
};

Battle tests[305];

int main() {
    int n, m;
    cin >> n >> m;

    char winner;
    int j1, j2, j3, b1, b2, b3;
    for (int i = 0; i < n; i++) {
        cin >> winner >> j1 >> j2 >> j3 >> b1 >> b2 >> b3;
        if (winner == 'J') {
            tests[i] = {j1 - b1, j2 - b2, j3 - b3};
        }
        else {
            tests[i] = {b1 - j1, b2 - j2, b3 - j3};;
        }
    }
    //Fraction frac1 = {1, 2};
    //Fraction frac2 = {2, 3};

    //cout << (frac1 < frac2) << endl;
}
