/*
Prints the number's digits that divide the number

Example:
Input:
123

Output:
3
1
*/

#include <iostream>

using namespace std;

int main() {
	int x;
	cin >> x;
	int y = x;
	while (y > 0) {
        //add if (y % 10 != 0) for lines 23-25
		if (x % (y % 10) == 0) {
			cout << y % 10 << '\n';
		}
		y /= 10;
	}
	return 0;
}
