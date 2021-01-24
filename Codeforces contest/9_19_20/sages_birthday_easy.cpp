#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int inp;
        cin >> inp;
    }

    cout << (n - 1) / 2 << endl;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            cout << n / 2 + i / 2 + 1 << " ";
        }
        else
        {
            cout << (i / 2) + 1 << " ";
        }
    }
}
