#include <iostream>
using namespace std;

int last3[3][3] = {{1, 0, 1}, {1, 1, 0}, {0, 1, 1}};

int main()
{
    int t;
    cin >> t;

    for (int z = 0; z < t; z++)
    {
        int n;
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (n % 2 == 1 && i >= n - 3)
                {
                    if (j >= n - 3)
                    {
                        cout << last3[i - (n - 3)][j - (n - 3)] << " ";
                    }
                    else
                    {
                        cout << "0 ";
                    }
                }
                else
                {
                    if (i / 2 == j / 2)
                    {
                        cout << "1 ";
                    }
                    else
                    {
                        cout << "0 ";
                    }
                }
            }
            cout << endl;
        }
    }
}
