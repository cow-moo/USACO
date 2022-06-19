#include <iostream>
using namespace std;
#define SIZE 1000

int bit[SIZE];

int getMax(int i)
{
    int res = 0;
    while (i > 0)
    {
        res = max(res, bit[i]);
        i -= (i) & -(i);
    }
    return res;
}

void addValue(int i, int value)
{
    while (i <= SIZE)
    {
        bit[i] = max(bit[i], value);
        i += (i) & -(i);
    }
}

int main()
{
    //addValue(3, 3);
    //addValue(5, 5);
    addValue(3, 3);
    //add(5, 34);
    //sum adds everything up to and including i
    //cout << sum(3) - sum(2) << endl;
    cout << getMax(5) << endl;
}
