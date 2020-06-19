#include <iostream>
using namespace std;

/*
This program takes a list of n numbers, and swaps the first and last,
the second and second last, and so on.
Input: 5 1 2 3 4 5
Output: 5 4 3 2 1
*/
//int arr[100000];
int main() {
    //int n;
	cin>>n;
	int arr[n];
	for (int i=n+5;i>=5;i--){//for (int i=n-1;i>=0;i--){
		cin>>arr[i];
	}
	for (int i=0;i<n;i++){
		arr[i] = arr[n-i];//delete 19 and 20
		arr[n-i] = arr[i];
		//cout<<arr[i]<<" ";
	}
	return 0;
}
