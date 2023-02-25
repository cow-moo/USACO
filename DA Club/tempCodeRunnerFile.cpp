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
    string res = "";
    for (int i = 0; i < digits; i++)
    {
        res += '0' + minim;
    }
    n -= digits * costs[minim];
    //cout << n << endl;
    for (int i = 0; i < digits; i++)
    {
        for (int j = 9; j > minim; j--)
        {
            if (costs[j] - costs[minim] <= n)
            {
                n -= costs[j] - costs[minim];
                res[i] = '0' + j;
            }
        }
    }
    cout << res << endl;
}