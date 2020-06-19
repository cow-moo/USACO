/*
Check whether a given positive integer is prime

Example:
Input:
7

Output:
Prime
*/

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int a, i = 2;
    cin >> a;
    if(a == 1) {
        cout << "Not prime" << endl;
    } else {
        while(i < sqrt(a)) { //should be i <= sqrt(a) i*i <= a
            if(a % i == 0) {
                cout << "Not prime" << endl;
                return 0;
            }
            i++;
        }
        cout << "Prime" << endl;
    }
    return 0;
}
