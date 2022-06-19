#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int z = 0; z < t; z++)
    {
        int n, m;
        cin >> n >> m;

        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            sum += a;
        }

        cout << max(0, sum - m) << endl;
    }
}
