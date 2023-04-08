#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    long long xp, yp, x1, y1, xi, yi, ans = 0;
    cin >> x1 >> y1;
    xp = x1, yp = y1;
    for (int i = 1; i < n; i++)
    {
        cin >> xi >> yi;
        ans += yi * xp - xi * yp;
        xp = xi, yp = yi;
    }
    ans += y1 * xi - x1 * yi;
    cout << abs(ans) << endl;
}