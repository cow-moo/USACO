#include <iostream>
#include <numeric>
using namespace std;

long long a, b;

long long checkx(long long x)
{
    return ((a * (x + 1) / b) + 1) / 2 + (x + 1) / 2;
}

long long checky(long long y)
{
    return (b * y / a) / 2 + (y + 1) / 2;
}

int main()
{
    long long n;
    cin >> a >> b >> n;
    long long l = 0, r = 3 * n + 5;

    while (l < r)
    {
        long long m = (l + r) / 2;
        if (checkx(m) < n + 1)
            l = m + 1;
        else
            r = m;
    }
    l += !(l % 2);
    //cout << l << " " << check(l) << endl;
    if (checkx(l) == n + 1)
    {
        long long num = a * (l + 1);
        long long floor = num / b;
        if (floor % 2 == 0)
        {
            num = num % b;
        }
        else
        {
            num = b - (num % b);
        }
        if ((floor / 2) % 2 == 1)
            num *= -1;
        //cout << num << endl;
        if (num == 0)
            b = 1;
        else
        {
            long long div = gcd(num, b);
            num /= div;
            b /= div;
        }
        cout << ((l / 2) % 2 ? -1 : 1) << " 1 " << num << " " << b << endl;
    }
    else
    {
        l = 0, r = 3 * n + 5;
        while (l < r)
        {
            long long m = (l + r) / 2;
            //cout << m << " " << checky(m) << endl;
            if (checky(m) < n + 1)
                l = m + 1;
            else
                r = m;
        }
        //l = a * (l + 1) / b;
        //l -= !(l % 2);
        long long num = b * l - a;
        long long floor = num / a;
        //cout << num << "/" << a << " " << l << endl;
        if (floor % 2 == 0)
        {
            num = num % a;
        }
        else
        {
            num = a - (num % a);
        }
        if ((floor / 2) % 2 == 1)
            num *= -1;
        //cout << num << endl;
        if (num == 0)
            a = 1;
        else
        {
            long long div = gcd(num, a);
            num /= div;
            a /= div;
        }
        cout << num << " " << a << " " << ((l / 2) % 2 ? -1 : 1) << " 1" << endl;
    }
}

//6 7 1 1