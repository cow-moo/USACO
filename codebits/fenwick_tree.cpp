#include <iostream>
using namespace std;
#define SIZE 1000

int bit[SIZE];

int sum(int i)
{
    int sum = 0;
    while (i > 0)
    {
        sum += bit[i];
        i -= (i) & -(i);
    }
    return sum;
}

void add(int i, int delta)
{
    while (i <= SIZE)
    {
        bit[i] += delta;
        i += (i) & -(i);
    }
}

int main()
{
    add(3, 3);
    //add(5, 34);
    //sum adds everything up to and including i
    cout << sum(3) - sum(2) << endl;
}
