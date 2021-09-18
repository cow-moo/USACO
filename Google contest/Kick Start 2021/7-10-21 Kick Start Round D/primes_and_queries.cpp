#include <iostream>
using namespace std;
#define SIZE 100050

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

int getVal(long long a, long long s, long long p)
{
    long long a1 = 1;
    long long a2 = 1;

    for (int i = 0; i < s; i++)
    {
        a1 *= a;
        a2 *= a % p;
    }

    long long diff = a1 - a2;

    int res = 0;
    while (diff % p == 0)
    {
        diff /= p;
        res++;
    }
    return res;
}

int main()
{
    cout << getVal(67, 3, 2) << endl;
    int t;
    cin >> t;

    for (int z = 1; z <= t; z++)
    {
        long long n, q, p;

        for (int i = 0; i < n; i++)
        {
            long long inp;
            cin >> inp;

        }
    }
}
