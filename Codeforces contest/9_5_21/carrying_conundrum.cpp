#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int z = 0; z < t; z++)
    {
        long long n;
        cin >> n;

        long long a = 0, b = 0, cur = 1;
        while (n > 0)
        {
            a += cur * (n % 10);
            n /= 10;
            b += cur * (n % 10);
            n /= 10;

            //cout << n << endl;
            cur *= 10;
        }
        //cout << a << " " << b << endl;
        cout << (a + 1) * (b + 1) - 2 << endl;
    }
}
