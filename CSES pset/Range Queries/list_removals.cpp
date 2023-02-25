#include <iostream>
using namespace std;
#define SIZE 200050

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

int arr[SIZE];

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        add(i, 1);
    }

    for (int i = 0; i < n; i++)
    {
        int p;
        cin >> p;
        
        int l = 1, r = n;
        while (l < r)
        {
            //cout << l << " " << r << endl;
            int m = (l + r) / 2;
            if (sum(m) < p)
            {
                l = m + 1;
            }
            else
            {
                r = m;
            }
        }
        add(l, -1);
        cout << arr[l] << " ";
    }
    cout << endl;
}

//2 6 1 4 2
//1 1 1 1 1