#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <iomanip>
using namespace std;

float solve(double t, double d)
{
    return t - sqrt(t * t - 4 * d);
}

int main()
{
    cout << fixed << setprecision(2);

    int n;
    cin >> n;

    for (int z = 0; z < n; z++)
    {
        int s, x0, y0;
        cin >> s >> x0 >> y0;
        float total = 0;
        for (int i = 0; i < s; i++)
        {
            int x, y;
            float t;
            cin >> x >> y >> t;
            int xDiff = abs(x - x0);
            int yDiff = abs(y - y0);

            total += solve(t, xDiff) + solve(t, yDiff);


            x0 = x;
            y0 = y;
        }

        cout << total << endl;
    }
}
