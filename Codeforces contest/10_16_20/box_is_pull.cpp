#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int z = 0; z < t; z++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        cout << (abs(x2 - x1) + abs(y2 - y1) + ((x1 != x2 && y1 != y2) ? 2 : 0)) << endl;
    }
}
