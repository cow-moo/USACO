#include <iostream>
using namespace std;

int costs[15];

int main()
{
    int n;
    cin >> n;

    int minim = 1;
    for (int i = 1; i <= 9; i++)
    {
        cin >> costs[i];
        if (costs[i] <= costs[minim])
        {
            minim = i;
        }
    }

    int digits = n / costs[minim];
    n -= digits * costs[minim];
    for (int i = 0; i < digits; i++)
    {
        for (int j = 9; j >= minim; j--)
        {
            if (costs[j] - costs[minim] <= n)
            {
                n -= costs[j] - costs[minim];
                cout << j;
                break;
            }
        }
    }
    cout << endl;
}