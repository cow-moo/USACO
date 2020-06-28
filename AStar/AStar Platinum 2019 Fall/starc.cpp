#include <iostream>
using namespace std;

struct Fraction {
    int n, d;
    bool operator<(Fraction const& other) {
        return n * other.d < d * other.n;
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    Fraction frac1 = {1, 2};
    Fraction frac2 = {2, 3};

    cout << (frac1 < frac2) << endl;
}
