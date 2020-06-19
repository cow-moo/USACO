/*
Calculate the sum of the first digits of the list of n positive integers

Example:
Input:
4
123 4 52 71

Output:
17
*/

#include <iostream>

using namespace std;

int main() {
	int n;
	int x;//x needs to be initialized to 0
	cin>>n; //need to get input for n
	for(int i = 0; i <= n; i++) { //should be i<n not i<=n
		int a;
		cin >> a;
		while(a >= 10) {
			a =/ 10;
            //should be /= not =/
		}
		x += a;
	}
	cout << x << endl;
	return 0;
}
