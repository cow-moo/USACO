#include <iostream>
using namespace std;

/*
This program reads in n numbers and prints out every other number,
starting from the first number

Input: 5 1 2 3 4 5
Output: 1 3 5
*/
//int arr[100000];
int main() {
	int n, arr[n];//array should be global
	cin>>n;
	for (int i = 0; i <= n; i++){//for (int i = 0; i < n; i++){
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++){//for (i = 0; i < n; i+=2){
		cout << arr[n]; //cout << arr[i] << " "
	}
	return 0;
}
