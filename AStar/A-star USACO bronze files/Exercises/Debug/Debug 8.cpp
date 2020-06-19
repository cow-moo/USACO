/*
Add all even digits in a positive integer n

Example:
Input:
682347

Output:
20
*/

#include <iostream>

using namespace std;

int main() {
    int sum; //needs to initialize sum as 0
    //int n;   needs to declare n
    cin >> n;
    while (n >= 0) { //should be n>0 not n>=0
        if (n%2 == 0) {
            sum += n%2; //should be sum+=n%10 not sum+= n%2
        }
        n/10; //should be n/=10 not n/10
    }
    cout << n << endl; //should cout << sum << endl;
    return 0;
}
