#include <iostream>
#include <algorithm>
using namespace std;

bool comp(int a, int b) {
    return a > b;
}

int main(){
    int x[5] = {3, 4, 2, 1, 5};
    sort(x, x+5, comp);

    for (int i = 0; i < 5; i++) {
        cout << x[i] << endl;
    }
}
