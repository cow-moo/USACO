#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int z = 0; z < t; z++)
    {
        int n, x;
        cin >> n >> x;

        int sum = 0;
        bool allEqual = true;
        bool oneEqual = false;
        for (int i = 0; i < n; i++)
        {
            int rating;
            cin >> rating;

            if (rating != x)
                allEqual = false;
            else
                oneEqual = true;
            sum += rating;
        }

        if (allEqual)
        {
            cout << 0 << endl;
        }
        else if (oneEqual || sum == n * x)
        {
            cout << 1 << endl;
        }
        else
        {
            cout << 2 << endl;
        }
    }
}
