/*
Given a list of integers ending with the number 0, compute the average of the positive integers in the list

Example:
Input:
4 6 1 0

Output:
3.666666666666666
*/

#include <iostream>

using namespace std;

int main() {
    int a, b = 0, c = 0;
    cin >> a;
    while(a != 0) {
        if(a > 0)    //the if statement needs brackets
            b += a;
            c++;
        cin >> a;
    }
    double ans = 1.0*b/c;
    cout << ans << endl;
    return 0;
}
