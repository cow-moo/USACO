#include <iostream>
using namespace std;
#define SIZE 200050

long long bit[SIZE];

long long sum(int i)
{
    long long sum = 0;
    while (i > 0)
    {
        sum += bit[i];
        i -= (i) & -(i);
    }
    return sum;
}

void add(int i, long long delta)
{
    while (i <= SIZE)
    {
        bit[i] += delta;
        i += (i) & -(i);
    }
}

int main()
{
    int n, q;
    cin >> n >> q;
    int prev = 0;
    for (int i = 1; i <= n; i++)
    {
        int val;
        cin >> val;
        add(i, val - prev);
        prev = val;
    }
    for (int i = 0; i < q; i++)
    {
        int inp;
        cin >> inp;
        if (inp == 1)
        {
            long long a, b, u;
            cin >> a >> b >> u;
            add(a, u);
            add(b + 1, -u);
        }
        else
        {
            long long k;
            cin >> k;
            cout << sum(k) << endl;
        }
    }
}