#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    double a, b, c, d, m, t;
    cin >> a >> b >> c >> d >> m >> t;
    d -= t / m;

    double d0 = b * b - 3 * a * c;
    double d1 = 2 * b * b * b - 9 * a * b * c + 27 * a * a * d;
    double C = pow((d1 + sqrt(d1 * d1 - 4 * d0 * d0 * d0)) / 2, 1.0 / 3);
    double x = -1.0 / 3 / a * (b + C + d0 / C);
    cout << x << endl;
}
