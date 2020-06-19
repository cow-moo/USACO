/*
Given a list of n integers, find the minimum in the list BEFORE encountering the 0

Example:
Input:
5
3 2 0 5 1

Output:
2
*/

#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int a[n];
	bool c = false;
	for (int i = 0; i < n && !c; i++) { //there shouldn't be !c
		cin >> a[i];
		if (a[i] == 0) c = true;
	}

	int o = 1000000000; // this is not the bug
	for (int i = 0; i < n; i++) { //make it i < n && a[i]
		if (a[i] < o) o = a[i];
	}

	cout << o << '\n';
	return 0;
}
