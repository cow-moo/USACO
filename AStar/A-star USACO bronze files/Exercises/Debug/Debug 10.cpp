#include <iostream>
using namespace std;

/*
Given a list of numbers, for each number n, find the tens digit of 3^n,
it is guaranteed no number is greater than 22.
Input:
4
2 7 3 5
Output:
0 8 2 4
*/

int main() {
	int n;
	cin>>n>>tmp; //shouldn't have >>tmp
	int tmp, tmp2;//this needs to be initialized before line 16
	for (int i=n;i>=0;i--){//for (int i=n;i>0;i--){
		cin>>tmp;
		tmp2 = 0; //tmp2 = 1
		for (int i=1;i<=n;i++){//for (int i=1;i<=tmp;i++){
			tmp2 *= 3;
		}
		cout << tmp2 % 100 << " "; //(tmp2/10) % 10
	}
}
