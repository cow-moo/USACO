#include <iostream>
using namespace std;

int arr[2000];

int main()
{
    int t;
    cin >> t;

    for (int z = 0; z < t ; z++)
    {
        int n;
        cin >> n;

        int a, b;
        cin >> a;
        b = a;
        for (int i = 1; i < n; i++)
        {
            int inp;
            cin >> inp;
            a &= inp;
            b |= inp;
        }
        cout << b - a << endl;
    }
}
