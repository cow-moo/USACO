#include <iostream>
using namespace std;

/*
This program prints out the first n prime numbers in reverse order.
n <= 20
Input: 10
Output: 31 29 23 19 17 13 11 7 3 2
*/
//int arr[100000];
int main() {
	int n, count;//int n,count=0
	bool isprime = true;
	cin>>n;
	int arr[n];//should be global

	for (int i=2;i<1000;i++){
        isprime = true;
		for (int j=0;j<i;j++){//for (int j=2;j<i;j++){
			if (i % j == 0){
				isprime = false;
				break;
			}
		}
		if (isprime == true){
			count++;
			arr[count] = j;//arr[count] = i
		}
	}

	for (int i=n;i>0;i--){
		cout<<arr[i]<<" ";
	}
	return 0;
}
