#include <iostream>
#include <iomanip>
using namespace std;

int getDigit(int n, int i)
{
    for (int j = 0; j < i; j++)
        n /= 10;
    return n % 10;
}

int main()
{
    cout << -4 + 7 / 3 % 5 << endl;
}