#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

double roundPlaces(double num, int places)
{
    return round(num*pow(10,places))/pow(10,places);
}

int main()
{
    int t;
    cin >> t;
    //cout << fixed;
    //cout << std::setprecision(3);
    //cout << 1.0005d << endl;

    for (int z = 0; z < t; z++)
    {
        double curx, cury, h;
        int n;
        cin >> curx >> cury >> h >> n;

        for (int i = 0; i < n; i++)
        {
            //cout << i << " " << cury << " " << curx << endl;
            cury += h * sin(curx) / curx;
            curx += h;
        }
        cout << roundPlaces(cury, 3) << endl;
    }
}
