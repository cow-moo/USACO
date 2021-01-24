#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int z = 1; z <= t; z++)
    {
        int s, k, n;
        cin >> n >> k >> s;

//        (k - 1) + 1 + n
//        (k - 1) + k - s + (n - s + 1)
//        2 * k + n - 2 * s
//        2 * (k - s) + n
        cout << "Case #" << z << ": " << min(k + n, 2 * (k - s) + n) << endl;
    }
}
