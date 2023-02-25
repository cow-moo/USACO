#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int z = 1; z <= t; z++)
    {
        int n;
        cin >> n;
        cout << "Case #" << z << ": " << (n - 1) / 5 + 1 << endl;
    }
}
