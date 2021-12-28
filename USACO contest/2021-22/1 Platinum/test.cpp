#include <iostream>
using namespace std;

int main()
{
    int a;
    cin >> a;
    cout << a;
    int arr[5] = {1, 2, 3, 4, 5};
    auto test = lower_bound(arr, arr + 5, 3);
    cout << *test << endl;
}
