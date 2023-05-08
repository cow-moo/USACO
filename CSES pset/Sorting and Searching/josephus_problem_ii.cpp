#include <iostream>
using namespace std;
#define SIZE 200005

int bit[SIZE];

int sum(int i)
{
    i++;
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
    i++;
    while (i <= SIZE)
    {
        bit[i] += delta;
        i += (i) & -(i);
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        add(i, 1);
    }

    int cur = 1;
    for (int i = n; i > 0; i--)
    {
        cur = (cur + k) % i;
        if (cur == 0)
            cur = i;

        int l = 0, r = n - 1;
        while (l < r)
        {
            int m = (l + r) / 2;
            if (sum(m) >= cur)
            {
                r = m;
            }
            else
            {
                l = m + 1;
            }
        }

        cout << l + 1 << " ";
        add(l, -1);
        //cout << 'c' << cur << endl;
        //cur = l;
    }
    cout << endl;
}

//0 1 2 3 4 5 6
//1 0 0 1 1 0 1
//3, 5, 2, 4