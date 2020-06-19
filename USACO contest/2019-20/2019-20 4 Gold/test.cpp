#include <iostream>
using namespace std;

int main() {
    int a = 0;
    if (false && a++ > -10)
        cout << a << endl;
    cout << a << endl;
}
