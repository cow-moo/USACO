#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int z = 0; z < t; z++)
    {
        int n;
        cin >> n;
        string num;
        cin >> num;

        if (n % 2 == 0)
        {
            bool containsEven = false;
            for (int i = 1; i < n; i += 2)
            {
                if ((num[i] - '0') % 2 == 0)
                {
                    containsEven = true;
                    break;
                }
            }
            cout << (containsEven ? 2 : 1) << endl;
        }
        else
        {
            bool containsOdd = false;
            for (int i = 0; i < n; i += 2)
            {
                if ((num[i] - '0') % 2 == 1)
                {
                    containsOdd = true;
                    break;
                }
            }
            cout << (containsOdd ? 1 : 2) << endl;
        }
    }
}
