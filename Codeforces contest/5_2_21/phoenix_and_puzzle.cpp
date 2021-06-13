#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int z = 0; z < t; z++)
    {
        int n;
        cin >> n;

        int halfRoot = sqrt(n / 2);
        int quarterRoot = sqrt(n / 4);

        if (n == 2 * halfRoot * halfRoot || n == 2 * (halfRoot + 1) * (halfRoot + 1) || n == 4 * quarterRoot * quarterRoot || n == 4 * (quarterRoot + 1) * (quarterRoot + 1))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}
