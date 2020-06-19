/*
Prints the int in [0,100) that appears the most and is the largest for ties

Example:
Input:
5
3 3 2 2 8

Output:
3
*/

#include <iostream>

using namespace std;

int f[100];

int main() {
	int n; cin >> n;
	int k = 0;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		f[x]++;
		if (f[x] > f[k]) {
			k = x;
		}
		/*else if(f[x]==f[k] && x>k){
            k = x;
		}*/
	}
	cout << k << '\n';
	return 0;
}
