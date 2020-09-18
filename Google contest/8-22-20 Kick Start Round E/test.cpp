#include <iostream>
#include <vector>
using namespace std;

vector<int> test[100];

int main() {
//    vector<vector<int> > test;
//    for (int i = 0; i < 3; i++) {
//        vector<int> x;
//        x.push_back(i);
//        test.push_back(x);
//    }
//
//    cout << test[2][0] << endl;

    for (int a : test[0]) {
        cout << a << endl;
    }
}
