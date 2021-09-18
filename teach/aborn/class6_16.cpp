#include <iostream>
using namespace std;

/*
int arr[100];    initialize array; a row of variables/boxes
^    ^    ^
type name size

index i refers to the i+1th element
index 0 is the first element, index 1 is the first element, index n-1 is the last element

to access index i, use arr[i]
you can assign and use it like a normal variable
cout << arr[2] << endl;
arr[i] = 17;
cin >> arr[i];
sum += arr[i];
*/

int arr[100050];

int main()
{
    //reads a number n, then reads n numbers into an array
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

1. read a number n, then read n numbers. output the number in the middle (it is guaranteed that n is odd)

n = 5
0 1 2 3 4
middle is 2

n = 7
0 1 2 3 4 5 6
middle is 3

2. read a number n, then read n numbers. output the numbers in reverse order

3. read a number n, then read n numbers. output the sum of the array of numbers

4. read a number n, then read n numbers. output all the numbers in the array that are divisible by 3 or 5

arr[i] % 3 == 0 || arr[i] % 5 == 0

5. read a number n, then read n numbers. find if the sequence of numbers is symmetric. if it is, write "symmetric", otherwise write "not symmetric"
15 19 7 21 7 19 15
0  1  2 3  4 5  6
0 match n-1
1 match n-2
2 match n-3
3 match n-4

i match n-1-i

5, 7, ..., 75
