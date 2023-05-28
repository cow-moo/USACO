#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

long long check(long long r2)
{
    long long cnt = 0;
    long long i = sqrt(r2), j = 0;
    for (; 2 * i * i > r2; i--)
    {
        long long temp = sqrt(r2 - i * i);
        cnt += (temp - j) * i;
        j = temp;
        //cout << i << " " << j << endl;
    }
    cnt += i * (i - j);
    return 4 * (2 * cnt - i * i);
}

int main()
{
    //cout << check(1000000000) << endl;
    long long s;
    cin >> s;

    long long l = 0, r = 1000000000;
    while (l < r)
    {
        long long m = (l + r) / 2;
        //cout << m << endl;
        if (check(m) > s)
            r = m;
        else
            l = m + 1;
    }
    cout << fixed << setprecision(10) << sqrt(l) << endl;
}